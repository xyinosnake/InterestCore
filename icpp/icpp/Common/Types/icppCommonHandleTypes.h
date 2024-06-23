
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Types/icCommonTypes.h"

icpp_ns_x1(icpp) ic_info("IC Handle Types")
    icpp_alias(stream_h,        ::ic_stream_h);        //流句柄。
    icpp_alias(file_h,          ::ic_file_h);          //文件句柄。
    icpp_alias(thread_h,        ::ic_thread_h);        //线程句柄。
    icpp_alias(thread_mutex_h,  ::ic_thread_mutex_h);  //线程互斥体句柄（速度更快，但不可跨进程）。
    icpp_alias(process_mutex_h, ::ic_process_mutex_h); //进程互斥体句柄（速度慢，可以跨进程）。
    icpp_alias(mutex_h,         ::ic_mutex_h);         //互斥体句柄（默认为进程互斥体句柄）。
icpp_end_ns_x1;