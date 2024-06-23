
#pragma once

#include"./P_icBinToS.h"

ic_info("defs")
    ic_info("H...")
        ic_hide size_t ic_call H_icGetBinPByStyleS8 (const ch8_t**  ppDst, ic_bin_str_fmt_e eStyle) ic_noexc;
        ic_hide size_t ic_call H_icGetBinPByStyleS16(const ch16_t** ppDst, ic_bin_str_fmt_e eStyle) ic_noexc;
        ic_hide size_t ic_call H_icGetBinPByStyleS32(const ch32_t** ppDst, ic_bin_str_fmt_e eStyle) ic_noexc;

    #define H_icGetBinPByStyleS_m(char_xt, UC_PF, LC_PF) \
        size_t szPF;\
        ic_if_do_x2(eStyle & ic_bsf_NP_v, *ppDst = 0, szPF = 0)\
        ic_else_do_x2(*ppDst = (const char_xt*)((eStyle & ic_bsf_LP_v) ? LC_PF : UC_PF), szPF = 2)\
        return szPF;

    ic_hide size_t ic_call H_icGetBinPByStyleS8(const ch8_t** ppDst, ic_bin_str_fmt_e eStyle) ic_noexc {
        H_icGetBinPByStyleS_m(ch8_t, "0B", "0b");
    }

    ic_hide size_t ic_call H_icGetBinPByStyleS16(const ch16_t** ppDst, ic_bin_str_fmt_e eStyle) ic_noexc {
    #if /* defined(IC_LE) || */ !defined(IC_BE)
        #define UC_PF "\x30\x00\x42\x00"
        #define LC_PF "\x30\x00\x62\x00"
    #else
        #define UC_PF "\x00\x30\x00\x42"
        #define LC_PF "\x00\x30\x00\x62"
    #endif
        H_icGetBinPByStyleS_m(ch16_t, UC_PF, LC_PF);
    #undef UC_PF
    #undef LC_PF
    }

    ic_hide size_t ic_call H_icGetBinPByStyleS32(const ch32_t** ppDst, ic_bin_str_fmt_e eStyle) ic_noexc {
    #if /* defined(IC_LE) || */ !defined(IC_BE)
        #define UC_PF "\x30\x00\x00\x00\x42\x00\x00\x00"
        #define LC_PF "\x30\x00\x00\x00\x62\x00\x00\x00"
    #else
        #define UC_PF "\x00\x00\x00\x30\x00\x00\x00\x42"
        #define LC_PF "\x00\x00\x00\x30\x00\x00\x00\x62"
    #endif
        H_icGetBinPByStyleS_m(ch32_t, UC_PF, LC_PF);
    #undef UC_PF
    #undef LC_PF
    }
    #undef H_icGetBinPByStyleS_m

    #define icBinUToS(char_xt, GetRS_xf, GetP_xf, UToS_xf) \
        const char_xt* PF;\
        const char_xt* RD = GetRS_xf();\
            size_t szPF = GetP_xf(&PF, eStyle);\
        return UToS_xf(dst, value, RD, 2, iDigits, PF, szPF, WritePositiveSign);

    ic_core_dcl ch8_p ic_call icBinU32ToS8(ch8_p dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch8_t, icGetRS8, H_icGetBinPByStyleS8, icU32ToS8);
    }

    ic_core_dcl ch8_p ic_call icBinU64ToS8(ch8_p dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch8_t, icGetRS8, H_icGetBinPByStyleS8, icU64ToS8);
    }

    ic_core_dcl ch16_p ic_call icBinU32ToS16(ch16_p dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch16_t, icGetRS16, H_icGetBinPByStyleS16, icU32ToS16);
    }

    ic_core_dcl ch16_p ic_call icBinU64ToS16(ch16_p dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch16_t, icGetRS16, H_icGetBinPByStyleS16, icU64ToS16);
    }

    ic_core_dcl ch32_p ic_call icBinU32ToS32(ch32_p dst, uint32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch32_t, icGetRS32, H_icGetBinPByStyleS32, icU32ToS32);
    }

    ic_core_dcl ch32_p ic_call icBinU64ToS32(ch32_p dst, uint64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch32_t, icGetRS32, H_icGetBinPByStyleS32, icU64ToS32);
    }

    ic_core_dcl ch8_p ic_call icBinI32ToS8(ch8_p dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch8_t, icGetRS8, H_icGetBinPByStyleS8, icI32ToS8);
    }

    ic_core_dcl ch8_p ic_call icBinI64ToS8(ch8_p dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch8_t, icGetRS8, H_icGetBinPByStyleS8, icI64ToS8);
    }

    ic_core_dcl ch16_p ic_call icBinI32ToS16(ch16_p dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch16_t, icGetRS16, H_icGetBinPByStyleS16, icI32ToS16);
    }

    ic_core_dcl ch16_p ic_call icBinI64ToS16(ch16_p dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch16_t, icGetRS16, H_icGetBinPByStyleS16, icI64ToS16);
    }

    ic_core_dcl ch32_p ic_call icBinI32ToS32(ch32_p dst, int32_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch32_t, icGetRS32, H_icGetBinPByStyleS32, icI32ToS32);
    }

    ic_core_dcl ch32_p ic_call icBinI64ToS32(ch32_p dst, int64_t value, size_t iDigits, ic_bin_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        icBinUToS(ch32_t, icGetRS32, H_icGetBinPByStyleS32, icI64ToS32);
    }
    #undef H_icGetBinPByStyleS_m