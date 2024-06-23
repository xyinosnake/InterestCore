
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("二进制格式枚举") ic_def_enum(ic_bin_str_fmt_e) {
    ic_bsf_UP_v      = 0x00000000,  // uppercase prefix("0B01101001")
    ic_bsf_LP_v      = 0x00000001,  // lowercase prefix("0b01101001")
    ic_bsf_NP_v      = 0x00000002,  // no prefix("01101001")
    ic_bsf_default_v = ic_bsf_LP_v,
} ic_bin_str_fmt_e;
ic_alias(ic_bin_e, ic_bin_str_fmt_e);