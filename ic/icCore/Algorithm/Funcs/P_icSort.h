
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: icSort")
    #define Dcl_icSort_m(suffix, Type) \
        ic_core_dcl void ic_call icSortLess##suffix   (Type* bg, Type* ed) ic_noexc; \
        ic_core_dcl void ic_call icSortGreater##suffix(Type* bg, Type* ed) ic_noexc; \
        ic_inl      void ic_call icSort##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
    ic_macro_x4_param_x2(Dcl_icSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dcl_icSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dcl_icSort_m, F32, flo32_t, F64, flo64_t);
    #undef Dcl_icSort_m
    ic_core_dcl void ic_call icSortObj(void* bg, void* ed, size_t btSzOfObj, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;


ic_info("inl: icSort")
    #define Inl_icSort_m(suffix, Type) \
        ic_inl void ic_call icSort##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
            ic_if_else_do(bGreater, icSortGreater##suffix(bg, ed), icSortLess##suffix(bg, ed)); \
        }
    ic_macro_x4_param_x2(Inl_icSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Inl_icSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Inl_icSort_m, F32, flo32_t, F64, flo64_t);
    #undef Inl_icSort_m