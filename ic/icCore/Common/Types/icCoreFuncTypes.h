
#pragma once

#include"./icCoreValueTypes.h"

ic_info("Func Types Decs")
    ic_dcl_f(ic_operate_f,   ic_call, void)(void_p pMem) ic_noexc;
    ic_dcl_f(ic_alloc_f,     ic_call, void_p)(size_t btSz) ic_noexc;
    ic_dcl_f(ic_realloc_f,   ic_call, void_p)(void_p pMem, size_t btSz) ic_noexc;
    ic_alias(ic_dealloc_f,   ic_operate_f);
    ic_alias(ic_construct_f, ic_operate_f);
    ic_alias(ic_destruct_f,  ic_operate_f);
    ic_dcl_f(ic_compare_f,   ic_call, bool)(cvoid_p pObjA, cvoid_p pObjB) ic_noexc;
    ic_dcl_f(ic_assign_f,    ic_call, void)(void_p pDstObj, cvoid_p pSrcObj) ic_noexc;
    ic_dcl_f(ic_thread_f,    ic_t_call, ic_thr_t)(void_p pParams) ic_noexc;

ic_info("Func Defs")
    #define ic_def_operate_f(FuncName, pObjMem)                        void  ic_call FuncName(void_p pObjMem) ic_noexc
    #define ic_def_alloc_f(FuncName, btSz)                             void_p ic_call FuncName(size_t btSz  ) ic_noexc
    #define ic_def_dealloc_f(FuncName, pMem)                           ic_def_operate_f(FuncName, pMem)
    #define ic_def_realloc_f(FuncName, pMem, btSz)                     void_p ic_call FuncName(void_p pMem, size_t btSz) ic_noexc
    #define ic_def_construct_f(FuncName, pMem)                         ic_def_operate_f(FuncName, pMem)
    #define ic_def_destruct_f(FuncName, pMem)                          ic_def_operate_f(FuncName, pMem)
    #define ic_def_compare_f(FuncName, pObjA, pObjB)                   bool ic_call FuncName(cvoid_p pObjA, cvoid_p pObjB) ic_noexc
    #define ic_def_compare_replace_f(FuncName, pObj, pOldObj, pNewObj) bool ic_call FuncName( void_p pObj,  cvoid_p pOldObj, cvoid_p pNewObj) ic_noexc
    #define ic_def_assign_f(FuncName, pDstObj, pSrcObj)                void ic_call FuncName(void_p pDstObj, cvoid_p pSrcObj) ic_noexc
    #define ic_def_thread_f(FuncName, pParams)                         ic_thr_t ic_t_call FuncName(void_p pParams) ic_noexc