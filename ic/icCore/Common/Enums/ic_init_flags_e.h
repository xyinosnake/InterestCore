
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("ic初始化枚举") ic_def_enum(ic_init_flags_e) {
    ic_itf_utf8_v           = 0x00000001, //icCore
    ic_itf_console_buffer_v = 0x00000002, //icCore(Not in Core Default)
    ic_itf_console_color_v  = 0x00000004, //icCore
    ic_itf_time_v           = 0x00000008, //icCore
    ic_itf_core_default_v   = ic_itf_utf8_v | ic_itf_console_color_v,
    ic_itf_core_all_v       = ic_itf_utf8_v | ic_itf_console_buffer_v | ic_itf_console_color_v | ic_itf_time_v,

    ic_itf_process_heap_v   = 0x00000010, //ic
    ic_itf_default_v        = ic_itf_core_default_v | ic_itf_process_heap_v,
    ic_itf_all_v            = ic_itf_core_all_v | ic_itf_process_heap_v,
#ifdef IC_OS_WINDOWS
    ic_itf_win32_WinMain_default = ic_itf_process_heap_v,
#endif
} ic_init_flags_e;
ic_alias(ic_init_e, ic_init_flags_e);