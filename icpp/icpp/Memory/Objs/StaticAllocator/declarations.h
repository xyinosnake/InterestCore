
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"

ic_info("declarations")
    ic_info("icppStaticAllocator & icppStaticAllocator2")
        class icppStaticAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticAllocator2: public icppStaticAllocator {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };

    ic_info("icppStaticCountedAllocator & icppStaticCountedAllocator2")
        class icppStaticCountedAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticCountedAllocator2: icppStaticCountedAllocator {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };

    ic_info("icppStaticPosixAllocator & icppStaticPosixAllocator2")
        class icppStaticPosixAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticPosixAllocator2: public icppStaticPosixAllocator {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };
    
    ic_info("icppStaticCountedPosixAllocator & icppStaticCountedPosixAllocator2")
        class icppStaticCountedPosixAllocator {
        public:
            ic_inl static void_p ic_call allocate(size_t btSz) ic_noexc;
            ic_inl static void   ic_call deallocate(void_p pMem) ic_noexc;
        };

        class icppStaticCountedPosixAllocator2: icppStaticCountedPosixAllocator {
        public:
            ic_inl static void_p ic_call reallocate(void_p pMem, size_t btSz) ic_noexc;
        };