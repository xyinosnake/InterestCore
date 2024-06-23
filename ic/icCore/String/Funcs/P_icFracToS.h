
#pragma once

#include"../../Common/icCoreCommon.h"
#include"../Enums/icCoreStringEnums.h"

ic_info("decs")
    ic_core_dcl ch8_p  ic_call icFrac64ToS8  (ch8_p  dst, int32_t num, int32_t den, ic_frac_str_fmt_e eStyle) ic_noexc;
    ic_core_dcl ch8_p  ic_call icFrac128ToS8 (ch8_p  dst, int64_t num, int64_t den, ic_frac_str_fmt_e eStyle) ic_noexc;
    ic_core_dcl ch16_p ic_call icFrac64ToS16 (ch16_p dst, int32_t num, int32_t den, ic_frac_str_fmt_e eStyle) ic_noexc;
    ic_core_dcl ch16_p ic_call icFrac128ToS16(ch16_p dst, int64_t num, int64_t den, ic_frac_str_fmt_e eStyle) ic_noexc;
    ic_core_dcl ch32_p ic_call icFrac64ToS32 (ch32_p dst, int32_t num, int32_t den, ic_frac_str_fmt_e eStyle) ic_noexc;
    ic_core_dcl ch32_p ic_call icFrac128ToS32(ch32_p dst, int64_t num, int64_t den, ic_frac_str_fmt_e eStyle) ic_noexc;