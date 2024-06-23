
#pragma once

#include"../../Common/icppCommon.h"
#include"../../../../ic/ic/Memory/icMemory.h"

ic_info("in ns inlines declarations") icpp_ns_x1(icpp)
    ic_info("icCore")
        icpp_t1(struct_xt)
            ic_inl void ic_call clearStruct(struct_xt& refStruct) ic_noexc;
        ic_inl void ic_call clearMem(void_p bg, void_p ed) ic_noexc;
        ic_inl void ic_call clearMemSize(void_p dst, size_t btSz) ic_noexc;
        ic_inl void ic_call copyMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
        ic_inl void ic_call moveMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
        ic_inl void ic_call copyMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
        ic_inl void ic_call moveMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call copyMem(type_xp dst, cvoid_p bg, cvoid_p ed) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call moveMem(type_xp dst, cvoid_p bg, cvoid_p ed) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call copyMemSize(type_xp dst, cvoid_p bg, size_t btSz) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call moveMemSize(type_xp dst, cvoid_p bg, size_t btSz) ic_noexc;
        ic_inl bool ic_call equalMem(cvoid_p bg1, cvoid_p bg2, size_t btSz) ic_noexc;
        ic_inl bool ic_call sameMem(cvoid_p bg1, cvoid_p ed1, cvoid_p bg2, cvoid_p ed2) ic_noexc;
        ic_inl bool ic_call sameMemSize(cvoid_p bg1, size_t btSz1, cvoid_p bg2, size_t btSz2) ic_noexc;
        ic_inl bool ic_call memStartsWithSize(cvoid_p pMemBg, size_t memBtSz, cvoid_p pWithBg, size_t withBtSz) ic_noexc;
        ic_inl bool ic_call memStartsWith(cvoid_p pMemBg, cvoid_p pMemEd, cvoid_p pWithBg, cvoid_p pWithEd) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call insertMem(type_xp pos, type_xp edOfData, type_xp edOfCap, cvoid_p bg, cvoid_p ed, type_xp* pNewMemEd ic_dfv(ic_null)) ic_noexc;
        icpp_t1(type_xp)
            ic_inl type_xp ic_call insertMemSize(type_xp pos, type_xp edOfData, type_xp edOfCap, cvoid_p bg, size_t btSz, type_xp* pNewMemEd ic_dfv(ic_null)) ic_noexc;
        ic_inl void_p ic_call posixAllocInl(size_t btSz) ic_noexc;
        ic_inl void   ic_call posixDeallocInl(void_p pMem) ic_noexc;
        ic_inl void_p ic_call posixReallocInl(void_p pMem, size_t btSz) ic_noexc;
        ic_inl void_p ic_call posixAlloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call posixDealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call posixRealloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl void_p ic_call countedPosixAlloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call countedPosixDealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call countedPosixRealloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl ptrdiff_t ic_call getAllocCount() ic_noexc;

    ic_info("ic")
        ic_inl void_p ic_call alloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call dealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call realloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl void_p ic_call countedAlloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call countedDealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call countedRealloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl void_p ic_call threadAlloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call threadDealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call threadRealloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl void_p ic_call countedThreadAlloc(size_t btSz) ic_noexc;
        ic_inl void   ic_call countedThreadDealloc(void_p pMem) ic_noexc;
        ic_inl void_p ic_call countedThreadRealloc(void_p pMem, size_t btSz) ic_noexc;
        ic_inl ptrdiff_t ic_call getThreadAllocCount() ic_noexc;
icpp_end_ns_x1

#include"./P_icCoreMemFuncs.h"
#include"./P_icMemFuncs.h"
