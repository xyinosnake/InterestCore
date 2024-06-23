
#pragma once

#include"./P_icHexToS.h"
#include"./P_icPmtToS.h"

ic_info("H dcls")
    ic_hide size_t ic_call H_icGetHexPAndRByStyleS8 (const ch8_t**  ppDst, ic_hex_str_fmt_e eStyle) ic_noexc;
    ic_hide size_t ic_call H_icGetHexPAndRByStyleS16(const ch16_t** ppDst, ic_hex_str_fmt_e eStyle) ic_noexc;
    ic_hide size_t ic_call H_icGetHexPAndRByStyleS32(const ch32_t** ppDst, ic_hex_str_fmt_e eStyle) ic_noexc;

ic_info("defs")
    #define H_icGetHexPAndRByStyleS_m(char_xt, LR_xf, UR_xf, LC_PF, UC_PF) \
        size_t szPrefix;\
        ic_if_do_x2(eStyle& ic_hsf_NP_v, ppDst[0] = 0, szPrefix = 0)\
        ic_else_do_x2(ppDst[0] = (const char_xt*)((eStyle & ic_hsf_LP_v) ? LC_PF : UC_PF), szPrefix = 2)\
        ic_do_and_return(ppDst[1] = (eStyle & ic_hsf_LR_v) ? LR_xf() : UR_xf(), szPrefix)

    ic_hide size_t ic_call H_icGetHexPAndRByStyleS8(const ch8_t** ppDst, ic_hex_str_fmt_e eStyle) ic_noexc {
        H_icGetHexPAndRByStyleS_m(ch8_t, icGetHexLRS8, icGetHexURS8, "0x", "0X");
    }

    ic_hide size_t ic_call H_icGetHexPAndRByStyleS16(const ch16_t** ppDst, ic_hex_str_fmt_e eStyle) ic_noexc {
    #if /* defined(IC_LE) || */ !defined(IC_BE)
        #define LC_PF "\x30\x00\x78\x00"
        #define UC_PF "\x30\x00\x58\x00"
    #else
        #define LC_PF "\x00\x30\x00\x78"
        #define UC_PF "\x00\x30\x00\x58"
    #endif
        H_icGetHexPAndRByStyleS_m(ch16_t, icGetHexLRS16, icGetHexURS16, LC_PF, UC_PF);
    #undef UC_PF
    #undef LC_PF
    }

    ic_hide size_t ic_call H_icGetHexPAndRByStyleS32(const ch32_t** ppDst, ic_hex_str_fmt_e eStyle) ic_noexc {
    #if /* defined(IC_LE) || */ !defined(IC_BE)
        #define UC_PF "\x30\x00\x00\x00\x58\x00\x00\x00"
        #define LC_PF "\x30\x00\x00\x00\x78\x00\x00\x00"
    #else
        #define UC_PF "\x00\x00\x00\x30\x00\x00\x00\x58"
        #define LC_PF "\x00\x00\x00\x30\x00\x00\x00\x78"
    #endif
        H_icGetHexPAndRByStyleS_m(ch32_t, icGetHexLRS32, icGetHexURS32, LC_PF, UC_PF);
    #undef LC_PF
    #undef UC_PF
    }
    #undef H_icGetHexPAndRByStyleS_m
    
    #define H_icHexUToS_m(char_xt, PR_xv, UToS_xv) \
        const char_xt* PF_RD[2];\
              size_t   szPF = PR_xv(PF_RD, eStyle);\
        return UToS_xv(dst, value, PF_RD[1], 16, iDigits, PF_RD[0], szPF, WritePositiveSign);

    ic_core_dcl ch8_p ic_call icHexU32ToS8(ch8_p dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch8_t, H_icGetHexPAndRByStyleS8, icU32ToS8);
    }

    ic_core_dcl ch8_p ic_call icHexU64ToS8(ch8_p dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch8_t, H_icGetHexPAndRByStyleS8, icU64ToS8);
    }

    ic_core_dcl ch16_p ic_call icHexU32ToS16(ch16_p dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch16_t, H_icGetHexPAndRByStyleS16, icU32ToS16);
    }

    ic_core_dcl ch16_p ic_call icHexU64ToS16(ch16_p dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch16_t, H_icGetHexPAndRByStyleS16, icU64ToS16);
    }
    ic_core_dcl ch32_p ic_call icHexU32ToS32(ch32_p dst, uint32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch32_t, H_icGetHexPAndRByStyleS32, icU32ToS32);
    }
    ic_core_dcl ch32_p ic_call icHexU64ToS32(ch32_p dst, uint64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch32_t, H_icGetHexPAndRByStyleS32, icU64ToS32);
    }

    ic_core_dcl ch8_p ic_call icHexI32ToS8(ch8_p dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch8_t, H_icGetHexPAndRByStyleS8, icI32ToS8);
    }

    ic_core_dcl ch8_p ic_call icHexI64ToS8(ch8_p dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch8_t, H_icGetHexPAndRByStyleS8, icI64ToS8);
    }

    ic_core_dcl ch16_p ic_call icHexI32ToS16(ch16_p dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch16_t, H_icGetHexPAndRByStyleS16, icI32ToS16);
    }

    ic_core_dcl ch16_p ic_call icHexI64ToS16(ch16_p dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch16_t, H_icGetHexPAndRByStyleS16, icI64ToS16);
    }

    ic_core_dcl ch32_p ic_call icHexI32ToS32(ch32_p dst, int32_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch32_t, H_icGetHexPAndRByStyleS32, icI32ToS32);
    }

    ic_core_dcl ch32_p ic_call icHexI64ToS32(ch32_p dst, int64_t value, size_t iDigits, ic_hex_str_fmt_e eStyle, bool WritePositiveSign) ic_noexc {
        H_icHexUToS_m(ch32_t, H_icGetHexPAndRByStyleS32, icI64ToS32);
    }
    #undef H_icHexUToS_m