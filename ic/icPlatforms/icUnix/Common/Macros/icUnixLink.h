
#pragma once

/**
说明：
    IC_UNIX_COMPILE       icUnix源码（集成）编译
    IC_UNIX_EXPORT        导出（编译）icUnix动态库
    IC_UNIX_IMPORT        导入（链接）icUnix动态库
    IC_UNIX_STATIC_EXPORT 导出（编译）icUnix静态库
    IC_UNIX_STATIC_IMPORT 导入（链接）icUnix静态库
**/

#include"../../../../icCore/Common/Macros/icEnv.h"

ic_info("默认模式")
    #if !defined(IC_UNIX_EXPORT) && !defined(IC_UNIX_IMPORT) && !defined(IC_UNIX_STATIC_EXPORT) && !defined(IC_UNIX_STATIC_IMPORT) && !defined(IC_UNIX_COMPILE)
        #define IC_UNIX_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info("ic_unix_declare")
    #if defined(IC_UNIX_COMPILE)                //IC源码（集成）编译
        #define ic_unix_declare          ic_c
    #elif defined(IC_UNIX_EXPORT)               //导出（编译）IC动态库
        #define ic_unix_declare          ic_export
    #elif defined(IC_UNIX_IMPORT)               //导入（链接）IC动态库
        #define ic_unix_declare          ic_import
    #elif defined(IC_UNIX_STATIC_EXPORT)        //导出（编译）IC静态库
        #define ic_unix_declare          ic_c
    #elif defined(IC_UNIX_STATIC_IMPORT)        //导入（链接）IC静态库
        #define ic_unix_declare          ic_c
    #endif

ic_info("mini keywords")
    #define ic_unix_dcl ic_unix_declare