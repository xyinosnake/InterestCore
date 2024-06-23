
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_def_enum(ic_str_fmt_e) {
    ic_sf_UTF8_v  = 0x00000000,
    ic_sf_UTF16_v = 0x00000001,
    ic_sf_UTF32_v = 0x00000002,
    ic_sf_ANSI_v  = 0x00000003,
    ic_sf_N_v     = ic_sf_UTF8_v,
#ifdef IC_OS_WINDOWS
    ic_sf_W_v = ic_sf_UTF16_v,
    ic_sf_A_v = ic_sf_ANSI_v,
#else
    ic_sf_W_v = ic_sf_UTF32_v,
#endif
} ic_str_fmt_e;
ic_alias(ic_str_e, ic_str_fmt_e);