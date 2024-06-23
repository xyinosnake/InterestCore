
#pragma once

#include"../../Common/Funcs/icCoreCommonFuncs.h"
#include"./icCoreMemoryFuncs.h"

ic_info("inline decs: P3")
    ic_inl void ic_call icInitP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        pp[0] = 0;
        pp[1] = 0;
        pp[2] = 0;
    }

    ic_inl size_t ic_call icSizeOfBytesP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        return icPtrDiffU(pp[0], pp[1]);
    }

    ic_inl size_t ic_call icCapOfBytesP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        return icPtrDiffU(pp[0], pp[2]);
    }

    ic_inl size_t ic_call icResOfBytesP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        return icPtrDiffU(pp[1], pp[2]);
    }

    ic_inl void* ic_call icBeginP3(IC_P3* pP3) ic_noexc {
        return pP3->ptr[0];
    }

    ic_inl void* ic_call icEndP3(IC_P3* pP3) ic_noexc {
        return pP3->ptr[1];
    }

    ic_inl void ic_call icClearP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        pp[1] = pp[0];
    }

    ic_inl void ic_call icEraseP3(IC_P3* pP3, void* bg, void* ed) ic_noexc {
        void** pp = pP3->ptr;
        pp[1] = icCopyMem(bg, ed, pp[1]);
    }

    ic_inl void* ic_call icPopP3(IC_P3* pP3, size_t btSzOfElem) ic_noexc {
        void** pp = pP3->ptr;
        ic_assert(pp[0] != pp[1], "P3 is empty!");
        void* new_p1 = icSubPtr(pp[1], btSzOfElem);
        pp[1] = new_p1;
        return new_p1;
    }

    ic_inl bool ic_call icIsEmptyP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        return pp[0] == pp[1];
    }

    ic_inl bool ic_call icIsNullP3(IC_P3* pP3) ic_noexc {
        void** pp = pP3->ptr;
        return !(pp[0] || pp[1] || pp[2]);
    }

    ic_inl void_p ic_call icInsertMemToP3(IC_P3* pP3, void_p pos, cvoid_p bg, cvoid_p ed, const IC_ALLOC* pAlloc) ic_noexc {
        return icInsertMemSizeToP3(pP3, pos, bg, icPtrDiffU(bg, ed), pAlloc);
    }

ic_info("inline decs: P3 Obj")
    ic_inl size_t ic_call icSizeOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc {
        return icSizeOfBytesP3(pP3) / btSzOfObj;
    }

    ic_inl size_t ic_call icCapOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc {
        return icCapOfBytesP3(pP3) / btSzOfObj;
    }

    ic_inl size_t ic_call icResOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc {
        return icResOfBytesP3(pP3) / btSzOfObj;
    }