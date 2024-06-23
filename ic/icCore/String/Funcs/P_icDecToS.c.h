
#pragma once

#include"./P_icDecToS.h"

ic_info("defs", "decimal")
    ic_core_dcl ch8_p ic_call icDecU32ToS8(ch8_p dst, uint32_t value, bool WritePositiveSign) ic_noexc {
        return icU32ToS8(dst, value, icGetRS8(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch8_p ic_call icDecU64ToS8(ch8_p dst, uint64_t value, bool WritePositiveSign) ic_noexc {
        return icU64ToS8(dst, value, icGetRS8(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch16_p ic_call icDecU32ToS16(ch16_p dst, uint32_t value, bool WritePositiveSign) ic_noexc {
        return icU32ToS16(dst, value, icGetRS16(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch16_p ic_call icDecU64ToS16(ch16_p dst, uint64_t value, bool WritePositiveSign) ic_noexc {
        return icU64ToS16(dst, value, icGetRS16(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch32_p ic_call icDecU32ToS32(ch32_p dst, uint32_t value, bool WritePositiveSign) ic_noexc {
        return icU32ToS32(dst, value, icGetRS32(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch32_p ic_call icDecU64ToS32(ch32_p dst, uint64_t value, bool WritePositiveSign) ic_noexc {
        return icU64ToS32(dst, value, icGetRS32(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch8_p ic_call icDecI32ToS8(ch8_p dst, int32_t value, bool WritePositiveSign) ic_noexc {
        return icI32ToS8(dst, value, icGetRS8(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch8_p ic_call icDecI64ToS8(ch8_p dst, int64_t value, bool WritePositiveSign) ic_noexc {
        return icI64ToS8(dst, value, icGetRS8(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch16_p ic_call icDecI32ToS16(ch16_p dst, int32_t value, bool WritePositiveSign) ic_noexc {
        return icI32ToS16(dst, value, icGetRS16(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch16_p ic_call icDecI64ToS16(ch16_p dst, int64_t value, bool WritePositiveSign) ic_noexc {
        return icI64ToS16(dst, value, icGetRS16(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch32_p ic_call icDecI32ToS32(ch32_p dst, int32_t value, bool WritePositiveSign) ic_noexc {
        return icI32ToS32(dst, value, icGetRS32(), 10, 0, 0, 0, WritePositiveSign);
    }

    ic_core_dcl ch32_p ic_call icDecI64ToS32(ch32_p dst, int64_t value, bool WritePositiveSign) ic_noexc {
        return icI64ToS32(dst, value, icGetRS32(), 10, 0, 0, 0, WritePositiveSign);
    }