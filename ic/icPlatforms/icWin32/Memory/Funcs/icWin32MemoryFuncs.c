
#ifndef IC_WIN32_MEMORY_FUNCS
#define IC_WIN32_MEMORY_FUNCS

#include"./icWin32MemoryFuncs.h"

ic_info("globals")
    ic_hide               HANDLE g_icWin32Heap       = NULL; //Process Heap
    ic_hide ic_thread_own HANDLE g_icWin32ThreadHeap = NULL; //Thread Heap

ic_info("definitions")
    ic_win32_dcl BOOL ic_call icWin32EnableGlobalHeap(HANDLE* phGlobalHeap, BOOL bEnable, DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize) ic_noexc {
        HANDLE hTh = *phGlobalHeap;
        if (bEnable) {
            ic_if_do(!hTh, *phGlobalHeap = hTh = HeapCreate(flOptions, dwInitialSize, dwMaximumSize));
            return hTh != NULL;
        } else {
            ic_if_do_x2(hTh, ic_if_return(!HeapDestroy(hTh), FALSE), *phGlobalHeap = NULL);
            return TRUE;
        }
    }

    ic_win32_dcl BOOL ic_call icWin32EnableProcessHeap(BOOL bEnable) ic_noexc {
        return icWin32EnableGlobalHeap(&g_icWin32Heap, bEnable, 0, 0, 0);
    }

    ic_win32_dcl BOOL ic_call icWin32EnableThreadHeap(BOOL bEnable) ic_noexc {
        return icWin32EnableGlobalHeap(&g_icWin32ThreadHeap, bEnable, 0, 0, 0);
    }

    ic_win32_dcl void_p ic_call icWin32Alloc(size_t btSz) ic_noexc {
        return HeapAlloc(g_icWin32Heap, 0, btSz);
    }

    ic_win32_dcl void ic_call icWin32Dealloc(void_p pMem) ic_noexc {
        HeapFree(g_icWin32Heap, 0, pMem);
    }

    ic_win32_dcl void_p ic_call icWin32Realloc(void_p pMem, size_t btSz) ic_noexc {
        return HeapReAlloc(g_icWin32Heap, 0, pMem, btSz);
    }

    ic_win32_dcl void_p ic_call icWin32ThreadAlloc(size_t btSz) ic_noexc {
        return HeapAlloc(g_icWin32ThreadHeap, 0, btSz);
    }

    ic_win32_dcl void ic_call icWin32ThreadDealloc(void_p pMem) ic_noexc {
        HeapFree(g_icWin32ThreadHeap, 0, pMem);
    }

    ic_win32_dcl void_p ic_call icWin32ThreadRealloc(void_p pMem, size_t btSz) ic_noexc {
        return HeapReAlloc(g_icWin32ThreadHeap, 0, pMem, btSz);
    }

#endif