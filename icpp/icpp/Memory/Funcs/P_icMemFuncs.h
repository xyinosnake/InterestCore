
#pragma once

#include"./icppMemoryFuncs.h"

ic_info("ic in ns inlines definitions") icpp_ns_x1(icpp)
    ic_inl void_p ic_call alloc(size_t btSz) ic_noexc {
        return icAlloc(btSz);
    }

    ic_inl void   ic_call dealloc(void_p pMem) ic_noexc {
        return icDealloc(pMem);
    }

    ic_inl void_p ic_call realloc(void_p pMem, size_t btSz) ic_noexc {
        return icRealloc(pMem, btSz);
    }

    ic_inl void_p ic_call countedAlloc(size_t btSz) ic_noexc {
        return icCountedAlloc(btSz);
    }
    
    ic_inl void ic_call countedDealloc(void_p pMem) ic_noexc {
        return icCountedDealloc(pMem);
    }

    ic_inl void_p ic_call countedRealloc(void_p pMem, size_t btSz) ic_noexc {
        return icCountedRealloc(pMem, btSz);
    }

    ic_inl volatile ptrdiff_t* ic_call getThreadAllocCountPtr() ic_noexc {
        return icGetThreadAllocCountPtr();
    }

    ic_inl void_p ic_call threadAlloc(size_t btSz) ic_noexc {
        return icThreadAlloc(btSz);
    }

    ic_inl void   ic_call threadDealloc(void_p pMem) ic_noexc {
        return icThreadDealloc(pMem);
    }

    ic_inl void_p ic_call threadRealloc(void_p pMem, size_t btSz) ic_noexc {
        return icThreadRealloc(pMem, btSz);
    }

    ic_inl void_p ic_call countedThreadAlloc(size_t btSz) ic_noexc {
        return icCountedThreadAlloc(btSz);
    }

    ic_inl void ic_call countedThreadDealloc(void_p pMem) ic_noexc {
        return icCountedThreadDealloc(pMem);
    }

    ic_inl void_p ic_call countedThreadRealloc(void_p pMem, size_t btSz) ic_noexc {
        return icCountedThreadRealloc(pMem, btSz);
    }

    ic_inl ptrdiff_t ic_call getThreadAllocCount() ic_noexc {
        return icGetThreadAllocCount();
    }
icpp_end_ns_x1