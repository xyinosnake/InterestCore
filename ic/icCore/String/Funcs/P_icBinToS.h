
#pragma once

#include"../../Common/icCoreCommon.h"
#include"../Enums/icCoreStringEnums.h"

ic_info("binary")
    ic_core_dcl ch8_p  ic_call icBinU32ToS8 (ch8_p  dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icBinU64ToS8 (ch8_p  dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icBinU32ToS16(ch16_p dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icBinU64ToS16(ch16_p dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icBinU32ToS32(ch32_p dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icBinU64ToS32(ch32_p dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;

    ic_core_dcl ch8_p  ic_call icBinI32ToS8 (ch8_p  dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icBinI64ToS8 (ch8_p  dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icBinI32ToS16(ch16_p dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icBinI64ToS16(ch16_p dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icBinI32ToS32(ch32_p dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icBinI64ToS32(ch32_p dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;