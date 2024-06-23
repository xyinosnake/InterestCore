
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs")
    ic_info("decs: isSortedUntil")
        #define Dcl_icIsSortedUntil_m(suffix, Type) \
            ic_core_dcl Type* ic_call icIsSortedUntilLess##suffix   (const Type* bg, const Type* ed) ic_noexc; \
            ic_core_dcl Type* ic_call icIsSortedUntilGreater##suffix(const Type* bg, const Type* ed) ic_noexc; \
            ic_inl      Type* ic_call icIsSortedUntil##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icIsSortedUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icIsSortedUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icIsSortedUntil_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icIsSortedUntil_m
        ic_core_dcl void* ic_call icIsSortedUntilObj(const void* bg, const void* ed, size_t btSzOfObj, ic_compare_f f) ic_noexc;

    ic_info("decs: isSorted")
        #define Dcl_icIsSorted_m(suffix, Type) \
            ic_inl bool ic_call icIsSortedLess##suffix   (const Type* bg, const Type* ed) ic_noexc; \
            ic_inl bool ic_call icIsSortedGreater##suffix(const Type* bg, const Type* ed) ic_noexc; \
            ic_inl bool ic_call icIsSorted##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icIsSorted_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icIsSorted_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icIsSorted_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icIsSorted_m
        ic_inl bool ic_call icIsSortedObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc;

ic_info("inl")
    ic_info("inl: isSortedUntil")
        #define Inl_icIsSortedUntil_m(suffix, Type) \
            ic_inl Type* ic_call icIsSortedUntil##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc { \
                ic_if_else_return(bGreater, icIsSortedUntilGreater##suffix(bg, ed), icIsSortedUntilLess##suffix(bg, ed)); \
            }
        ic_macro_x4_param_x2(Inl_icIsSortedUntil_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icIsSortedUntil_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icIsSortedUntil_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icIsSortedUntil_m

    ic_info("inl: isSorted")
        #define Inl_icIsSorted_m(suffix, Type) \
            ic_inl bool ic_call icIsSortedLess##suffix   (const Type* bg, const Type* ed) ic_noexc { return (const Type*)icIsSortedUntilLess##suffix   (bg, ed) == ed; } \
            ic_inl bool ic_call icIsSortedGreater##suffix(const Type* bg, const Type* ed) ic_noexc { return (const Type*)icIsSortedUntilGreater##suffix(bg, ed) == ed; } \
            ic_inl bool ic_call icIsSorted##suffix(bool bGreater, const Type* bg, const Type* ed) ic_noexc { ic_if_else_return(bGreater, icIsSortedGreater##suffix(bg, ed), icIsSortedLess##suffix(bg, ed)); }
        ic_macro_x4_param_x2(Inl_icIsSorted_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icIsSorted_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icIsSorted_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icIsSorted_m
        ic_inl bool ic_call icIsSortedObj(cvoid_p bg, cvoid_p ed, size_t btSzOfObj, ic_compare_f f) ic_noexc {
            return (cvoid_p)icIsSortedUntilObj(bg, ed, btSzOfObj, f) == ed;
        }