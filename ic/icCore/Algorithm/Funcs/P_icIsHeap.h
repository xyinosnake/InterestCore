
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs")
    ic_info("decs: icIsHeapUntil")
        #define Dcl_icIsHeapUntil_m(suffix, Type) \
            ic_core_dcl Type* ic_call icIsHeapUntilLess##suffix   (const Type* bg, const Type* ed) ic_noexc; \
            ic_core_dcl Type* ic_call icIsHeapUntilGreater##suffix(const Type* bg, const Type* ed) ic_noexc; \
            ic_inl      Type* ic_call icIsHeapUntil##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icIsHeapUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icIsHeapUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icIsHeapUntil_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icIsHeapUntil_m
        ic_core_dcl void_p ic_call icIsHeapUntilObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc;

    ic_info("decs: icIsHeap")
        #define Dcl_icIsHeap_m(suffix, Type) \
            ic_inl bool ic_call icIsHeapLess##suffix   (const Type* bg, const Type* ed) ic_noexc; \
            ic_inl bool ic_call icIsHeapGreater##suffix(const Type* bg, const Type* ed) ic_noexc; \
            ic_inl bool ic_call icIsHeap##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icIsHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icIsHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icIsHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icIsHeap_m
        ic_inl bool ic_call icIsHeapObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc;

ic_info("inl")
    ic_info("inl: icIsHeapUntil")
        #define Inl_icIsHeapUntil_m(suffix, Type) \
            ic_inl Type* ic_call icIsHeapUntil##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc { \
                ic_if_else_return(bGreater, icIsHeapUntilGreater##suffix(bg, ed), icIsHeapUntilLess##suffix(bg, ed)); \
            }
        ic_macro_x4_param_x2(Inl_icIsHeapUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icIsHeapUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icIsHeapUntil_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icIsHeapUntil_m
    
    ic_info("inl: icIsHeap")
        #define Inl_icIsHeap_m(suffix, Type) \
            ic_inl bool ic_call icIsHeapLess##suffix   (const Type* bg, const Type* ed) ic_noexc { return (const Type*)icIsHeapUntilLess##suffix   (bg, ed) == ed; } \
            ic_inl bool ic_call icIsHeapGreater##suffix(const Type* bg, const Type* ed) ic_noexc { return (const Type*)icIsHeapUntilGreater##suffix(bg, ed) == ed; } \
            ic_inl bool ic_call icIsHeap##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc { ic_if_else_return(bGreater, icIsHeapGreater##suffix(bg, ed), icIsSortedLess##suffix(bg, ed)); }
        ic_macro_x4_param_x2(Inl_icIsHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icIsHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icIsHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icIsHeap_m
        ic_inl bool ic_call icIsHeapObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc {
            return icIsHeapUntilObj(bg, ed, btSzOfObj, f) == (void_p)ed;
        }