
#pragma once

#include"./icCoreStringFuncs.h"

ic_info("dcls", "Pmt means primitive.")
    ic_core_dcl ch8_p  ic_call icPmtU32ToS8 (ch8_p  dst, uint32_t value, cch8_p  radix, size_t iRNum, size_t iDigits) ic_noexc;
    ic_core_dcl ch8_p  ic_call icPmtU64ToS8 (ch8_p  dst, uint64_t value, cch8_p  radix, size_t iRNum, size_t iDigits) ic_noexc;
    ic_core_dcl ch16_p ic_call icPmtU32ToS16(ch16_p dst, uint32_t value, cch16_p radix, size_t iRNum, size_t iDigits) ic_noexc;
    ic_core_dcl ch16_p ic_call icPmtU64ToS16(ch16_p dst, uint64_t value, cch16_p radix, size_t iRNum, size_t iDigits) ic_noexc;
    ic_core_dcl ch32_p ic_call icPmtU32ToS32(ch32_p dst, uint32_t value, cch32_p radix, size_t iRNum, size_t iDigits) ic_noexc;
    ic_core_dcl ch32_p ic_call icPmtU64ToS32(ch32_p dst, uint64_t value, cch32_p radix, size_t iRNum, size_t iDigits) ic_noexc;

    ic_core_dcl ch8_p  ic_call icU32ToS8 (ch8_p  dst, uint32_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icU64ToS8 (ch8_p  dst, uint64_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icU32ToS16(ch16_p dst, uint32_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icU64ToS16(ch16_p dst, uint64_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icU32ToS32(ch32_p dst, uint32_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icU64ToS32(ch32_p dst, uint64_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;

    ic_core_dcl ch8_p  ic_call icI32ToS8 (ch8_p  dst, int32_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch8_p  ic_call icI64ToS8 (ch8_p  dst, int64_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icI32ToS16(ch16_p dst, int32_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch16_p ic_call icI64ToS16(ch16_p dst, int64_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icI32ToS32(ch32_p dst, int32_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;
    ic_core_dcl ch32_p ic_call icI64ToS32(ch32_p dst, int64_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc;

ic_info("F dcls", "F means floating point.", "Use snprintf and icASCIIToSXX.")
    ic_core_dcl ch8_p  ic_call icF32ToS8 (ch8_p  dst, flo32_t value) ic_noexc;
    ic_core_dcl ch16_p ic_call icF32ToS16(ch16_p dst, flo32_t value) ic_noexc;
    ic_core_dcl ch32_p ic_call icF32ToS32(ch32_p dst, flo32_t value) ic_noexc;
    ic_core_dcl ch8_p  ic_call icF64ToS8 (ch8_p  dst, flo64_t value) ic_noexc;
    ic_core_dcl ch16_p ic_call icF64ToS16(ch16_p dst, flo64_t value) ic_noexc;
    ic_core_dcl ch32_p ic_call icF64ToS32(ch32_p dst, flo64_t value) ic_noexc;