
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("十六进制格式枚举") ic_def_enum(ic_hex_str_fmt_e) {
    ic_hsf_UP_v      = 0x00000000, //uppercase prefix("0X0a")
    ic_hsf_LP_v      = 0x00000001, //lowercase prefix("0x0a")
    ic_hsf_NP_v      = 0x00000002, //no prefix("0a")
    ic_hsf_UR_v      = 0x00000000, //uppercase radix("0A")
    ic_hsf_LR_v      = 0x00000004, //lowercase radix("0a")
    ic_hsf_UU_v      = (ic_hsf_UP_v | ic_hsf_UR_v), //"0X0A"
    ic_hsf_UL_v      = (ic_hsf_UP_v | ic_hsf_LR_v), //"0X0a"
    ic_hsf_LU_v      = (ic_hsf_LP_v | ic_hsf_UR_v), //"0x0A"
    ic_hsf_LL_v      = (ic_hsf_LP_v | ic_hsf_LR_v), //"0x0a"
    ic_hsf_NU_v      = (ic_hsf_NP_v | ic_hsf_UR_v), //"0A"
    ic_hsf_NL_v      = (ic_hsf_NP_v | ic_hsf_LR_v), //"0a"
    ic_hsf_default_v = ic_hsf_LU_v,
} ic_hex_str_fmt_e;
ic_alias(ic_hex_e, ic_hex_str_fmt_e);










