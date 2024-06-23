
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("文件模式枚举") ic_def_enum(ic_file_mode_e) {
    ic_fm_read_v       = 0x00000000,
    ic_fm_write_v      = 0x00000001,
    ic_fm_read_write_v = 0x00000002,
    ic_fm_append_v     = 0x00000003,
    ic_fm_overwrite_v  = ic_fm_read_write_v,
} ic_file_mode_e;
ic_alias(ic_file_e, ic_file_mode_e);