
#pragma once

#include"./P_icMakeHeap.h"
#include"./P_icPopHeap.h"

ic_info("defs: icMakeHeap")
    #define icMakeHeap_m(func) \
        ic_stv_x2(ptrdiff_t, bottom = ed - bg, hole = bottom >> 1); \
        ic_while_do_x2(hole > 0, --hole, func(bg, hole, bottom, *(bg + hole)))
    #define Dfn_icMakeHeap_m(suffix, Type) \
        ic_core_dcl void ic_call icMakeHeapLess##suffix   (Type* bg, Type* ed) ic_noexc { icMakeHeap_m(icPopHeapHoleByIndexLess##suffix);    } \
        ic_core_dcl void ic_call icMakeHeapGreater##suffix(Type* bg, Type* ed) ic_noexc { icMakeHeap_m(icPopHeapHoleByIndexGreater##suffix); }
    ic_macro_x4_param_x2(Dfn_icMakeHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icMakeHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icMakeHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icMakeHeap_m
    #undef icMakeHeap_m
    ic_core_dcl void ic_call icMakeHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
        ic_stv_x2(ptrdiff_t, bottom = icObjPtrDiff(bg, ed, btSzOfObj), hole = bottom >> 1);\
        ic_while_do_x3(hole > 0, --hole, 
            fAssign(pInitedTempVal, icAddObjPtr(bg, hole, btSzOfObj)),
            icPopHeapHoleByIndexObj(bg, btSzOfObj, hole, bottom, pInitedTempVal, fCmp, fAssign))
    }