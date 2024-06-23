#pragma once


#include"./icEnv.h"
#include"./icInfo.h"

ic_info("macros")
    #define IC_TOPMOST

ic_info("Disable Warnings")
    #include"./icDisableWarnings.h"

ic_info("Win32置顶 - 在WIN32与VS平台下，必须置顶以下宏以避免部分C语言运行时动态库函数出现错误或警告信息。")
    #if defined(IC_OS_WINDOWS) && !defined(IC_NO_TOPMOST)
        #if !defined(_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES) && !defined(_CRT_SECURE_NO_WARNINGS) && !defined(_CRT_NON_CONFORMING_SWPRINTFS)
            #define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1    // 自动将标准函数置换成安全版本（安全模板重载）
            #define _CRT_SECURE_NO_WARNINGS                      // 禁用CRT的弃用警告（C4996警告）
            #define _CRT_NON_CONFORMING_SWPRINTFS                // 替换为标准Windows函数
        #endif
    #endif

ic_info("Clang Intrinsics Topmost - 该问题尚未解决，内容暂时弃用。") /*
        #if defined(__clang__)
            #define __AVX__
            #define __AVX2__
            #define __RDRND__
            #define __RDSEED__
        #endif
    */