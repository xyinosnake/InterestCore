
#pragma once

#include"./icCoreMemoryFuncs.h"

ic_info("decs: P4")
    ic_core_dcl void ic_call icTakeP4(IC_P4* pP4, IC_P4* pTargetP4, ic_dealloc_f dealloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        ic_if_do(p0, dealloc(p0));
        void** ppTgt = pTargetP4->ptr;
        pp[0] = ppTgt[0];
        pp[1] = ppTgt[1];
        pp[2] = ppTgt[2];
        pp[3] = ppTgt[3];
        ppTgt[0] = 0;
        ppTgt[1] = 0;
        ppTgt[2] = 0;
        ppTgt[3] = 0;
    }

    ic_core_dcl void ic_call icDestroyP4(IC_P4* pP4, ic_dealloc_f dealloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        if (p0) {
            dealloc(p0);
            pp[0] = 0;
            pp[1] = 0;
            pp[2] = 0;
            pp[3] = 0;
        }
    }

    ic_core_dcl void_p ic_call icShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        void_p p3 = pp[3];
        ic_if_return(p0 == p1 && p2 == p3, p0);
        size_t old_btSz = icPtrDiffU(p1, p2);
        void_p new_p0   = pAlloc->alloc(old_btSz);
        ic_if_return(!new_p0, new_p0);
        void_p new_p2 = icCopyMemSize(new_p0, p1, old_btSz);
        pp[0] = new_p0;
        pp[1] = new_p0;
        pp[2] = new_p2;
        pp[3] = new_p2;
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icCreateP4(IC_P4* pP4, size_t btSz, size_t btLMinRes, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp       = pP4->ptr;
        void_p p0       = pp[0];
        void_p p3       = pp[3];
        size_t btOldCap = icPtrDiffU(p0, p3);
        size_t btMinCap = btLMinRes + btSz + btRMinRes;
        void_p new_p0;
        void_p new_p1;
        ic_if_do_and_goto(btOldCap >= btMinCap, new_p1 = icAddPtr(p0, btLMinRes), jSetP1P2);
        new_p0 = pAlloc->alloc(btMinCap);
        ic_if_return(!new_p0, new_p0);
        ic_if_do(p0, pAlloc->dealloc(p0));
    //jSetP0P3:
        pp[0]  = new_p0;
        pp[3]  = icAddPtr(new_p0, btMinCap);
        new_p1 = icAddPtr(new_p0, btLMinRes);
    jSetP1P2:
        pp[1] = new_p1;
        pp[2] = icAddPtr(new_p1, btSz);
        return new_p1;
    }

    ic_core_dcl void_p ic_call icCreateP4FromMem(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btLMinRes, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        size_t btSz  = icPtrDiffU(bg, ed);
        void_p pData = icCreateP4(pP4, btSz, btLMinRes, btRMinRes, pAlloc);
        ic_if_return(!pData, pData);
        return icCopyMemSize(pData, bg, btSz);
    }

    ic_core_dcl void_p ic_call icInsertPlaceToP4(IC_P4* pP4, void_p pos, size_t btInsert, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp        = pP4->ptr;
        void_p p2        = pp[2];
        void_p p3        = pp[3];
        size_t btOldRRes = icPtrDiffU(p2, p3); //右挪
        ic_if_do_and_return(btOldRRes >= btInsert, pp[2] = icMoveMem(icAddPtr(pos, btInsert), pos, p2), pos);
        void_p p0        = pp[0];
        void_p p1        = pp[1];
        size_t btOldLRes = icPtrDiffU(p0, p1);
        if (btOldLRes >= btInsert) { //左挪
            void_p new_p1 = icSubPtr(p1, btInsert);
            pos = icCopyMem(new_p1, p1, pos); //[*] pos = new_pos;
            pp[1] = new_p1;
            return pos;
        }
        size_t btNewCap = (icPtrDiffU(p0, p3) << 1) + btInsert;
        void_p new_p0   = pAlloc->alloc(btNewCap);
        ic_if_return(!new_p0, new_p0);
        size_t btNewSize = icPtrDiffU(p1, p2) + btInsert;
        size_t btNewLRes = (btNewCap - btNewSize) << 1;
        void_p new_p1  = icAddPtr(new_p0, btNewLRes);
        void_p new_pos = icCopyMem(new_p1, p1, pos); //拷贝左块
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = icCopyMem(icAddPtr(new_pos, btInsert), pos, p2); //拷贝右块
        pp[3] = icAddPtr(new_p0, btNewCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_pos;
    }

    ic_core_dcl void_p ic_call icInsertMemSizeToP4(IC_P4* pP4, void_p pos, cvoid_p memBg, size_t memBtSz, const IC_ALLOC* pAlloc) ic_noexc {
        pos = icInsertPlaceToP4(pP4, pos, memBtSz, pAlloc);
        ic_if_goto(!pos, posEnd);
        pos = icCopyMemSize(pos, memBg, memBtSz);
        ic_label_return(posEnd, pos);
    }

    ic_core_dcl void_p ic_call icReserveP4(IC_P4* pP4, size_t btCap, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p3 = pp[3];
        size_t old_btCap = icPtrDiffU(p0, p3);
        ic_if_return(old_btCap >= btCap, p1);
        void_p new_p0 = pAlloc->alloc(btCap);
        ic_if_return(!new_p0, new_p0);
        void_p new_p1 = icAddPtr(new_p0, icPtrDiff(p0, p1) * btCap / old_btCap);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = icCopyMem(new_p1, p1, pp[2]);
        pp[3] = icAddPtr(new_p0, btCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p1;
    }

    ic_core_dcl void_p ic_call icReserveResP4(IC_P4* pP4, size_t btLRes, size_t btRRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        void_p p3 = pp[3];
        size_t old_btLRes = icPtrDiffU(p0, p1);
        size_t old_btRRes = icPtrDiffU(p2, p3);
        ic_if_return(old_btLRes >= btLRes && old_btRRes >= btRRes, p1);
        size_t new_btLRes = ic_greater(btLRes, old_btLRes);
        size_t new_btRRes = ic_greater(btLRes, old_btLRes);
        size_t old_btSz  = icPtrDiffU(p1, p2);
        size_t new_btCap = new_btLRes + old_btSz + new_btRRes;
        void_p new_p0 = pAlloc->alloc(new_btCap);
        ic_if_return(!new_p0, new_p0);
        void_p new_p1 = icAddPtr(new_p0, new_btLRes);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = icCopyMem(new_p1, p1, p2);
        pp[3] = icAddPtr(new_p0, new_btCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p1;
    }

    ic_core_dcl void_p ic_call icResizeP4(IC_P4* pP4, size_t btSz, size_t btLMinRes, size_t btRMinRes, bool bMem0, const IC_ALLOC* pAlloc) ic_noexc {
        //尚未完成！
        return NULL;
    }

    ic_core_dcl void_p ic_call icLShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        ic_if_return(p0 == p1, p0);
        void_p p2 = pp[2];
        void_p p3 = pp[3];
        size_t old_btSz        = icPtrDiffU(p1, p2);
        size_t old_btSzAndRRes = icPtrDiffU(p1, p3);
        void_p new_p0          = pAlloc->alloc(old_btSzAndRRes);
        ic_if_return(!new_p0, new_p0);
        void_p new_p2 = icCopyMemSize(new_p0, p1, old_btSz);
        pp[0] = new_p0;
        pp[1] = new_p0;
        pp[2] = new_p2;
        pp[3] = icAddPtr(new_p0, old_btSzAndRRes);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icRShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p1 = pp[1];
        void_p p2 = pp[2];
        void_p p3 = pp[3];
        ic_if_return(p2 == p3, p1);
        void_p p0 = pp[0];
        size_t old_btSz        = icPtrDiffU(p1, p2);
        size_t old_btSzAndLRes = icPtrDiffU(p0, p2);
        void_p new_p0          = pAlloc->alloc(old_btSzAndLRes);
        ic_if_return(!new_p0, new_p0);
        void_p new_p1 = icAddPtr(new_p0, old_btSzAndLRes - old_btSz);
        void_p new_p2 = icCopyMemSize(new_p1, p1, old_btSz);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = new_p2;
        pp[3] = new_p2;
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p0;
    }

    ic_core_dcl void_p ic_call icLAppendPlaceToP4(IC_P4* pP4, size_t btLAppend, size_t btLMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p0 = pp[0];
        void_p p1 = pp[1];
        size_t btLOldRes = icPtrDiffU(p0, p1);
        size_t btLAppCap = btLAppend + btLMinRes;
        ic_if_do_and_return(btLOldRes >= btLAppCap, pp[1] = p1 = icSubPtr(p1, btLAppend), p1);
        void_p p3       = pp[3];
        size_t btNewCap = (icPtrDiffU(p0, p3) << 1) + btLAppCap;
        void_p new_p0   = pAlloc->alloc(btNewCap);
        ic_if_return(!new_p0, new_p0);
        void_p p2     = pp[2];
        void_p new_p3 = icAddPtr(new_p0, btNewCap);
        void_p cp_pos = icSubPtr(new_p3, icPtrDiffU(p1, p3));
        void_p new_p2 = icCopyMem(cp_pos, p1, p2);
        void_p new_p1 = icSubPtr(cp_pos, btLAppend);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = new_p2;
        pp[3] = new_p3;
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_p1;
    }

    ic_core_dcl void_p ic_call icRAppendPlaceToP4(IC_P4* pP4, size_t btRAppend, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        void** pp = pP4->ptr;
        void_p p2 = pp[2];
        void_p p3 = pp[3];
        size_t btROldRes = icPtrDiffU(p2, p3);
        size_t btRAppCap = btRAppend + btRMinRes;
        ic_if_do_and_return(btROldRes >= btRAppCap, pp[2] = icAddPtr(p2, btRAppend), p2);
        void_p p0       = pp[0];
        size_t btNewCap = (icPtrDiffU(p0, p3) << 1) + btRAppCap;
        void_p new_p0   = pAlloc->alloc(btNewCap);
        ic_if_return(!new_p0, new_p0);
        void_p p1 = pp[1];
        void_p new_p1  = icAddPtr(new_p0, icPtrDiffU(p0, p1));
        void_p new_pos = icCopyMem(new_p1, p1, p2);
        void_p new_p2  = icAddPtr(new_pos, btRAppend);
        pp[0] = new_p0;
        pp[1] = new_p1;
        pp[2] = new_p2;
        pp[3] = icAddPtr(new_p0, btNewCap);
        ic_if_do(p0, pAlloc->dealloc(p0));
        return new_pos;
    }

    ic_core_dcl void_p ic_call icLAppendMemToP4(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btLMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        size_t btLAppend = icPtrDiffU(bg, ed);
        void_p pos       = icLAppendPlaceToP4(pP4, btLAppend, btLMinRes, pAlloc);
        ic_if_goto(!pos, posEnd);
        pos = icCopyMemSize(pos, bg, btLAppend);
        ic_label_return(posEnd, pos);
    }

    ic_core_dcl void_p ic_call icRAppendMemToP4(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc {
        size_t btRAppend = icPtrDiffU(bg, ed);
        void_p pos       = icRAppendPlaceToP4(pP4, btRAppend, btRMinRes, pAlloc);
        ic_if_goto(!pos, posEnd);
        pos = icCopyMemSize(pos, bg, btRAppend);
        ic_label_return(posEnd, pos);
    }
