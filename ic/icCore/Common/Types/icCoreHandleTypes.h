
#pragma once

#include"./icCoreValueTypes.h"
#include"../icCoreHeaders.h"

ic_info("IC Handle Types")
    ic_alias(ic_stream_h,        FILE*             ); //流句柄。
    ic_alias(ic_file_h,          void_p            ); //文件句柄。
    ic_alias(ic_thread_h,        void_p            ); //线程句柄。
    ic_alias(ic_thread_mutex_h,  void_p            ); //线程互斥体句柄（速度更快，但不可跨进程）。
    ic_alias(ic_process_mutex_h, void_p            ); //进程互斥体句柄（速度慢，可以跨进程）。
    ic_alias(ic_mutex_h,         ic_process_mutex_h); //互斥体句柄（默认为进程互斥体句柄）。