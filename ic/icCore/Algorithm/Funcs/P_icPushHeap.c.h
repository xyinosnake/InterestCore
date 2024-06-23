
#pragma once

#include"./P_icPushHeap.h"

ic_info("defs: icPushHeapByIndex")
    #define icPushHeapByIndex_m(opt) \
        ic_init_while_do_x3(ptrdiff_t idx = (hole - 1) >> 1, top < hole && (*(bg + idx) opt val),\
            *(bg + hole) = *(bg + idx), hole = idx, idx = (hole - 1) >> 1);\
        *(bg + hole) = val
    #define Dfn_icPushHeapByIndex_m(suffix, Type) \
        ic_core_dcl void ic_call icPushHeapByIndexLess##suffix   (Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc { icPushHeapByIndex_m(<); } \
        ic_core_dcl void ic_call icPushHeapByIndexGreater##suffix(Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc { icPushHeapByIndex_m(>); }
    ic_macro_x4_param_x2(Dfn_icPushHeapByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icPushHeapByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icPushHeapByIndex_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icPushHeapByIndex_m
    #undef icPushHeapByIndex_m
    ic_core_dcl void ic_call icPushHeapByIndexObj(void_p bg, size_t btSzOfObj, ptrdiff_t hole, ptrdiff_t top, cvoid_p pVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
        ic_init_while_do_x3(ptrdiff_t idx = (hole - 1) >> 1, top < hole && fCmp(icAddObjPtr(bg, idx, btSzOfObj), pVal),
            fAssign(icAddObjPtr(bg, hole, btSzOfObj), icAddObjPtr(bg, idx, btSzOfObj)), hole = idx, idx = (hole - 1) >> 1);
        fAssign(icAddObjPtr(bg, hole, btSzOfObj), pVal);
    }