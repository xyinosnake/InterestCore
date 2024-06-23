
#pragma once

#include"./P_icSortHeap.h"
#include"./P_icPopHeap.h"

/*
    ic_if_return(ed - bg < 2, ic_nothing); \
    ic_for_do(Type* checkPos = bg + 1, ed != checkPos, --ed, func(bg, ed))
*/

ic_info("defs")
    #define icSortHeap_m(Type, func) \
        for (; ed - bg >= 2; --ed) { func(bg, ed); }
    #define Dfn_icSortHeap_m(suffix, Type) \
        ic_core_dcl void ic_call icSortHeapLess##suffix   (Type* bg, Type* ed) ic_noexc { icSortHeap_m(Type, icPopHeapLess##suffix);    } \
        ic_core_dcl void ic_call icSortHeapGreater##suffix(Type* bg, Type* ed) ic_noexc { icSortHeap_m(Type, icPopHeapGreater##suffix); }
    ic_macro_x4_param_x2(Dfn_icSortHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icSortHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icSortHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icSortHeap_m
    #undef icSortHeap_m
    ic_core_dcl void ic_call icSortHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
        ic_if_return(icObjPtrDiffU(bg, ed, btSzOfObj) < 2, ic_nothing);
        ic_for_do(void_p checkPos = icAddObjPtr(bg, 1, btSzOfObj), ed != checkPos, ed = icSubObjPtr(ed, 1, btSzOfObj), icPopHeapObj(bg, ed, btSzOfObj, pInitedTempVal, fCmp, fAssign));
    }