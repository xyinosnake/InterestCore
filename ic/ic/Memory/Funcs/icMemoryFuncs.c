
#ifndef IC_MEMORY_FUNCS
#define IC_MEMORY_FUNCS

#include"./icMemoryFuncs.h"
#include"../../Platforms/icPlatforms.h"

ic_info("Mem")
    ic_dcl void_p ic_call icAlloc(size_t btSz) ic_noexc {
    #if defined(IC_DEBUG)
        return icCountedAlloc(btSz);
    #elif defined(IC_OS_WINDOWS)
        return icWin32Alloc(btSz);
    #else
        return malloc(btSz);
    #endif
    }

    ic_dcl void ic_call icDealloc(void_p pMem) ic_noexc {
    #if defined(IC_DEBUG)
        icCountedDealloc(pMem);
    #elif defined(IC_OS_WINDOWS)
        icWin32Dealloc(pMem);
    #else
        free(pMem);
    #endif
    }

    ic_dcl void_p ic_call icRealloc(void_p pMem, size_t btSz) ic_noexc {
    #if defined(IC_DEBUG)
        return icCountedRealloc(pMem, btSz);
    #elif defined(IC_OS_WINDOWS)
        return icWin32Realloc(pMem, btSz);
    #else
        return realloc(pMem, btSz);
    #endif
    }

    ic_dcl void_p ic_call icCountedAlloc(size_t btSz) ic_noexc {
        void_p p =
    #if defined(IC_OS_WINDOWS)
        icWin32Alloc(btSz);
    #else
        malloc(btSz);
    #endif
        ic_if_do(p, icLockedInc(icGetAllocCountPtr()));
        return p;
    }

    ic_dcl void ic_call icCountedDealloc(void_p pMem) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        icWin32Dealloc(pMem);
    #else
        free(pMem);
    #endif
        icLockedDec(icGetAllocCountPtr());
    }

    ic_dcl void_p ic_call icCountedRealloc(void_p pMem, size_t btSz) ic_noexc {
        void_p p =
    #if defined(IC_OS_WINDOWS)
        icWin32Realloc(pMem, btSz);
    #else
        realloc(pMem, btSz);
    #endif
        ic_if_do((!pMem) && p, icLockedInc(icGetAllocCountPtr()));
        return p;
    }

    ic_dcl void_p ic_call icThreadAlloc(size_t btSz) ic_noexc {
    #if defined(IC_DEBUG)
        return icCountedThreadAlloc(btSz);
    #elif defined(IC_OS_WINDOWS)
        return icWin32ThreadAlloc(btSz);
    #else
        return malloc(btSz);
    #endif
    }

    ic_dcl void ic_call icThreadDealloc(void_p pMem) ic_noexc {
    #if defined(IC_DEBUG)
        icCountedThreadDealloc(pMem);
    #elif defined(IC_OS_WINDOWS)
        icWin32ThreadDealloc(pMem);
    #else
        free(pMem);
    #endif
    }

    ic_dcl void_p ic_call icThreadRealloc(void_p pMem, size_t btSz) ic_noexc {
    #if defined(IC_DEBUG)
        return icCountedThreadRealloc(pMem, btSz);
    #elif defined(IC_OS_WINDOWS)
        return icWin32ThreadRealloc(pMem, btSz);
    #else
        return realloc(pMem, btSz);
    #endif
    }

    ic_hide ic_thread_own ptrdiff_t g_icThreadAllocCount = 0;
    ic_dcl volatile ptrdiff_t* ic_call icGetThreadAllocCountPtr() ic_noexc {
        return &g_icThreadAllocCount;
    }

    ic_dcl void_p ic_call icCountedThreadAlloc(size_t btSz) ic_noexc {
        void_p p =
    #if defined(IC_OS_WINDOWS)
        icWin32ThreadAlloc(btSz);
    #else
        malloc(btSz);
    #endif
        ic_if_do(p, ++g_icThreadAllocCount);
        return p;
    }

    ic_dcl void ic_call icCountedThreadDealloc(void_p pMem) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        icWin32ThreadDealloc(pMem);
    #else
        free(pMem);
    #endif
        --g_icThreadAllocCount;
    }

    ic_dcl void_p ic_call icCountedThreadRealloc(void_p pMem, size_t btSz) ic_noexc {
        void_p p =
    #if defined(IC_OS_WINDOWS)
        icWin32ThreadRealloc(pMem, btSz);
    #else
        realloc(pMem, btSz);
    #endif
        ic_if_do((!pMem) && p, ++g_icThreadAllocCount);
        return p;
    }
#endif