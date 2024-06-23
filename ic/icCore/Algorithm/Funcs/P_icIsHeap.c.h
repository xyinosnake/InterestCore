
#pragma once

#include"./P_icIsHeap.h"

ic_info("defs")
    #define icIsHeapUntil_m(val_xt, opt) \
        ic_init_x2(ptrdiff_t sz = ed - bg, ptrdiff_t szOff = 1);\
        ic_while_do_x2_return(szOff < sz, ic_init_if_return(const val_xt* bgSzOff = bg + szOff, *(bg + ((szOff - 1) >> 1)) < *bgSzOff, (val_xt*)bgSzOff), ++szOff, (val_xt*)ed)
    #define Dfn_icIsHeapUntil_m(suffix, Type) \
        ic_core_dcl Type* ic_call icIsHeapUntilLess##suffix   (const Type* bg, const Type* ed) ic_noexc { icIsHeapUntil_m(Type, <); } \
        ic_core_dcl Type* ic_call icIsHeapUntilGreater##suffix(const Type* bg, const Type* ed) ic_noexc { icIsHeapUntil_m(Type, >); }
    ic_macro_x4_param_x2(Dfn_icIsHeapUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dfn_icIsHeapUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dfn_icIsHeapUntil_m, F32, flo32_t, F64, flo64_t);
    #undef Dfn_icIsHeapUntil_m
    #undef icIsHeapUntil_m
    ic_core_dcl void_p ic_call icIsHeapUntilObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc {
        ic_init_x2(ptrdiff_t sz = icObjPtrDiff(bg, ed, btSzOfObj), ptrdiff_t szOff = 1);
        ic_while_do_x2_return(szOff < sz, ic_init_if_return(cvoid_p bgSzOff = icAddObjPtr(bg, szOff, btSzOfObj),
                f(icAddObjPtr(bg, (szOff - 1) >> 1, btSzOfObj), bgSzOff), (void_p)bgSzOff), ++szOff, (void_p)ed);
    }