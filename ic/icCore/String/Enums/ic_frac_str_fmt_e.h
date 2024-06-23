
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("分数格式枚举") ic_def_enum(ic_frac_str_fmt_e) {
    ic_fsf_default_v = 0x00000000,
    ic_fsf_WN_v      = 0x00000001, //write num positive sign
    ic_fsf_WD_v      = 0x00000002, //write den positive sign
    ic_fsf_WND_v     = (ic_fsf_WN_v | ic_fsf_WD_v)
} ic_frac_str_fmt_e;
ic_alias(ic_frac_e, ic_frac_str_fmt_e);