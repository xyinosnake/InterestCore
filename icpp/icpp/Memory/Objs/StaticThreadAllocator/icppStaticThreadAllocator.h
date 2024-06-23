
#pragma once

#include"./declarations.h"
#include"../../Funcs/icppMemoryFuncs.h"

ic_info("icppStaticThreadAllocator & icppStaticThreadAllocator2")
    ic_inl void_p ic_call icppStaticThreadAllocator::allocate(size_t btSz) ic_noexc {
        return icThreadAlloc(btSz);
    }

    ic_inl void ic_call icppStaticThreadAllocator::deallocate(void_p pMem) ic_noexc {
        return icThreadDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticThreadAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icThreadRealloc(pMem, btSz);
    }

ic_info("icppStaticCountedThreadAllocator & icppStaticCountedThreadAllocator2")
    ic_inl void_p ic_call icppStaticCountedThreadAllocator::allocate(size_t btSz) ic_noexc {
        return icCountedAlloc(btSz);
    }

    ic_inl void ic_call icppStaticCountedThreadAllocator::deallocate(void_p pMem) ic_noexc {
        return icCountedDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticCountedThreadAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icCountedRealloc(pMem, btSz);
    }
