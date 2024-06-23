
#pragma once

#include"./P_icFracToS.h"

ic_info("defs")
    #define icFracToS_m(char_xt, GetRS_xf, IToS_xf) \
        const char_xt* RD = GetRS_xf();\
        dst = IToS_xf(dst, num, RD, 10, 0, 0, 0, eStyle & ic_fsf_WN_v);\
        *dst++ = (char_xt)'/';\
        dst = IToS_xf(dst, den, RD, 10, 0, 0, 0, eStyle & ic_fsf_WD_v);\
        return dst;

    ic_core_dcl ch8_p ic_call icFrac64ToS8(ch8_p dst, int32_t num, int32_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch8_t, icGetRS8, icI32ToS8);
    }

    ic_core_dcl ch8_p ic_call icFrac128ToS8(ch8_p dst, int64_t num, int64_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch8_t, icGetRS8, icI64ToS8);
    }

    ic_core_dcl ch16_p ic_call icFrac64ToS16(ch16_p dst, int32_t num, int32_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch16_t, icGetRS16, icI32ToS16);
    }

    ic_core_dcl ch16_p ic_call icFrac128ToS16(ch16_p dst, int64_t num, int64_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch16_t, icGetRS16, icI64ToS16);
    }

    ic_core_dcl ch32_p ic_call icFrac64ToS32(ch32_p dst, int32_t num, int32_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch32_t, icGetRS32, icI32ToS32);
    }

    ic_core_dcl ch32_p ic_call icFrac128ToS32(ch32_p dst, int64_t num, int64_t den, ic_frac_e eStyle) ic_noexc {
        icFracToS_m(ch32_t, icGetRS32, icI64ToS32);
    }
    #undef icFracToS_m