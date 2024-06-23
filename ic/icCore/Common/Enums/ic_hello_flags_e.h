
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("ic Hello枚举") ic_def_enum(ic_hello_flags_e) {
    ic_hf_ic_info_v          = 0x00000001,
    ic_hf_current_info_v     = 0x00000002,
    ic_hf_dependences_info_v = 0x00000004,
    ic_hf_default_v          = ic_hf_current_info_v,
    ic_hf_all_v              = ic_hf_ic_info_v | ic_hf_current_info_v | ic_hf_dependences_info_v,
} ic_hello_flags_e;
ic_alias(ic_hello_e, ic_hello_flags_e);