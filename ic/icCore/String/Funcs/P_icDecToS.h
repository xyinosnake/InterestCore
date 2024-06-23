
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs", "decimal")
    ic_core_dcl ch8_p  ic_call icDecU32ToS8 (ch8_p  dst, uint32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icDecU64ToS8 (ch8_p  dst, uint64_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icDecU32ToS16(ch16_p dst, uint32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icDecU64ToS16(ch16_p dst, uint64_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icDecU32ToS32(ch32_p dst, uint32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icDecU64ToS32(ch32_p dst, uint64_t value, bool WritePositiveSign) ic_noexc;

    ic_core_dcl ch8_p  ic_call icDecI32ToS8 (ch8_p  dst, int32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icDecI64ToS8 (ch8_p  dst, int64_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icDecI32ToS16(ch16_p dst, int32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icDecI64ToS16(ch16_p dst, int64_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icDecI32ToS32(ch32_p dst, int32_t value, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icDecI64ToS32(ch32_p dst, int64_t value, bool WritePositiveSign) ic_noexc;