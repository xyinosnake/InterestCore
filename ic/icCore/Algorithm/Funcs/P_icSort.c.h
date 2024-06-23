
#pragma once

#include"./P_icSort.h"
#include"./P_icInsertionSort.h"
#include"./P_icMakeHeap.h"
#include"./P_icSortHeap.h"

ic_info("defs")
    ic_info("defs: H_icMed3")
        #define H_icMed3_m(Type, opt) \
            ic_if_do(*mid opt *bg, ic_swap_ptr(Type, mid, bg)); \
            ic_if_do_x2(*ed opt *mid, ic_swap_ptr(Type, ed, mid), ic_if_do(*mid opt *bg, ic_swap_ptr(Type, mid, bg)))
        #define Dfn_H_icMed3_m(suffix, Type) \
            ic_hide void ic_call H_icMed3Less##suffix   (Type* bg, Type* mid, Type* ed) ic_noexc { H_icMed3_m(Type, <); } \
            ic_hide void ic_call H_icMed3Greater##suffix(Type* bg, Type* mid, Type* ed) ic_noexc { H_icMed3_m(Type, >); }
            ic_macro_x4_param_x2(Dfn_H_icMed3_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
            ic_macro_x4_param_x2(Dfn_H_icMed3_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
            ic_macro_x2_param_x2(Dfn_H_icMed3_m, F32, flo32_t, F64, flo64_t);
        #undef Dfn_H_icMed3_m
        #undef H_icMed3_m
        ic_hide void ic_call H_icMed3Obj(void_p bg, void_p mid, void_p ed, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            ic_if_do(fCmp(mid, bg), ic_swap_obj(pInitedTempVal, mid, bg, fAssign));
            ic_if_do_x2(fCmp(ed, mid), ic_swap_obj(pInitedTempVal, ed, mid, fAssign), ic_if_do(fCmp(mid, bg), ic_swap_obj(pInitedTempVal, mid, bg, fAssign)));
        }

    ic_info("defs: H_icGuessMedian")
        #define H_icGuessMedian_m(Type, opt, func) \
            ic_init_if(ptrdiff_t sz = ed - bg, sz > 40) { \
                ic_stv_x2(ptrdiff_t, step1 = (sz + 1) >> 3, step2 = step1 << 1); \
                func(bg, bg + step1, bg + step2); \
                func(mid - step1, mid, mid + step1); \
                func(ed - step2, ed - step1, ed); \
                func(bg + step1, mid, ed - step1); \
            } ic_else_do(func(bg, mid, ed))
        #define Dfn_H_icGuessMedian_m(suffix, Type) \
            ic_hide void ic_call H_icGuessMedianLess##suffix   (Type* bg, Type* mid, Type* ed) ic_noexc { H_icGuessMedian_m(Type, <, H_icMed3Less##suffix);    } \
            ic_hide void ic_call H_icGuessMedianGreater##suffix(Type* bg, Type* mid, Type* ed) ic_noexc { H_icGuessMedian_m(Type, >, H_icMed3Greater##suffix); }
            ic_macro_x4_param_x2(Dfn_H_icGuessMedian_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
            ic_macro_x4_param_x2(Dfn_H_icGuessMedian_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
            ic_macro_x2_param_x2(Dfn_H_icGuessMedian_m, F32, flo32_t, F64, flo64_t);
        #undef Dfn_H_icGuessMedian_m
        #undef H_icGuessMedian_m
        ic_hide void ic_call H_icGuessMedianObj(void_p bg, void_p mid, void_p ed, size_t btSzOfObj, void* pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            ic_init_if(ptrdiff_t sz = icObjPtrDiff(bg, ed, btSzOfObj), sz > 40) {
                ic_stv_x2(ptrdiff_t, step1 = (sz + 1) >> 3, step2 = step1 << 1);
                H_icMed3Obj(bg, icAddObjPtr(bg, step1, btSzOfObj), icAddObjPtr(bg, step2, btSzOfObj), pInitedTempVal, fCmp, fAssign);
                H_icMed3Obj(icSubObjPtr(mid, step1, btSzOfObj), mid, icAddObjPtr(mid, step1, btSzOfObj), pInitedTempVal, fCmp, fAssign);
                H_icMed3Obj(icSubObjPtr(ed, step2, btSzOfObj), icSubObjPtr(ed, step1, btSzOfObj), ed, pInitedTempVal, fCmp, fAssign);
                H_icMed3Obj(icAddObjPtr(bg, step1, btSzOfObj), mid, icSubObjPtr(ed, step1, btSzOfObj), pInitedTempVal, fCmp, fAssign);
            } ic_else_do(H_icMed3Obj(bg, mid, ed, pInitedTempVal, fCmp, fAssign))
        }

    ic_info("defs: H_icPartitionByMedianGuess")
        #define H_icPartitionByMedianGuess_m(Type, opt, func) \
            ic_stv_x3(Type*, mid = bg + ((ed - bg) >> 1), pbg = mid, ped = pbg + 1); \
            func(bg, mid, ed - 1); \
            ic_while_do(bg < pbg && !(*(pbg - 1) opt *pbg) && !(*pbg opt *(pbg - 1)), --pbg); \
            ic_while_do(ped < ed && !(*ped opt *pbg) && !(*pbg opt *ped), ++ped); \
            ic_stv_x2(Type*, gbg = ped, ged = pbg); \
            for (;;) { \
                for (; gbg < ed; ++gbg) { \
                         ic_if_continue(*pbg opt *gbg) \
                    else ic_if_break(*gbg opt *pbg) \
                    else ic_if_do_x2(ped != gbg, ic_swap_ptr(Type, ped, gbg), ++ped) \
                         ic_else_do(++ped) \
                } \
                for (; bg < ged; --ged) { \
                         ic_if_continue(*(ged - 1) opt *pbg) \
                    else ic_if_break(*pbg opt *(ged - 1)) \
                    else ic_if_do_x2(--pbg != (ged - 1), Type* pTemp = ged - 1, ic_swap_ptr(Type, pbg, pTemp)) \
                } \
                ic_if_do_and_return(ged == bg && gbg == ed, *ppLeft = pbg, ped); \
                     ic_if_do_x3(ged == bg, ic_if_do(ped != gbg, ic_swap_ptr(Type, pbg, ped)),  \
                        ic_swap_ptr(Type, pbg, gbg), ic_inc_x3(ped, pbg, gbg)) \
                else ic_if_do_x3(gbg == ed, ic_if_do(--ged != --pbg, ic_swap_ptr(Type, ged, pbg)),  \
                        --ped, ic_swap_ptr(Type, pbg, ped)) \
                     ic_else_do_x3(--ged, ic_swap_ptr(Type, gbg, ged), ++gbg); \
            }
        #define Dfn_H_icPartitionByMedianGuess_m(suffix, Type) \
            ic_hide Type* ic_call H_icPartitionByMedianGuessLess##suffix   (Type** ppLeft, Type* bg, Type* ed) ic_noexc { H_icPartitionByMedianGuess_m(Type, <, H_icGuessMedianLess##suffix);    } \
            ic_hide Type* ic_call H_icPartitionByMedianGuessGreater##suffix(Type** ppLeft, Type* bg, Type* ed) ic_noexc { H_icPartitionByMedianGuess_m(Type, >, H_icGuessMedianGreater##suffix); }
            ic_macro_x4_param_x2(Dfn_H_icPartitionByMedianGuess_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
            ic_macro_x4_param_x2(Dfn_H_icPartitionByMedianGuess_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
            ic_macro_x2_param_x2(Dfn_H_icPartitionByMedianGuess_m, F32, flo32_t, F64, flo64_t);
        #undef Dfn_H_icPartitionByMedianGuess_m
        #undef H_icPartitionByMedianGuess_m
        ic_hide void_p ic_call H_icPartitionByMedianGuessObj(void** ppLeft, void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            ic_stv_x3(void_p, mid = icAddObjPtr(bg, (icObjPtrDiff(bg, ed, btSzOfObj) >> 1), btSzOfObj), pbg = mid, ped = icAddObjPtr(pbg, 1, btSzOfObj));
            H_icGuessMedianObj(bg, mid, icSubObjPtr(ed, 1, btSzOfObj), btSzOfObj, pInitedTempVal, fCmp, fAssign);
            ic_while_do(bg < pbg && !fCmp(icSubObjPtr(pbg, 1, btSzOfObj), pbg) && !fCmp(pbg, icSubObjPtr(pbg, 1, btSzOfObj)), pbg = icSubObjPtr(pbg, 1, btSzOfObj));
            ic_while_do(ped < ed && !fCmp(ped, pbg) && !fCmp(pbg, ped), ped = icAddObjPtr(ped, 1, btSzOfObj));
            ic_stv_x2(void_p, gbg = ped, ged = pbg);
            for (;;) {
                for (; gbg < ed; gbg = icAddObjPtr(gbg, 1, btSzOfObj)) {
                         ic_if_continue(fCmp(pbg, gbg))
                    else ic_if_break(fCmp(gbg, pbg))
                    else ic_if_do_x2(ped != gbg, ic_swap_obj(pInitedTempVal, ped, gbg, fAssign), ped = icAddObjPtr(ped, 1, btSzOfObj))
                         ic_else_do(ped = icAddObjPtr(ped, 1, btSzOfObj))
                }
                for (; bg < ged; ged = icSubObjPtr(ged, 1, btSzOfObj)) {
                         ic_if_continue(fCmp(icSubObjPtr(ged, 1, btSzOfObj), pbg))
                    else ic_if_break(fCmp(pbg, icSubObjPtr(ged, 1, btSzOfObj)))
                    else ic_if_do_x2((pbg = icSubObjPtr(pbg, 1, btSzOfObj)) != icSubObjPtr(ged, 1, btSzOfObj), 
                        void_p pTemp = icSubObjPtr(ged, 1, btSzOfObj), ic_swap_obj(pInitedTempVal, pbg, pTemp, fAssign))
                }
                ic_if_do_and_return(ged == bg && gbg == ed, *ppLeft = pbg, ped);
                     ic_if_do_x3(ged == bg, ic_if_do(ped != gbg, ic_swap_obj(pInitedTempVal, pbg, ped, fAssign)),
                        ic_swap_obj(pInitedTempVal, pbg, gbg, fAssign), ic_do_x3(ped = icAddObjPtr(ped, 1, btSzOfObj), pbg = icAddObjPtr(pbg, 1, btSzOfObj), gbg = icAddObjPtr(gbg, 1, btSzOfObj)))
                else ic_if_do_x3(gbg == ed, ic_if_do((ged = icSubObjPtr(ged, 1, btSzOfObj)) != (pbg = icSubObjPtr(pbg, 1, btSzOfObj)), ic_swap_obj(pInitedTempVal, ged, pbg, fAssign)), 
                        ped = icSubObjPtr(ped, 1, btSzOfObj), ic_swap_obj(pInitedTempVal, pbg, ped, fAssign))
                     ic_else_do_x3(ged = icSubObjPtr(ged, 1, btSzOfObj), ic_swap_obj(pInitedTempVal, gbg, ged, fAssign), gbg = icAddObjPtr(gbg, 1, btSzOfObj));
            }
        }

    ic_info("defs: H_icSort")
        #define H_icSort_m(Type, InsertionSort_f, MakeHeap_f, SortHeap_f, H_ParByMB_f, H_Sort_f, opt) \
            for (;;) { \
                ic_if_do_and_return(ed - bg <= 32, InsertionSort_f(bg, ed), ic_nothing); /* small */ \
                ic_if_do_x2_and_return(ideal <= 0, MakeHeap_f(bg, ed), SortHeap_f(bg, ed), ic_nothing); /* heap sort if too many divisions */ \
                ic_stv_x2(Type*, left, right); /* divide and conquer by quicksort */ \
                right = H_ParByMB_f(&left, bg, ed); \
                ideal = (ideal >> 1) + (ideal >> 2); /* allow 1.5 log2(N) divisions */ \
                ic_if_do_x2((left - bg) < (ed - right), H_Sort_f(bg, left, ideal), bg = right) /* loop on second half */ \
                ic_else_do_x2(H_Sort_f(right, ed, ideal), ed = left) /* loop on first half */ \
            }
        #define Dfn_H_icSort_m(suffix, Type) \
            ic_hide void ic_call H_icSortLess##suffix   (Type* bg, Type* ed, ptrdiff_t ideal) ic_noexc { H_icSort_m(Type, icInsertionSortLess##suffix,    icMakeHeapLess##suffix,    icSortHeapLess##suffix,    H_icPartitionByMedianGuessLess##suffix,    H_icSortLess##suffix,    <); } \
            ic_hide void ic_call H_icSortGreater##suffix(Type* bg, Type* ed, ptrdiff_t ideal) ic_noexc { H_icSort_m(Type, icInsertionSortGreater##suffix, icMakeHeapGreater##suffix, icSortHeapGreater##suffix, H_icPartitionByMedianGuessGreater##suffix, H_icSortGreater##suffix, >); }
            ic_macro_x4_param_x2(Dfn_H_icSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
            ic_macro_x4_param_x2(Dfn_H_icSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
            ic_macro_x2_param_x2(Dfn_H_icSort_m, F32, flo32_t, F64, flo64_t);
        #undef Dfn_H_icSort_m
        #undef H_icSort_m        
        ic_hide void ic_call H_icSortObj(void_p bg, void_p ed, ptrdiff_t ideal, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            for (;;) {
                ic_if_do_and_return(icObjPtrDiff(bg, ed, btSzOfObj) <= 32, icInsertionSortObj(bg, ed, btSzOfObj, pInitedTempVal, fCmp, fAssign), ic_nothing); /* small */                
                ic_if_do_x2_and_return(ideal <= 0, icMakeHeapObj(bg, ed, btSzOfObj, pInitedTempVal, fCmp, fAssign), icSortHeapObj(bg, ed, btSzOfObj, pInitedTempVal, fCmp, fAssign), ic_nothing); /* heap sort if too many divisions */
                ic_stv_x2(void_p, left, right); /* divide and conquer by quicksort */
                right = H_icPartitionByMedianGuessObj(&left, bg, ed, btSzOfObj, pInitedTempVal, fCmp, fAssign);
                ideal = (ideal >> 1) + (ideal >> 2); /* allow 1.5 log2(N) divisions */
                ic_if_do_x2(icObjPtrDiff(bg, left, btSzOfObj) < icObjPtrDiff(right, ed, btSzOfObj),
                    H_icSortObj(bg, left, ideal, btSzOfObj, pInitedTempVal, fCmp, fAssign), bg = right) /* loop on second half */
                ic_else_do_x2(H_icSortObj(right, ed, ideal, btSzOfObj, pInitedTempVal, fCmp, fAssign), ed = left) /* loop on first half */
            }
        }

    ic_info("defs: icSort")
        #define Dfn_icSort_m(suffix, Type) \
            ic_core_dcl void ic_call icSortLess##suffix   (Type* bg, Type* ed) ic_noexc { H_icSortLess##suffix   (bg, ed, ed - bg); } \
            ic_core_dcl void ic_call icSortGreater##suffix(Type* bg, Type* ed) ic_noexc { H_icSortGreater##suffix(bg, ed, ed - bg); }
            ic_macro_x4_param_x2(Dfn_icSort_m, U8,  uint8_t, U16, uint16_t, U32, uint32_t, U64, uint64_t);
            ic_macro_x4_param_x2(Dfn_icSort_m, I8,   int8_t, I16,  int16_t, I32,  int32_t, I64,  int64_t);
            ic_macro_x2_param_x2(Dfn_icSort_m, F32, flo32_t, F64, flo64_t);
        #undef Dfn_icSort_m
        ic_core_dcl void ic_call icSortObj(void_p bg, void_p ed, size_t btSzOfObj, void_p pInitedTempVal, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc {
            H_icSortObj(bg, ed, icObjPtrDiff(bg, ed, btSzOfObj), btSzOfObj, pInitedTempVal, fCmp, fAssign);
        }