
#pragma once

#include"../../Common/icCoreCommon.h"
#include"../Enums/icCoreStringEnums.h"

ic_info("decs", "hexadecimal")
    ic_core_dcl ch8_p  ic_call ichexU32ToS8 (ch8_p  dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call ichexU64ToS8 (ch8_p  dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call ichexU32ToS16(ch16_p dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call ichexU64ToS16(ch16_p dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call ichexU32ToS32(ch32_p dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call ichexU64ToS32(ch32_p dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;

    ic_core_dcl ch8_p  ic_call ichexI32ToS8 (ch8_p  dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call ichexI64ToS8 (ch8_p  dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call ichexI32ToS16(ch16_p dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call ichexI64ToS16(ch16_p dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call ichexI32ToS32(ch32_p dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call ichexI64ToS32(ch32_p dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc;