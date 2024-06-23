
#pragma once
 
#include"./P_icPmtToS.h"
#include"../../Memory/Funcs/icCoreMemoryFuncs.h"

ic_info("defs")
    #define icPmtUXXToSX_m(char_xt, uint_xt) \
        char_xt  buf[sizeof(uint_xt) * 8];\
        char_xt* bufEd = buf + 8 * sizeof(uint_xt);\
        char_xt* bufIt = bufEd;\
        char_xt* tmnBG = bufEd - iDigits;\
        uint_xt  rNum  = (uint_xt)iRNum;\
        char_xt  zr;\
        ic_do_x2_while(*(--bufIt) = radix[value % rNum], value /= rNum, value);\
        zr = radix[0]; \
        ic_while_do_return(--bufIt >= tmnBG, *bufIt = zr, (char_xt*)icCopyMem(dst, ++bufIt, bufEd))

    ic_core_dcl ch8_p ic_call icPmtU32ToS8(ch8_p dst, uint32_t value, cch8_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch8_t, uint32_t);
    }

    ic_core_dcl ch8_p ic_call icPmtU64ToS8(ch8_p dst, uint64_t value, cch8_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch8_t, uint64_t);
    }

    ic_core_dcl ch16_p ic_call icPmtU32ToS16(ch16_p dst, uint32_t value, cch16_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch16_t, uint32_t);
    }

    ic_core_dcl ch16_p ic_call icPmtU64ToS16(ch16_p dst, uint64_t value, cch16_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch16_t, uint64_t);
    }

    ic_core_dcl ch32_p ic_call icPmtU32ToS32(ch32_p dst, uint32_t value, cch32_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch32_t, uint32_t);
    }

    ic_core_dcl ch32_p ic_call icPmtU64ToS32(ch32_p dst, uint64_t value, cch32_p radix, size_t iRNum, size_t iDigits) ic_noexc {
        icPmtUXXToSX_m(ch32_t, uint64_t);
    }
    #undef icPmtUXXToSX_m

    #define icUXXToSX_m(char_xt, func_xv) \
        ic_if_do(WritePositiveSign, *dst++ = (char_xt)'+');\
        ic_if_do(prefix, dst = (char_xt*)icCopyMemSize(dst, prefix, sizeof(char_xt) * szOfPre));\
        return func_xv(dst, value, radix, iRNum, iDigits);

    ic_core_dcl ch8_p ic_call icU32ToS8(ch8_p dst, uint32_t value, cch8_p radix, size_t iRNum, size_t iDigits, cch8_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch8_t, icPmtU32ToS8);
    }

    ic_core_dcl ch8_p  ic_call icU64ToS8(ch8_p dst, uint64_t value, cch8_p radix, size_t iRNum, size_t iDigits, cch8_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch8_t, icPmtU64ToS8);
    }

    ic_core_dcl ch16_p ic_call icU32ToS16(ch16_p dst, uint32_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch16_t, icPmtU32ToS16);
    }

    ic_core_dcl ch16_p ic_call icU64ToS16(ch16_p dst, uint64_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch16_t, icPmtU64ToS16);
    }

    ic_core_dcl ch32_p ic_call icU32ToS32(ch32_p dst, uint32_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch32_t, icPmtU32ToS32);
    }

    ic_core_dcl ch32_p ic_call icU64ToS32(ch32_p dst, uint64_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icUXXToSX_m(ch32_t, icPmtU64ToS32);
    }
    #undef icUXXToSX_m

    #define icIXXToSX_m(uint_xt, char_xt, func_xv) \
        uint_xt uv;\
        ic_if_do_x2(value < 0, uv = (uint_xt)-value, *dst++ = (char_xt)'-')\
        ic_else_do_x2(uv = (uint_xt)value, ic_if_do(WritePositiveSign, *dst++ = (char_xt)'+'));\
        ic_if_do(prefix, dst = (char_xt*)icCopyMemSize(dst, prefix, sizeof(char_xt) * szOfPre));\
        return func_xv(dst, uv, radix, iRNum, iDigits)

    ic_core_dcl ch8_p ic_call icI32ToS8(ch8_p dst, int32_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint32_t, ch8_t, icPmtU32ToS8);
    }

    ic_core_dcl ch8_p ic_call icI64ToS8(ch8_p dst, int64_t value, cch8_p  radix, size_t iRNum, size_t iDigits, cch8_p  prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint64_t, ch8_t, icPmtU64ToS8);
    }

    ic_core_dcl ch16_p ic_call icI32ToS16(ch16_p dst, int32_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint32_t, ch16_t, icPmtU32ToS16);
    }

    ic_core_dcl ch16_p ic_call icI64ToS16(ch16_p dst, int64_t value, cch16_p radix, size_t iRNum, size_t iDigits, cch16_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint64_t, ch16_t, icPmtU64ToS16);
    }

    ic_core_dcl ch32_p ic_call icI32ToS32(ch32_p dst, int32_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint32_t, ch32_t, icPmtU32ToS32);
    }
    ic_core_dcl ch32_p ic_call icI64ToS32(ch32_p dst, int64_t value, cch32_p radix, size_t iRNum, size_t iDigits, cch32_p prefix, size_t szOfPre, bool WritePositiveSign) ic_noexc {
        icIXXToSX_m(uint64_t, ch32_t, icPmtU64ToS32);    
    }
    #undef icIXXToSX_m

#define icIXXToSX_m(flo_xt, return_x) \
    ch8_t  buf[64];\
    size_t n = (size_t)snprintf(buf, 64, "%g", value);\
    return return_x

    ic_core_dcl ch8_p ic_call icF32ToS8(ch8_p dst, flo32_t value) ic_noexc {
        icIXXToSX_m(flo32_t, (ch8_p)icCopyMemSize(dst, buf, sizeof(ch8_t) * n));
    }

    ic_core_dcl ch16_p ic_call icF32ToS16(ch16_p dst, flo32_t value) ic_noexc {
        icIXXToSX_m(flo32_t, icASCIIToUtf16(dst, buf, buf + n));
    }

    ic_core_dcl ch32_p ic_call icF32ToS32(ch32_p dst, flo32_t value) ic_noexc {
        icIXXToSX_m(flo32_t, icASCIIToUtf32(dst, buf, buf + n));
    }


    ic_core_dcl ch8_p ic_call icF64ToS8(ch8_p dst, flo64_t value) ic_noexc {
        icIXXToSX_m(flo64_t, (ch8_p)icCopyMemSize(dst, buf, sizeof(ch8_t) * n));
    }

    ic_core_dcl ch16_p ic_call icF64ToS16(ch16_p dst, flo64_t value) ic_noexc {
        icIXXToSX_m(flo64_t, icASCIIToUtf16(dst, buf, buf + n));
    }

    ic_core_dcl ch32_p ic_call icF64ToS32(ch32_p dst, flo64_t value) ic_noexc {
        icIXXToSX_m(flo64_t, icASCIIToUtf32(dst, buf, buf + n));
    }
#undef icIXXToSX_m