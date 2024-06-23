
#pragma once

#include"./icCoreMemoryFuncs.h"

ic_info("inline decs: Alloc")
    ic_inl ptrdiff_t ic_call icGetAllocCount() ic_noexc {
        return *icGetAllocCountPtr();
    }

    ic_inl void_p ic_call icPosixAllocInl(size_t btSz) ic_noexc {
    #ifdef IC_DEBUG
        return icCountedPosixAlloc(btSz); //调试模式会使用计数内存分配。
    #else
        return malloc(btSz);
    #endif
    }

    ic_inl void   ic_call icPosixDeallocInl(void_p pMem) ic_noexc {
    #ifdef IC_DEBUG
        icCountedPosixDealloc(pMem); //调试模式会使用计数内存释放。
    #else
        free(pMem);
    #endif
    }

    ic_inl void_p ic_call icPosixReallocInl(void_p pMem, size_t btSz) ic_noexc {
    #ifdef IC_DEBUG
        return icCountedPosixRealloc(pMem, btSz);
    #else
        return realloc(pMem, btSz);
    #endif
    }

ic_info("Copy Move Memory")
    ic_inl void ic_call icClearMem(void_p bg, void_p ed) ic_noexc {
        icClearMemSize(bg, icPtrDiffU(bg, ed));
    }

    ic_inl void ic_call icClearMemSize(void_p dst, size_t btSz) ic_noexc {
        memset(dst, 0, btSz);
    }

    ic_inl void ic_call icCopyMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        icCopyMemSizeNoRet(dst, bg, icPtrDiffU(bg, ed));
    }

    ic_inl void ic_call icMoveMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        icMoveMemSizeNoRet(dst, bg, icPtrDiffU(bg, ed));
    }

    ic_inl void  ic_call icCopyMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        memcpy(dst, bg, btSz);
    }

    ic_inl void  ic_call icMoveMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        memmove(dst, bg, btSz);
    }

    ic_inl void_p ic_call icCopyMem(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        return icCopyMemSize(dst, bg, icPtrDiffU(bg, ed));
    }

    ic_inl void_p ic_call icMoveMem(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        return icMoveMemSize(dst, bg, icPtrDiffU(bg, ed));
    }

    ic_inl void_p ic_call icCopyMemSize(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        icCopyMemSizeNoRet(dst, bg, btSz);
        return icAddPtr(dst, btSz);
    }

    ic_inl void_p ic_call icMoveMemSize(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        icMoveMemSizeNoRet(dst, bg, btSz);
        return icAddPtr(dst, btSz);
    }

    ic_inl bool ic_call icEqualMem(cvoid_p bg1, cvoid_p bg2, size_t btSz) ic_noexc {
        return memcmp(bg1, bg2, btSz) == 0;
    }

    ic_inl bool ic_call icSameMem(cvoid_p bg1, cvoid_p ed1, cvoid_p bg2, cvoid_p ed2) ic_noexc {
        return icSameMemSize(
            bg1, icPtrDiffU(bg1, ed1), 
            bg2, icPtrDiffU(bg2, ed2)
        );
    }

    ic_inl bool ic_call icSameMemSize(cvoid_p bg1, size_t btSz1, cvoid_p bg2, size_t btSz2) ic_noexc {
        ic_if_else_return(btSz1 != btSz2, false, icEqualMem(bg1, bg2, btSz1));
    }

    ic_inl bool ic_call icMemStartsWithSize(cvoid_p pMemBg, size_t memBtSz, cvoid_p pWithBg, size_t withBtSz) ic_noexc {
        ic_if_return(memBtSz < withBtSz, false);
        return icEqualMem(pMemBg, pWithBg, withBtSz);
    }

    ic_inl bool ic_call icMemStartsWith(cvoid_p pMemBg, cvoid_p pMemEd, cvoid_p pWithBg, cvoid_p pWithEd) ic_noexc {
        return icMemStartsWithSize(
            pMemBg,  icPtrDiffU(pMemBg, pMemEd),
            pWithBg, icPtrDiffU(pWithBg, pWithEd));
    }

    ic_inl void_p ic_call icInsertMem(void_p pos, void_p edOfData, void_p edOfCap, cvoid_p bg, cvoid_p ed, void_p* pNewMemEd) ic_noexc {
        return icInsertMemSize(pos, edOfData, edOfCap, bg, icPtrDiffU(bg, ed), pNewMemEd);
    }