
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs")
    ic_info("decs: icPushHeapByIndex")
        #define Dcl_icPushHeapByIndex_m(suffix, Type) \
            ic_core_dcl void ic_call icPushHeapByIndexLess##suffix   (Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc; \
            ic_core_dcl void ic_call icPushHeapByIndexGreater##suffix(Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc; \
            ic_inl      void ic_call icPushHeapByIndex##suffix(bool bGreater, Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc
        ic_macro_x4_param_x2(Dcl_icPushHeapByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icPushHeapByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icPushHeapByIndex_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icPushHeapByIndex_m
        ic_core_dcl void ic_call icPushHeapByIndexObj(void_p bg, size_t btSzOfObj, ptrdiff_t hole, ptrdiff_t top, cvoid_p pVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;

    ic_info("decs: icPushHeap")
        #define Dcl_icPushHeap_m(suffix, Type) \
            ic_inl void ic_call icPushHeapLess##suffix   (Type* bg, Type* ed) ic_noexc; \
            ic_inl void ic_call icPushHeapGreater##suffix(Type* bg, Type* ed) ic_noexc; \
            ic_inl void ic_call icPushHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icPushHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icPushHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icPushHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icPushHeap_m
        ic_inl void ic_call icPushHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;

ic_info("inl")
    ic_info("inl: icPushHeapByIndex")
        #define Inl_icPushHeapByIndex_m(suffix, Type) \
            ic_inl void ic_call icPushHeapByIndex##suffix(bool bGreater, Type* bg, ptrdiff_t hole, ptrdiff_t top, Type val) ic_noexc { \
                ic_if_else_do(bGreater, icPushHeapByIndexGreater##suffix(bg, hole, top, val), icPushHeapByIndexLess##suffix(bg, hole, top, val)); \
            }
        ic_macro_x4_param_x2(Inl_icPushHeapByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icPushHeapByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icPushHeapByIndex_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icPushHeapByIndex_m

    ic_info("inl: icPushHeap")
        #define icPushHeap_m(func)              ic_init_if_do(ptrdiff_t sz = ed - bg, sz >= 2, func(bg, --sz, 0, *--ed))
        #define Inl_icPushHeap_m(suffix, Type) \
            ic_inl void ic_call icPushHeapLess##suffix   (Type* bg, Type* ed) ic_noexc { icPushHeap_m(icPushHeapByIndexLess##suffix);    } \
            ic_inl void ic_call icPushHeapGreater##suffix(Type* bg, Type* ed) ic_noexc { icPushHeap_m(icPushHeapByIndexGreater##suffix); } \
            ic_inl void ic_call icPushHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
                ic_if_else_do(bGreater, icPushHeapGreater##suffix(bg, ed), icPushHeapLess##suffix(bg, ed)); \
            }
        ic_macro_x4_param_x2(Inl_icPushHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icPushHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icPushHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icPushHeap_m
        #undef icPushHeap_m
        ic_inl void ic_call icPushHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            ic_init_if_do_x2(ptrdiff_t sz = icObjPtrDiff(bg, ed, btSzOfObj), 2 <= sz, 
                fAssign(pInitedTempVal, icSubPtr(ed, btSzOfObj)),
                icPushHeapByIndexObj(bg, btSzOfObj, --sz, 0, pInitedTempVal, fCmp, fAssign));
        }