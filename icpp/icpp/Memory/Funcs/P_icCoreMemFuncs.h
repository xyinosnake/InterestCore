
#pragma once

#include"./icppMemoryFuncs.h"

ic_info("icCore in ns inlines definitions") icpp_ns_x1(icpp)
    icpp_t1(struct_xt) ic_inl void ic_call clearStruct(struct_xt& refStruct) ic_noexc {
        icClearMemSize(&refStruct, sizeof(struct_xt));
    }

    ic_inl void ic_call clearMem(void_p bg, void_p ed) ic_noexc {
        icClearMem(bg, ed);
    }

    ic_inl void ic_call clearMemSize(void_p dst, size_t btSz) ic_noexc {
        icClearMemSize(dst, btSz);
    }

    ic_inl void ic_call copyMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        icCopyMemNoRet(dst, bg, ed);
    }

    ic_inl void ic_call moveMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        icMoveMemNoRet(dst, bg, ed);
    }

    ic_inl void ic_call copyMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        icCopyMemSizeNoRet(dst, bg, btSz);
    }

    ic_inl void ic_call moveMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc {
        icMoveMemSizeNoRet(dst, bg, btSz);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call copyMem(type_xp dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        return (type_xp)icCopyMem(dst, bg, ed);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call moveMem(type_xp dst, cvoid_p bg, cvoid_p ed) ic_noexc {
        return (type_xp)icMoveMem(dst, bg, ed);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call copyMemSize(type_xp dst, cvoid_p bg, size_t btSz) ic_noexc {
        return (type_xp)icCopyMemSize(dst, bg, btSz);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call moveMemSize(type_xp dst, cvoid_p bg, size_t btSz) ic_noexc {
        return (type_xp)icMoveMemSize(dst, bg, btSz);
    }

    ic_inl bool ic_call equalMem(cvoid_p bg1, cvoid_p bg2, size_t btSz) ic_noexc {
        return icEqualMem(bg1, bg2, btSz);
    }

    ic_inl bool ic_call sameMem(cvoid_p bg1, cvoid_p ed1, cvoid_p bg2, cvoid_p ed2) ic_noexc {
        return icSameMem(bg1, ed1, bg2, ed2);
    }

    ic_inl bool ic_call sameMemSize(cvoid_p bg1, size_t btSz1, cvoid_p bg2, size_t btSz2) ic_noexc {
        return icSameMemSize(bg1, btSz1, bg2, btSz2);
    }

    ic_inl bool ic_call memStartsWithSize(cvoid_p pMemBg, size_t memBtSz, cvoid_p pWithBg, size_t withBtSz) ic_noexc {
        return icMemStartsWithSize(pMemBg, memBtSz, pWithBg, withBtSz);
    }

    ic_inl bool ic_call memStartsWith(cvoid_p pMemBg, cvoid_p pMemEd, cvoid_p pWithBg, cvoid_p pWithEd) ic_noexc {
        return icMemStartsWith(pMemBg, pMemEd, pWithBg, pWithEd);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call insertMem(type_xp pos, type_xp edOfData, type_xp edOfCap, cvoid_p bg, cvoid_p ed, type_xp* pNewMemEd) ic_noexc {
        return (type_xp)icInsertMem(pos, edOfData, edOfCap, bg, ed, pNewMemEd);
    }

    icpp_t1(type_xp) ic_inl type_xp ic_call insertMemSize(type_xp pos, type_xp edOfData, type_xp edOfCap, cvoid_p bg, size_t btSz, type_xp* pNewMemEd) ic_noexc {
        return (type_xp)icInsertMemSize(pos, edOfData, edOfCap, bg, btSz, pNewMemEd);
    }

    ic_inl void_p ic_call posixAllocInl(size_t btSz) ic_noexc {
        return icPosixAllocInl(btSz);
    }

    ic_inl void ic_call posixDeallocInl(void_p pMem) ic_noexc {
        return icPosixDeallocInl(pMem);
    }

    ic_inl void_p ic_call posixReallocInl(void_p pMem, size_t btSz) ic_noexc {
        return icPosixReallocInl(pMem, btSz);
    }

    ic_inl void_p ic_call posixAlloc(size_t btSz) ic_noexc {
        return icPosixAlloc(btSz);
    }

    ic_inl void ic_call posixDealloc(void_p pMem) ic_noexc {
        return icPosixDealloc(pMem);
    }

    ic_inl void_p ic_call posixRealloc(void_p pMem, size_t btSz) ic_noexc {
        return icPosixRealloc(pMem, btSz);
    }

    ic_inl void_p ic_call countedPosixAlloc(size_t btSz) ic_noexc {
        return icCountedPosixAlloc(btSz);
    }

    ic_inl void ic_call countedPosixDealloc(void_p pMem) ic_noexc {
        return icCountedPosixDealloc(pMem);
    }

    ic_inl void_p ic_call countedPosixRealloc(void_p pMem, size_t btSz) ic_noexc {
        return icCountedPosixRealloc(pMem, btSz);
    }

    ic_inl ptrdiff_t ic_call getAllocCount() ic_noexc {
        return icGetAllocCount();
    }
icpp_end_ns_x1