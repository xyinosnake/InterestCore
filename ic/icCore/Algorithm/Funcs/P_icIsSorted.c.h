
#pragma once

#include"./P_icIsSorted.h"

ic_info("defs")
    #define icIsSortedUntil_m(Type, opt) \
        ic_if_return((ed - bg) <= 1, (Type*)ed); \
        ic_do_x1(--ed); \
        ic_do_x2_while_return(Type v = *bg, ic_if_break(!(v opt *++bg)), bg != ed, (Type*)++bg)
    #define icDfnIsSortedUntil_m(suffix, Type) \
        ic_core_dcl Type* ic_call icIsSortedUntilLess##suffix   (const Type* bg, const Type* ed) ic_noexc { icIsSortedUntil_m(Type, <); } \
        ic_core_dcl Type* ic_call icIsSortedUntilGreater##suffix(const Type* bg, const Type* ed) ic_noexc { icIsSortedUntil_m(Type, >); }
    ic_macro_x4_param_x2(icDfnIsSortedUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(icDfnIsSortedUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(icDfnIsSortedUntil_m, F32, flo32_t, F64, flo64_t);
    #undef icDfnIsSortedUntil_m
    #undef icIsSortedUntil_m
    ic_core_dcl void* ic_call icIsSortedUntilObj(const void* bg, const void* ed, size_t btSzOfObj, ic_compare_f f) ic_noexc {
        ic_if_return(icObjPtrDiffU(bg, ed, btSzOfObj) <= 1, (void*)ed);
        ic_do_x1(ed = icSubPtr(ed, (ptrdiff_t)btSzOfObj));
        ic_do_x2_while_return(cvoid_p it = bg, ic_if_break(!f(it, bg = icAddPtr(bg, btSzOfObj))), bg != ed, icAddPtr(bg, btSzOfObj));
    }