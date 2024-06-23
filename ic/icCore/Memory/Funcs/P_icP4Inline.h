
#pragma once

#include"../../Common/Funcs/icCoreCommonFuncs.h"
#include"./icCoreMemoryFuncs.h"

ic_info("inline decs: P4")
    ic_inl void ic_call icInitP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        pp[0] = 0;
        pp[1] = 0;
        pp[2] = 0;
        pp[3] = 0;
    }

    ic_inl size_t ic_call icSizeOfBytesP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return icPtrDiffU(pp[1], pp[2]);
    }

    ic_inl size_t ic_call icCapOfBytesP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return icPtrDiffU(pp[0], pp[3]);
    }

    ic_inl size_t ic_call icLResOfBytesP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return icPtrDiffU(pp[0], pp[1]);
    }

    ic_inl size_t ic_call icRResOfBytesP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return icPtrDiffU(pp[2], pp[3]);
    }

    ic_inl size_t ic_call icResOfBytesP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return icPtrDiffU(pp[0], pp[1]) +
               icPtrDiffU(pp[2], pp[3]);
    }

    ic_inl void_p ic_call icBeginP4(IC_P4* pP4) ic_noexc {
        return pP4->ptr[1];
    }

    ic_inl void_p ic_call icEndP4(IC_P4* pP4) ic_noexc {
        return pP4->ptr[2];
    }

    ic_inl void ic_call icClearP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        pp[2] = pp[1];
    }

    ic_inl void ic_call icEraseP4(IC_P4* pP4, void_p bg, void_p ed) ic_noexc {
        void** pp = pP4->ptr;
        pp[2] = icCopyMem(bg, ed, pp[2]);
    }

    ic_inl void_p ic_call icLPopP4(IC_P4* pP4, size_t btSzOfElem) ic_noexc {
        void** pp = pP4->ptr;
        ic_assert(pp[1] != pp[2], "P4 is empty!");
        void* old_p1 = pp[1];
        pp[1] = icAddPtr(old_p1, btSzOfElem);
        return old_p1;
    }

    ic_inl void_p ic_call icRPopP4(IC_P4* pP4, size_t btSzOfElem) ic_noexc {
        void** pp = pP4->ptr;
        ic_assert(pp[1] != pp[2], "P4 is empty!");
        void* new_p2 = icSubPtr(pp[2], btSzOfElem);
        pp[2] = new_p2;
        return new_p2;
    }

    ic_inl bool ic_call icIsEmptyP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return pp[1] == pp[2];
    }

    ic_inl bool ic_call icIsNullP4(IC_P4* pP4) ic_noexc {
        void** pp = pP4->ptr;
        return !(pp[0] || pp[1] || pp[2] || pp[3]);
    }

    ic_inl void_p ic_call icInsertMemToP4(IC_P4* pP4, void_p pos, cvoid_p bg, cvoid_p ed, const IC_ALLOC* pAlloc) ic_noexc {
        return icInsertMemSizeToP4(pP4, pos, bg, icPtrDiffU(bg, ed), pAlloc);
    }

ic_info("inline decs: P4 Obj")
    ic_inl size_t ic_call icSizeOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc {
        return icSizeOfBytesP4(pP4) / btSzOfObj;
    }

    ic_inl size_t ic_call icCapOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc {
        return icCapOfBytesP4(pP4) / btSzOfObj;
    }

    ic_inl size_t ic_call icLResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc {
        return icLResOfBytesP4(pP4) / btSzOfObj;
    }

    ic_inl size_t ic_call icRResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc {
        return icRResOfBytesP4(pP4) / btSzOfObj;
    }

    ic_inl size_t ic_call icResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc {
        return icResOfBytesP4(pP4) / btSzOfObj;
    }
