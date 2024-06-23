
#pragma once

#include"./icCoreMemoryFuncs.h"

ic_info("defs")
    ic_core_dcl void_p ic_call icInsertMemSize(void_p pos, void_p edOfData, void_p edOfCap, cvoid_p bg, size_t btSz, void** pNewMemEd) ic_noexc {
        ic_if_return((icPtrDiffU(edOfData, edOfCap)) < btSz, NULL);
        void_p movePos  = icAddPtr(pos, (ptrdiff_t)btSz);
        void_p newMemEd = icMoveMem(movePos, pos, edOfData);
        icCopyMemSizeNoRet(pos, bg, btSz);
        ic_if_do(pNewMemEd, *pNewMemEd = newMemEd);
        return movePos;
    }

ic_info("decs: Alloc")
    ic_hide volatile ptrdiff_t g_icAllocCount = 0;
    ic_core_dcl volatile ptrdiff_t* ic_call icGetAllocCountPtr() ic_noexc {
        return &g_icAllocCount;
    }

    ic_core_dcl void_p ic_call icCountedPosixAlloc(size_t btSz) ic_noexc {
        void_p p = malloc(btSz);
        ic_if_do(p, icLockedInc(&g_icAllocCount));
        return p;
    }

    ic_core_dcl void ic_call icCountedPosixDealloc(void_p pMem) ic_noexc {
        icLockedDec(&g_icAllocCount);
        free(pMem);
    }

    ic_core_dcl void_p ic_call icCountedPosixRealloc(void_p pMem, size_t btSz) ic_noexc {
        void_p p = realloc(pMem, btSz);
        ic_if_do((!pMem) && p, icLockedInc(&g_icAllocCount));
        return p;
    }

    ic_core_dcl void_p ic_call icPosixAlloc(size_t btSz) ic_noexc {
    #ifdef IC_DEBUG
        return icCountedPosixAlloc(btSz); //调试模式会使用计数内存分配。
    #else
        return malloc(btSz);
    #endif
    }

    ic_core_dcl void ic_call icPosixDealloc(void_p pMem) ic_noexc {
    #ifdef IC_DEBUG
        icCountedPosixDealloc(pMem); //调试模式会使用计数内存释放。
    #else
        free(pMem);
    #endif
    }

    ic_core_dcl void_p ic_call icPosixRealloc(void_p pMem, size_t btSz) ic_noexc {
    #ifdef IC_DEBUG
        return icCountedPosixRealloc(pMem, btSz);
    #else
        return realloc(pMem, btSz);
    #endif
    }