
#pragma once

#include"../../Common/icCoreCommon.h"


ic_info("decs: insertionSort")
    #define Dcl_icInsertionSort_m(suffix, Type) \
        ic_core_dcl void ic_call icInsertionSortLess##suffix   (Type* bg, Type* ed) ic_noexc; \
        ic_core_dcl void ic_call icInsertionSortGreater##suffix(Type* bg, Type* ed) ic_noexc; \
        ic_inl      void ic_call icInsertionSort##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
    ic_macro_x4_param_x2(Dcl_icInsertionSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dcl_icInsertionSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dcl_icInsertionSort_m, F32, flo32_t, F64, flo64_t);
    #undef Dcl_icInsertionSort_m
    ic_core_dcl void ic_call icInsertionSortObj(void* bg, void* ed, size_t btSzOfObj, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;

ic_info("inl: insertionSort")
    #define Inl_icInsertionSort_m(suffix, Type) \
        ic_inl void ic_call icInsertionSort##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
            ic_if_else_do(bGreater, icInsertionSortGreater##suffix(bg, ed), icInsertionSortLess##suffix(bg, ed)); \
        }
    ic_macro_x4_param_x2(Inl_icInsertionSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Inl_icInsertionSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Inl_icInsertionSort_m, F32, flo32_t, F64, flo64_t);
    #undef Inl_icInsertionSort_m