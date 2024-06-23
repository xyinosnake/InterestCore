
#pragma once

#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"

ic_info("declarations")
    ic_info("icppStaticThreadAllocator & icppStaticThreadAllocator2")
        class icppStaticThreadAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticThreadAllocator2 {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };

    ic_info("icppStaticCountedThreadAllocator & icppStaticCountedThreadAllocator2")
        class icppStaticCountedThreadAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticCountedThreadAllocator2 {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };