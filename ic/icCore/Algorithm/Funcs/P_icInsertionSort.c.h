
#pragma once

#include"../../Memory/icCoreMemory.h"
#include"./P_icInsertionSort.h"

ic_info("defs")
    #define icInsertionSort_m(val_xt, opt) \
        ic_if_return(bg == ed, ic_nothing);\
        val_xt* mid = bg;\
        while (++mid != ed) {\
            ic_init_x2(val_xt* hole = mid, val_xt v = *mid);\
            ic_if_do_x2(v opt *bg, icMoveMemNoRet(icSubPtr(++hole, icPtrDiff(bg, mid)), bg, mid), *bg = v)\
            ic_else_do_x2(ic_init_while_do_x2(val_xt* prev = hole, v opt *--prev, *hole = *prev, hole = prev), *hole = v)\
        }
    #define Dfn_icInsertionSort_m(suffix, Type) \
        ic_core_dcl void ic_call icInsertionSortLess##suffix   (Type* bg, Type* ed) ic_noexc { icInsertionSort_m(Type, <); } \
        ic_core_dcl void ic_call icInsertionSortGreater##suffix(Type* bg, Type* ed) ic_noexc { icInsertionSort_m(Type, >); }
    ic_macro_x4_param_x2(Dfn_icInsertionSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icInsertionSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icInsertionSort_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icInsertionSort_m
    #undef icInsertionSort_m
    ic_core_dcl void ic_call icInsertionSortObj(void* bg, void* ed, size_t btSzOfObj, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
        ic_if_return(bg == ed, ic_nothing);
        void_p mid = bg;
        while ((mid = icAddPtr(mid, btSzOfObj)) != ed) {
            ic_init_x2(void_p hole = mid, fAssign(pInitedTempVal, mid));
            ic_if_do_x2(fCmp(pInitedTempVal, bg), icMoveMemNoRet(icSubPtr(hole = icAddPtr(hole, btSzOfObj), icPtrDiff(bg, mid)), bg, mid), fAssign(bg, pInitedTempVal))
            ic_else_do_x2(ic_init_while_do_x2(void_p prev = hole, fCmp(pInitedTempVal, prev = icSubPtr(prev, btSzOfObj)), fAssign(hole, prev), hole = prev), fAssign(hole, pInitedTempVal))
        }
    }