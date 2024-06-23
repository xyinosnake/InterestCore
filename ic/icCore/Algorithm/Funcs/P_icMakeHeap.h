
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: icMakeHeap")
    #define Dcl_icMakeHeap_m(suffix, Type) \
        ic_core_dcl void ic_call icMakeHeapLess##suffix   (Type* bg, Type* ed) ic_noexc; \
        ic_core_dcl void ic_call icMakeHeapGreater##suffix(Type* bg, Type* ed) ic_noexc; \
        ic_inl      void ic_call icMakeHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
    ic_macro_x4_param_x2(Dcl_icMakeHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dcl_icMakeHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dcl_icMakeHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Dcl_icMakeHeap_m
    ic_core_dcl void ic_call icMakeHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;

ic_info("inl: icMakeHeap")
    #define Inl_icMakeHeap_m(suffix, Type) \
        ic_inl void ic_call icMakeHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
            ic_if_else_do(bGreater, icMakeHeapGreater##suffix(bg, ed), icMakeHeapLess##suffix(bg, ed)); \
        }
    ic_macro_x4_param_x2(Inl_icMakeHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Inl_icMakeHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Inl_icMakeHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Inl_icMakeHeap_m