
#pragma once

#include"./icCoreMemoryFuncs.h"

ic_info("inline decs: MixedSegBuf")
    ic_inl void ic_call icInitMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc {
        icInitP3((IC_P3*)pMixedP3);
    }

    ic_inl size_t ic_call icSizeOfBytesMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc {
        return icSizeOfBytesP3((IC_P3*)pMixedP3);
    }

    ic_inl size_t ic_call icCapOfBytesMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap) ic_noexc {
        void** pp = pMixedP3->ptr;
        void*  p0 = pp[0];
        return p0 ? icPtrDiffU(p0, pp[2]) : btStaticCap;
    }

    ic_inl size_t ic_call icResOfBytesMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap) ic_noexc {
        void** pp = pMixedP3->ptr;
        void*  p0 = pp[0];
        void*  p1 = pp[1];
        return p0 ? icPtrDiffU(p1, pp[2]) : btStaticCap - (size_t)p1;
    }

    ic_inl void* ic_call icBeginMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc {
        void* p0 = pMixedP3->ptr[0];
        return p0 ? p0 : pMixedP3->buffer;
    }

    ic_inl void* ic_call icEndMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc {
        void** pp = pMixedP3->ptr;
        void*  p0 = pp[0];
        void*  p1 = pp[1];
        return p0 ? p1 : icAddPtr(pMixedP3->buffer, (ptrdiff_t)p1);
    }

    ic_inl void ic_call icDestroyMixedP3(IC_MIXED_P3* pMixedP3, ic_dealloc_f dealloc) ic_noexc {
        icDestroyP3((IC_P3*)pMixedP3, dealloc);
    }