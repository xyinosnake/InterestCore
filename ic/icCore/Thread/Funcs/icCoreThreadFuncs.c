#ifndef IC_CORE_THREAD_FUNCS
#define IC_CORE_THREAD_FUNCS

#include"./icCoreThreadFuncs.h"
#include"../../Memory/Funcs/icCoreMemoryFuncs.h"

#ifdef IC_OS_WINDOWS
    #include<process.h>
#endif

ic_info("Thread")
    ic_core_dcl ic_thread_h ic_call icCreateThread(ic_thread_f fThread, size_t uStackSize, void* pParameter) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return (ic_thread_h)_beginthreadex(NULL, (uint32_t)uStackSize, (_beginthreadex_proc_type)fThread, pParameter, 0, NULL);
    #elif defined(IC_OS_UNIX_LIKE)
        pthread_t      thread;
        pthread_attr_t thread_attr;
        pthread_attr_init(&thread_attr);
        pthread_attr_setstacksize(&thread_attr, uStackSize); //设置为0，将会使用系统默认的线程堆栈大小（ChatGPT3.5）。
        int i = pthread_create(&thread, &thread_attr, (ic_pthread_f)fThread, pParameter);
        pthread_attr_destroy(&thread_attr);
        return i ? NULL : (ic_thread_h)thread;
    #else
        return NULL;
    #endif
    }

    ic_core_dcl bool ic_call icJoinThread(ic_thread_h hThread, ic_thr_t* pRtnVal) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        WaitForSingleObject((HANDLE)hThread, INFINITE);
        DWORD dwExitCode;
        GetExitCodeThread((HANDLE)hThread, &dwExitCode);
        CloseHandle((HANDLE)hThread);
        ic_if_do(pRtnVal, *pRtnVal = (ic_thr_t)dwExitCode);
        return true;
    #elif defined(IC_OS_UNIX_LIKE)
        return pthread_join((pthread_t)hThread, (void**)pRtnVal) == 0;
    #else
        return false;
    #endif
    }

ic_info("Process Mutex")
    ic_core_dcl ic_process_mutex_h ic_call icCreateProcessMutex() ic_noexc {
    #if defined(IC_OS_WINDOWS)
        SECURITY_ATTRIBUTES securityAttr; // 创建安全描述符
        securityAttr.nLength              = sizeof(SECURITY_ATTRIBUTES);
        securityAttr.lpSecurityDescriptor = NULL;
        securityAttr.bInheritHandle       = TRUE;  // 允许继承句柄
        return (ic_process_mutex_h)CreateMutexA(&securityAttr, FALSE, NULL);
    #elif defined(IC_OS_UNIX_LIKE)
        pthread_mutex_t* pMutex = (pthread_mutex_t*)icPosixAlloc(sizeof(pthread_mutex_t));
        ic_if_return(!pMutex, NULL);
        int i;
        pthread_mutexattr_t attr;
        i = pthread_mutexattr_init(&attr);
        ic_if_goto(i, ErrMem);
        i = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
        ic_if_goto(i, ErrAttr);
        i = pthread_mutex_init(pMutex, NULL);
        ic_if_goto(i, ErrAttr);
        pthread_mutexattr_destroy(&attr);
        return (ic_process_mutex_h)pMutex;
    ErrAttr:
        pthread_mutexattr_destroy(&attr);
    ErrMem:
        icPosixDealloc(pMutex);
        return NULL;
    #else
        return NULL;
    #endif
    }

    ic_core_dcl bool ic_call icLockProcessMutex(ic_process_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        DWORD result = WaitForSingleObject((HANDLE)hMutex, INFINITE); // 请求Mutex的所有权
        return result == WAIT_OBJECT_0;
    #elif defined(IC_OS_UNIX_LIKE)
        return pthread_mutex_lock((pthread_mutex_t*)hMutex) == 0;
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icUnlockProcessMutex(ic_process_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return ReleaseMutex((HANDLE)hMutex) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        return pthread_mutex_unlock((pthread_mutex_t*)hMutex) == 0;
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icDestroyProcessMutex(ic_process_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return CloseHandle((HANDLE)hMutex) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        int i = pthread_mutex_destroy((pthread_mutex_t*)hMutex);
        ic_if_return(i, false);
        icDealloc(hMutex);
        return true;
    #else
        return false;
    #endif
    }

ic_info("Thread Mutex")
    ic_core_dcl ic_thread_mutex_h ic_call icCreateThreadMutex(size_t spinCount) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        CRITICAL_SECTION* pCriticalSection = (CRITICAL_SECTION*)icPosixAlloc(sizeof(CRITICAL_SECTION));
        ic_if_return(!pCriticalSection, NULL);
        BOOL b = InitializeCriticalSectionAndSpinCount(pCriticalSection, (DWORD)spinCount);
        ic_if_do_and_return(!b, icPosixDealloc(pCriticalSection), NULL);
        return (ic_thread_mutex_h)pCriticalSection;
    #elif defined(IC_OS_UNIX_LIKE)
        pthread_mutex_t* pMutex = (pthread_mutex_t*)icAlloc(sizeof(pthread_mutex_t));
        ic_if_return(!pMutex, NULL);
        int i = pthread_mutex_init(pMutex, NULL);
        ic_if_do_and_return(i, icDealloc(pMutex), NULL);
        return (ic_thread_mutex_h)pMutex;
    #else
        return NULL;
    #endif
    }

    ic_core_dcl bool ic_call icLockThreadMutex(ic_thread_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        EnterCriticalSection((CRITICAL_SECTION*)hMutex);
        return true;
    #elif defined(IC_OS_UNIX_LIKE)
        return icLockProcessMutex((ic_process_mutex_h)hMutex);
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icUnlockThreadMutex(ic_thread_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        LeaveCriticalSection((CRITICAL_SECTION*)hMutex);
        return true;
    #elif defined(IC_OS_UNIX_LIKE)
        return icUnlockProcessMutex((ic_process_mutex_h)hMutex);
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icDestroyThreadMutex(ic_thread_mutex_h hMutex) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        DeleteCriticalSection((CRITICAL_SECTION*)hMutex);
        icPosixDealloc((CRITICAL_SECTION*)hMutex);
        return true;
    #elif defined(IC_OS_UNIX_LIKE)
        return icDestroyProcessMutex((ic_process_mutex_h)hMutex);
    #else
        return false;
    #endif
    }
#endif