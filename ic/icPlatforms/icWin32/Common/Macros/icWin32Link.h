
#pragma once

/**
说明：
    IC_WIN32_COMPILE       icWin32源码（集成）编译
    IC_WIN32_EXPORT        导出（编译）icWin32动态库
    IC_WIN32_IMPORT        导入（链接）icWin32动态库
    IC_WIN32_STATIC_EXPORT 导出（编译）icWin32静态库
    IC_WIN32_STATIC_IMPORT 导入（链接）icWin32静态库
**/

#include"../../../../icCore/Common/Macros/icEnv.h"

ic_info("默认模式")
    #if !defined(IC_WIN32_EXPORT) && !defined(IC_WIN32_IMPORT) && !defined(IC_WIN32_STATIC_EXPORT) && !defined(IC_WIN32_STATIC_IMPORT) && !defined(IC_WIN32_COMPILE)
        #define IC_WIN32_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info("ic_win32_declare")
    #if defined(IC_WIN32_COMPILE)                //IC源码（集成）编译
        #define ic_win32_declare          ic_c
    #elif defined(IC_WIN32_EXPORT)               //导出（编译）IC动态库
        #define ic_win32_declare          ic_export
    #elif defined(IC_WIN32_IMPORT)               //导入（链接）IC动态库
        #define ic_win32_declare          ic_import
    #elif defined(IC_WIN32_STATIC_EXPORT)        //导出（编译）IC静态库
        #define ic_win32_declare          ic_c
    #elif defined(IC_WIN32_STATIC_IMPORT)        //导入（链接）IC静态库
        #define ic_win32_declare          ic_c
    #endif

ic_info("mini keywords")
    #define ic_win32_dcl ic_win32_declare