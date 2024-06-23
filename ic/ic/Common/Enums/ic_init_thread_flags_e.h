
#pragma once

#include"../Macros/icCommonMacros.h"

ic_info("ic线程初始化枚举") ic_def_enum(ic_init_thread_flags_e) {
    ic_ittf_thread_heap_v = 0x00000001,
    ic_ittf_default_v     = ic_ittf_thread_heap_v,
} ic_init_thread_flags_e;
ic_alias(ic_init_thread_e, ic_init_thread_flags_e);