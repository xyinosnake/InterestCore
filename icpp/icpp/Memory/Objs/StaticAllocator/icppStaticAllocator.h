
#pragma once

#include"./declarations.h"
#include"../../Funcs/icppMemoryFuncs.h"

ic_info("icppStaticAllocator & icppStaticAllocator2")
    ic_inl void_p ic_call icppStaticAllocator::allocate(size_t btSz) ic_noexc {
        return icAlloc(btSz);
    }

    ic_inl void ic_call icppStaticAllocator::deallocate(void_p pMem) ic_noexc {
        return icDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icRealloc(pMem, btSz);
    }

ic_info("icppStaticCountedAllocator & icppStaticCountedAllocator2")
    ic_inl void_p ic_call icppStaticCountedAllocator::allocate(size_t btSz) ic_noexc {
        return icCountedAlloc(btSz);
    }

    ic_inl void ic_call icppStaticCountedAllocator::deallocate(void_p pMem) ic_noexc {
        return icCountedDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticCountedAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icCountedRealloc(pMem, btSz);
    }

ic_info("icppStaticPosixAllocator & icppStaticPosixAllocator2")
    ic_inl void_p ic_call icppStaticPosixAllocator::allocate(size_t btSz) ic_noexc {
        return icPosixAlloc(btSz);
    }

    ic_inl void ic_call icppStaticPosixAllocator::deallocate(void_p pMem) ic_noexc {
        return icPosixDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticPosixAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icPosixRealloc(pMem, btSz);
    }

ic_info("icppStaticCountedPosixAllocator & icppStaticCountedPosixAllocator2")
    ic_inl void_p ic_call icppStaticCountedPosixAllocator::allocate(size_t btSz) ic_noexc {
        return icCountedPosixAlloc(btSz);
    }

    ic_inl void ic_call icppStaticCountedPosixAllocator::deallocate(void_p pMem) ic_noexc {
        return icCountedPosixDealloc(pMem);
    }

    ic_inl void_p ic_call icppStaticCountedPosixAllocator2::reallocate(void_p pMem, size_t btSz) ic_noexc {
        return icCountedPosixRealloc(pMem, btSz);
    }