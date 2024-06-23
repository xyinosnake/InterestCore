
#pragma once

#include"./P_icPopHeap.h"

ic_info("defs: icPopHeapHoleByIndex")
    #define icPopHeapHoleByIndex_m(opt, func) \
        ic_stv_x3(ptrdiff_t, top = hole, idx = hole, maxSeqNonLeaf = (bottom - 1) >> 1);\
        while (idx < maxSeqNonLeaf) {\
            idx = 2 * idx + 2;\
            ic_if_do(*(bg + idx) opt *(bg + (idx - 1)), --idx);\
            ic_do_x2(*(bg + hole) = *(bg + idx), hole = idx);\
        }\
        ic_if_do_x2(idx == maxSeqNonLeaf && bottom % 2 == 0, *(bg + hole) = *(bg + (bottom - 1)), hole = bottom - 1);\
        func(bg, hole, top, val)
    #define Dfn_icPopHeapHoleByIndex_m(suffix, Type) \
        ic_core_dcl void ic_call icPopHeapHoleByIndexLess##suffix   (Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc { icPopHeapHoleByIndex_m(<, icPushHeapByIndexLess##suffix);    } \
        ic_core_dcl void ic_call icPopHeapHoleByIndexGreater##suffix(Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc { icPopHeapHoleByIndex_m(>, icPushHeapByIndexGreater##suffix); }
    ic_macro_x4_param_x2(Dfn_icPopHeapHoleByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icPopHeapHoleByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icPopHeapHoleByIndex_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icPopHeapHoleByIndex_m
    #undef icPushHeapByIndex_m
    ic_core_dcl void ic_call icPopHeapHoleByIndexObj(void_p bg, size_t btSzOfObj, ptrdiff_t hole, ptrdiff_t bottom, cvoid_p pVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
        ic_stv_x3(ptrdiff_t, top = hole, idx = hole, maxSeqNonLeaf = (bottom - 1) >> 1);
        while (idx < maxSeqNonLeaf) {
            idx = 2 * idx + 2;
            ptrdiff_t tIdx = idx - 1;
            ic_if_do(fCmp(icAddObjPtr(bg, idx, btSzOfObj), icAddObjPtr(bg, tIdx, btSzOfObj)), idx = tIdx);
            ic_do_x2(fAssign(icAddObjPtr(bg, hole, btSzOfObj), icAddObjPtr(bg, idx, btSzOfObj)), hole = idx);
        }
        ic_if_do_x2(idx == maxSeqNonLeaf && bottom % 2 == 0, 
            fAssign(icAddObjPtr(bg, hole, btSzOfObj), icAddObjPtr(bg, bottom - 1, btSzOfObj)), hole = bottom - 1);
        icPushHeapByIndexObj(bg, btSzOfObj, hole, top, pVal, fCmp, fAssign);
    }