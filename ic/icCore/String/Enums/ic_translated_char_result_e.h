
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("字符转换结果枚举") ic_def_enum(ic_translated_char_result_e) {
    ic_tcr_ok_v,
    ic_tcr_char_error_v,
    ic_tcr_not_enough_char_count_v,
    ic_tcr_empty_source_v,
} ic_translated_char_result_e;
ic_alias(ic_tcr_result_e, ic_translated_char_result_e);