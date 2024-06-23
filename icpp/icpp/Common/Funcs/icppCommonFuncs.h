
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Funcs/icCommonFuncs.h"

ic_info("icppName & icppDep")
    #define icppName()        "icpp"
    #define icppNameColored() icCmdFgClr(96, 255, 255) icppName() icCmdFgClrReset()
    #if defined(IC_OS_WINDOWS)
        #define icppDep()         icppName() "(" icCoreDep() ", " icWin32Dep() ", " icDep() ")"
        #define icppDepColored()  icppNameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ", " icWin32DepColored() icCmdFgClr(64, 255, 64) icCmdFgClr(64, 255, 64) ", " icDepColored() icCmdFgClr(64, 255, 64) ")" icCmdFgClrReset()
    #elif defined(IC_OS_UNIX_LIKE)
        #define icppDep()         icppName() "(" icCoreDep() ", " icUnixDep() ")"
        #define icppDepColored()  icppNameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ", " icUnixDepColored() icCmdFgClr(64, 255, 64) icCmdFgClr(64, 255, 64) ", " icDepColored() icCmdFgClr(64, 255, 64) ")" icCmdFgClrReset()
    #endif

ic_info("declarations")
    icpp_dcl void ic_call icppHello(ic_hello_flags_e flags ic_dfv(ic_hf_default_v)) ic_noexc;

ic_info("in ns inl") icpp_ns_x1(icpp)
    ic_inl void ic_call hello() ic_noexc;
    icpp_t1(value_xt) ic_inl bool ic_call valInItv      (value_xt value, value_xt left, value_xt right) ic_noexc;
    icpp_t1(value_xt) ic_inl bool ic_call valInClosedItv(value_xt value, value_xt left, value_xt right) ic_noexc;
    icpp_t1(value_xt) ic_inl value_xt& ic_call setBits(value_xt& v, value_xt mask) ic_noexc;
    icpp_t1(value_xt) ic_inl value_xt& ic_call clearBits(value_xt& v, value_xt mask) ic_noexc;
    icpp_t1(value_xt) ic_inl value_xt& ic_call setOrClearBits(bool b, value_xt& v, value_xt mask) ic_noexc;
    icpp_t1(value_xt) ic_inl value_xt  ic_call getBits(value_xt v, value_xt mask) ic_noexc;
    icpp_t1(value_xt) ic_inl value_xt  ic_call getBit(value_xt v, value_xt mask) ic_noexc;
    icpp_t2(func_xf, srcFunc_xf)
    ic_inl func_xf   ic_call funcCast(srcFunc_xf f) ic_noexc;
    ic_inl ptrdiff_t ic_call ptrDiff (cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl size_t    ic_call ptrDiffU(cvoid_p bg, cvoid_p ed) ic_noexc;
    icpp_t1(ptr_xt) ic_inl ptr_xt ic_call addPtr(ptr_xt bg, ptrdiff_t btSz) ic_noexc;
    icpp_t1(ptr_xt) ic_inl ptr_xt ic_call subPtr(ptr_xt bg, ptrdiff_t btSz) ic_noexc;
    ic_inl ptrdiff_t ic_call objPtrDiff (cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc;
    ic_inl size_t    ic_call objPtrDiffU(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc;
    ic_inl void_p    ic_call addObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc;
    ic_inl void_p    ic_call subObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc;
    ic_inl flo32_t   ic_call binF32(uint32_t u) ic_noexc;
    ic_inl flo64_t   ic_call binF64(uint64_t u) ic_noexc;
    ic_inl ptrdiff_t ic_call lockedInc(volatile ptrdiff_t& refI) ic_noexc;
    ic_inl size_t    ic_call lockedIncU(volatile size_t& refU) ic_noexc;
    ic_inl ptrdiff_t ic_call lockedDec(volatile ptrdiff_t& refI) ic_noexc;
    ic_inl size_t    ic_call lockedDecU(volatile size_t& refU) ic_noexc;
    icpp_t2(Obj, ...Args) ic_inl void ic_call construct(Obj& obj, Args&&...args) ic_noexc;
    icpp_t1(Obj)          ic_inl void ic_call destruct(Obj& obj) ic_noexc;
    icpp_t2(Target, Obj)  ic_inl Target& as(Obj& obj) ic_noexc;
    icpp_t2(Target, Obj)  ic_inl const Target& as(const Obj& obj) ic_noexc;
icpp_end_ns_x1

#include"./P_icppBasicInlines.h"
