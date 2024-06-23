
#pragma once

#include"../../Common/icWin32Common.h"

ic_info("declarations")
    ic_win32_dcl BOOL   ic_call icWin32EnableGlobalHeap(HANDLE* phGlobalHeap, BOOL bEnable, DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize) ic_noexc;
    ic_win32_dcl BOOL   ic_call icWin32EnableProcessHeap(BOOL bEnable) ic_noexc;
    ic_win32_dcl BOOL   ic_call icWin32EnableThreadHeap(BOOL bEnable) ic_noexc;
    ic_win32_dcl void_p ic_call icWin32Alloc(size_t btSz) ic_noexc;
    ic_win32_dcl void   ic_call icWin32Dealloc(void_p pMem) ic_noexc;
    ic_win32_dcl void_p ic_call icWin32Realloc(void_p pMem, size_t btSz) ic_noexc;
    ic_win32_dcl void_p ic_call icWin32ThreadAlloc(size_t btSz) ic_noexc;
    ic_win32_dcl void   ic_call icWin32ThreadDealloc(void_p pMem) ic_noexc;
    ic_win32_dcl void_p ic_call icWin32ThreadRealloc(void_p pMem, size_t btSz) ic_noexc;
ic_info("inl definitions")
    

