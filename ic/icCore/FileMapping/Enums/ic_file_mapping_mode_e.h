
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("文件映射模式枚举") ic_def_enum(ic_file_mapping_mode_e) {
    ic_fmm_read_v       = 0x00000000,
    ic_fmm_read_write_v = 0x00000001,
    ic_fmm_append_v     = 0x00000002,
} ic_file_mapping_mode_e;
ic_alias(ic_file_mapping_e, ic_file_mapping_mode_e);