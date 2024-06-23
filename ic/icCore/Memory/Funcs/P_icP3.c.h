
#pragma once

#include"./icCoreMemoryFuncs.h"

ic_info("decs: P3")
    ic_core_dcl void ic_call icTakeP3(IC_P3* pP3, IC_P3* pTargetP3, ic_dealloc_f dealloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        ic_if_do(p0, dealloc(p0));
        void** ppTgt = pTargetP3->ptr;
        pp[0] = ppTgt[0];
        pp[1] = ppTgt[1];
        pp[2] = ppTgt[2];
        ppTgt[0] = 0;
        ppTgt[1] = 0;
        ppTgt[2] = 0;
    }

    ic_core_dcl void ic_call icDestroyP3(IC_P3* pP3, ic_dealloc_f dealloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        if (p0) {
            dealloc(p0);
            pp[0] = 0;
            pp[1] = 0;
            pp[2] = 0;
        }
    }

    ic_core_dcl void_p ic_call icReserveP3(IC_P3* pP3, size_t btCap, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        void_p p2 = pp[2];
        size_t old_btCap = icPtrDiffU(p0, p2);
        ic_if_return(old_btCap >= btCap, p0);
        void_p new_p0 = pAlloc->alloc(btCap);
        ic_if_return(!new_p0, new_p0);
        void_p p1 = pp[1];
        pp[0] = new_p0;
        pp[1] = icCopyMem(new_p0, p0, p1);
        pp[2] = icAddPtr(new_p0, btCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icReserveResP3(IC_P3* pP3, size_t btRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        size_t old_btRes = icPtrDiffU(p1, p2);
        ic_if_return(old_btRes >= btRes, p0);
        size_t btOldSize = icPtrDiffU(p0, p1);
        size_t btNewCap  = btOldSize + btRes;
        void_p new_p0 = pAlloc->alloc(btNewCap);
        ic_if_return(!new_p0, new_p0);
        pp[0] = new_p0;
        pp[1] = icCopyMem(new_p0, p0, p1);
        pp[2] = icAddPtr(new_p0, btNewCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icResizeP3(IC_P3* pP3, size_t btSz, size_t btMinRes, bool bMem0, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        size_t old_btSz  = icPtrDiffU(p0, p1);
        size_t old_btCap = icPtrDiffU(p0, p2);
        size_t new_btCap = btSz + btMinRes;
        if (new_btCap <= old_btCap) {
            ic_if_do(btSz > old_btSz, 
                ic_if_do(bMem0, icClearMemSize(p1, btSz - old_btSz)));
            pp[1] = icAddPtr(p0, btSz);
            return p0;
        } 
        void_p new_p0 = pAlloc->alloc(new_btCap);
        ic_if_return(!new_p0, new_p0);
        size_t cpy_btSz;
        if (btSz > old_btSz) { 
            cpy_btSz = old_btSz;
            ic_if_do(bMem0, icClearMemSize(icAddPtr(new_p0, cpy_btSz), btSz - cpy_btSz));
        } else {
            cpy_btSz = btSz;
        }
        icCopyMemSizeNoRet(new_p0, p0, cpy_btSz);
        pp[0] = new_p0;
        pp[1] = icAddPtr(new_p0, btSz);
        pp[2] = icAddPtr(new_p0, new_btCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icShrinkP3(IC_P3* pP3, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        ic_if_return(p1 == p2, p0);
        size_t old_btSz = icPtrDiffU(p0, p1);
        void_p new_p0   = pAlloc->alloc(old_btSz);
        ic_if_return(!new_p0, new_p0);
        void_p new_p1 = icCopyMemSize(new_p0, p0, old_btSz);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = new_p1;
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icCreateP3(IC_P3* pP3, size_t btSz, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp       = pP3->ptr;
        void_p p0       = pp[0];
        void_p p2       = pp[2];
        size_t btOldCap = icPtrDiffU(p0, p2);
        size_t btMinCap = btSz + btMinRes;
        ic_if_do_and_return(btOldCap >= btMinCap, pp[1] = icAddPtr(p0, btSz), p0);
        void_p new_p0 = pAlloc->alloc(btMinCap);
        ic_if_return(!new_p0, new_p0);
        ic_if_do(p0, pAlloc->dealloc(p0));
        pp[0] = new_p0;
        pp[1] = icAddPtr(new_p0, btSz);
        pp[2] = icAddPtr(new_p0, btMinCap);
        return new_p0;
    }

    ic_core_dcl void_p ic_call icCreateP3FromMem(IC_P3* pP3, cvoid_p bg, cvoid_p ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        size_t btSz  = icPtrDiffU(bg, ed);
        void_p pData = icCreateP3(pP3, btSz, btMinRes, pAlloc);
        ic_if_return(!pData, pData);
        return icCopyMemSize(pData, bg, btSz);
    }

    ic_core_dcl void_p ic_call icInsertPlaceToP3(IC_P3* pP3, void_p pos, size_t btInsert, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp       = pP3->ptr;
        void_p p1       = pp[1];
        void_p p2       = pp[2];
        size_t btOldRes = icPtrDiffU(p1, p2);
        ic_if_do_and_return(btOldRes >= btInsert, pp[1] = icMoveMem(icAddPtr(pos, btInsert), pos, p1), pos);
        void_p p0       = pp[0];
        size_t btNewCap = (icPtrDiffU(p0, p2) << 1) + btInsert;
        void_p new_p0   = pAlloc->alloc(btNewCap);
        ic_if_return(!new_p0, new_p0);
        void_p new_pos = icCopyMem(new_p0, p0, pos);
        pp[0] = new_p0;
        pp[1] = icCopyMem(icAddPtr(new_pos, btInsert), pos, p1);
        pp[2] = icAddPtr(new_p0, btNewCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_pos;
    }

    ic_core_dcl void_p ic_call icInsertMemSizeToP3(IC_P3* pP3, void_p pos, cvoid_p memBg, size_t memBtSz, const IC_ALLOC* pAlloc) ic_noexc {
        pos = icInsertPlaceToP3(pP3, pos, memBtSz, pAlloc);
        ic_if_goto(!pos, posEnd);
        pos = icCopyMemSize(pos, memBg, memBtSz);
        ic_label_return(posEnd, pos);
    }

    ic_core_dcl void_p ic_call icAppendPlaceToP3(IC_P3* pP3, size_t btAppend, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp       = pP3->ptr;
        void_p p1       = pp[1];
        void_p p2       = pp[2];
        size_t btOldRes = icPtrDiffU(p1, p2);
        size_t btAppCap = btAppend + btMinRes;
        ic_if_do_and_return(btOldRes >= btAppCap, pp[1] = icAddPtr(p1, btAppend), p1);
        void_p p0       = pp[0];
        size_t btNewCap = (icPtrDiffU(p0, p2) << 1) + btAppCap;
        void_p new_p0   = pAlloc->alloc(btNewCap);
        void_p new_pos  = icCopyMem(new_p0, p0, p1);
        ic_if_return(!new_p0, new_p0);
        pp[0] = new_p0;
        pp[1] = icAddPtr(new_pos, btAppend);
        pp[2] = icAddPtr(new_p0, btNewCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_pos;
    }

    ic_core_dcl void_p ic_call icAppendMemToP3(IC_P3* pP3, cvoid_p bg, cvoid_p ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        size_t btAppend = icPtrDiffU(bg, ed);
        void_p pos      = icAppendPlaceToP3(pP3, btAppend, btMinRes, pAlloc);
        ic_if_goto(!pos, posEnd);
        pos = icCopyMemSize(pos, bg, btAppend);
        ic_label_return(posEnd, pos);
    }

ic_info("decs: P3 Obj")
    ic_core_dcl void ic_call icEraseObjP3(IC_P3* pP3, void_p bg, void_p ed, size_t btSzOfObj, ic_destruct_f fDestructor) ic_noexc {
        icDestructObjRange(bg, ed, btSzOfObj, fDestructor);
        icEraseP3(pP3, bg, ed);
    }

    ic_core_dcl void ic_call icClearObjP3(IC_P3* pP3, size_t btSzOfObj, ic_destruct_f fDestructor) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        ic_if_do_x2(p0 != p1, icDestructObjRange(p0, p1, btSzOfObj, fDestructor), pp[1] = p0);
    }

    ic_core_dcl void ic_call icDestroyObjP3(IC_P3* pP3, size_t btSzOfObj, ic_destruct_f fDestructor, ic_dealloc_f dealloc) ic_noexc {
        void** pp = pP3->ptr;
        void_p p0 = pp[0];
        if (p0) {
            void_p p1 = pp[1];
            ic_if_do(p0 != p1, icDestructObjRange(p0, p1, btSzOfObj, fDestructor));
            dealloc(p0);
            pp[0] = 0;
            pp[1] = 0;
            pp[2] = 0;
        }
    }

    ic_core_dcl void_p ic_call icResizeObjP3(IC_P3* pP3, size_t btSz, size_t btMinRes, const IC_CONSTRUCT* pConstruct, const IC_ALLOC* pAlloc) ic_noexc {
        //该函数尚未编写！
        return NULL;
    }