
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: icSortHeap")
    #define Dcl_icSortHeap_m(suffix, Type) \
        ic_core_dcl void ic_call icSortHeapLess##suffix   (Type* bg, Type* ed) ic_noexc; \
        ic_core_dcl void ic_call icSortHeapGreater##suffix(Type* bg, Type* ed) ic_noexc; \
        ic_inl      void ic_call icSortHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
    ic_macro_x4_param_x2(Dcl_icSortHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Dcl_icSortHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Dcl_icSortHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Dcl_icSortHeap_m
    ic_core_dcl void ic_call icSortHeapObj(void* bg, void* ed, size_t btSzOfObj, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;


ic_info("inl: icSortHeap")
    #define Inl_icSortHeap_m(suffix, Type) \
        ic_inl void ic_call icSortHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
            ic_if_else_do(bGreater, icSortHeapGreater##suffix(bg, ed), icSortHeapLess##suffix(bg, ed)); \
        }
    ic_macro_x4_param_x2(Inl_icSortHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
    ic_macro_x4_param_x2(Inl_icSortHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
    ic_macro_x2_param_x2(Inl_icSortHeap_m, F32, flo32_t, F64, flo64_t);
    #undef Inl_icSortHeap_m