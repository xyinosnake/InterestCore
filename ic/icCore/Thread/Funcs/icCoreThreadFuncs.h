
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("Thread")
    ic_core_dcl ic_thread_h ic_call icCreateThread(ic_thread_f fThread, size_t uStackSize ic_dfv(0), void* pParameter ic_dfv(NULL)) ic_noexc;
    ic_core_dcl bool ic_call icJoinThread(ic_thread_h hThread, ic_thr_t* pRtnVal ic_dfv(NULL)) ic_noexc;

ic_info("Process Mutex")
    ic_core_dcl ic_process_mutex_h ic_call icCreateProcessMutex() ic_noexc;
    ic_core_dcl bool ic_call icLockProcessMutex(ic_process_mutex_h hMutex) ic_noexc;
    ic_core_dcl bool ic_call icUnlockProcessMutex(ic_process_mutex_h hMutex) ic_noexc;
    ic_core_dcl bool ic_call icDestroyProcessMutex(ic_process_mutex_h hMutex) ic_noexc;

ic_info("Thread Mutex")
    ic_core_dcl ic_thread_mutex_h ic_call icCreateThreadMutex(size_t spinCount ic_dfv(0)) ic_noexc;
    ic_core_dcl bool ic_call icLockThreadMutex(ic_thread_mutex_h hMutex) ic_noexc;
    ic_core_dcl bool ic_call icUnlockThreadMutex(ic_thread_mutex_h hMutex) ic_noexc;
    ic_core_dcl bool ic_call icDestroyThreadMutex(ic_thread_mutex_h hMutex) ic_noexc;