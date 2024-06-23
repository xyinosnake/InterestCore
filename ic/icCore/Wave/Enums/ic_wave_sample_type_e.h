
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("ic Hello枚举") ic_def_enum(ic_wave_sample_type_e) {
    ic_wave_sample_type_unknown_v		   = 0,
    ic_wave_sample_type_unsigned_integer_v = 1,
    ic_wave_sample_type_signed_integer_v   = 2,
    ic_wave_sample_type_float_v			   = 3,
} ic_wave_sample_type_e;
ic_alias(ic_wave_sample_e, ic_wave_sample_type_e);