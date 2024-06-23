
#pragma once

#include"../../../icCore/Memory/icCoreMemory.h"
#include"../../Common/icCommon.h"

ic_info("Mem")
    ic_dcl void_p ic_call icAlloc(size_t btSz) ic_noexc;
    ic_dcl void   ic_call icDealloc(void_p pMem) ic_noexc;
    ic_dcl void_p ic_call icRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_dcl void_p ic_call icCountedAlloc(size_t btSz) ic_noexc;
    ic_dcl void   ic_call icCountedDealloc(void_p pMem) ic_noexc;
    ic_dcl void_p ic_call icCountedRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_dcl volatile ptrdiff_t* ic_call icGetThreadAllocCountPtr() ic_noexc;
    ic_dcl void_p ic_call icThreadAlloc(size_t btSz) ic_noexc;
    ic_dcl void   ic_call icThreadDealloc(void_p pMem) ic_noexc;
    ic_dcl void_p ic_call icThreadRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_dcl void_p ic_call icCountedThreadAlloc(size_t btSz) ic_noexc;
    ic_dcl void   ic_call icCountedThreadDealloc(void_p pMem) ic_noexc;
    ic_dcl void_p ic_call icCountedThreadRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_inl ptrdiff_t ic_call icGetThreadAllocCount() ic_noexc;

ic_info("inl")
    ic_inl ptrdiff_t ic_call icGetThreadAllocCount() ic_noexc {
        return *icGetThreadAllocCountPtr();
    }