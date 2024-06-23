
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs")
    ic_info("decs: icPopHeapHoleByIndex")
        #define Dcl_icPopHeapHoleByIndex_m(suffix, Type) \
            ic_core_dcl void ic_call icPopHeapHoleByIndexLess##suffix   (Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc; \
            ic_core_dcl void ic_call icPopHeapHoleByIndexGreater##suffix(Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc; \
            ic_inl      void ic_call icPopHeapHoleByIndex##suffix(bool bGreater, Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc
        ic_macro_x4_param_x2(Dcl_icPopHeapHoleByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icPopHeapHoleByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icPopHeapHoleByIndex_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icPopHeapHoleByIndex_m
        ic_core_dcl void ic_call icPopHeapHoleByIndexObj(void_p bg, size_t btSzOfObj, ptrdiff_t hole, ptrdiff_t bottom, cvoid_p pVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;
    
    ic_info("decs: icPopHeap")
        #define Dcl_icPopHeap_m(suffix, Type) \
            ic_inl void ic_call icPopHeapLess##suffix   (Type* bg, Type* ed) ic_noexc; \
            ic_inl void ic_call icPopHeapGreater##suffix(Type* bg, Type* ed) ic_noexc; \
            ic_inl void ic_call icPopHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc
        ic_macro_x4_param_x2(Dcl_icPopHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Dcl_icPopHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Dcl_icPopHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Dcl_icPopHeap_m
        ic_inl void ic_call icPopHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;

ic_info("inl")
    ic_info("inl: icPopHeapHoleByIndex")
        #define Inl_icPopHeapHoleByIndex_m(suffix, Type) \
            ic_inl void ic_call icPopHeapHoleByIndex##suffix(bool bGreater, Type* bg, ptrdiff_t hole, ptrdiff_t bottom, Type val) ic_noexc { \
                ic_if_else_do(bGreater, icPopHeapHoleByIndexGreater##suffix(bg, hole, bottom, val), icPopHeapHoleByIndexLess##suffix(bg, hole, bottom, val)); \
            }
        ic_macro_x4_param_x2(Inl_icPopHeapHoleByIndex_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icPopHeapHoleByIndex_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icPopHeapHoleByIndex_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icPopHeapHoleByIndex_m
    
    ic_info("inl: icPopHeap")
        #define icPopHeap_m(Type, func)   ic_init_if_do_x3(ptrdiff_t sz = ed - bg, sz >= 2, Type tempVal = *--ed, *ed = *bg, func(bg, 0, --sz, tempVal))
        #define Inl_icPopHeap_m(suffix, Type) \
            ic_inl void ic_call icPopHeapLess##suffix   (Type* bg, Type* ed) ic_noexc { icPopHeap_m(Type, icPopHeapHoleByIndexLess##suffix);    } \
            ic_inl void ic_call icPopHeapGreater##suffix(Type* bg, Type* ed) ic_noexc { icPopHeap_m(Type, icPopHeapHoleByIndexGreater##suffix); } \
            ic_inl void ic_call icPopHeap##suffix(bool bGreater, Type* bg, Type* ed) ic_noexc { \
                ic_if_else_do(bGreater, icPushHeapGreater##suffix(bg, ed), icPushHeapLess##suffix(bg, ed)); \
            }
        ic_macro_x4_param_x2(Inl_icPopHeap_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
        ic_macro_x4_param_x2(Inl_icPopHeap_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
        ic_macro_x2_param_x2(Inl_icPopHeap_m, F32, flo32_t, F64, flo64_t);
        #undef Inl_icPopHeap_m
        #undef icPopHeap_m
        ic_inl void ic_call icPopHeapObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            ic_init_if_do_x3(ptrdiff_t sz = icObjPtrDiff(bg, ed, btSzOfObj), sz >= 2,
                fAssign(pInitedTempVal, ed = icSubObjPtr(ed, 1, btSzOfObj)), fAssign(ed, bg), icPopHeapHoleByIndexObj(bg, btSzOfObj, 0, --sz, pInitedTempVal, fCmp, fAssign));
        }