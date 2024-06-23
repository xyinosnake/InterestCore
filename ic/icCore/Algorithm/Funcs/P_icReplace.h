
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: ReplaceVal")
    ic_core_dcl size_t ic_call icReplaceVal8 (int8_p  bg, int8_p  ed, int8_t  oldVal, int8_t  newVal) ic_noexc;
    ic_core_dcl size_t ic_call icReplaceVal16(int16_p bg, int16_p ed, int16_t oldVal, int16_t newVal) ic_noexc;
    ic_core_dcl size_t ic_call icReplaceVal32(int32_p bg, int32_p ed, int32_t oldVal, int32_t newVal) ic_noexc;
    ic_core_dcl size_t ic_call icReplaceVal64(int64_p bg, int64_p ed, int64_t oldVal, int64_t newVal) ic_noexc;
    ic_core_dcl size_t ic_call icReplaceObj(void_p bg, void_p ed, size_t btSzOfObj, cvoid_p pOldObj, cvoid_p pNewObj, ic_compare_f fCmp, ic_assign_f fAssign) ic_noexc;