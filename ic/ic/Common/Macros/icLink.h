
#pragma once

/**
说明：
    IC_COMPILE       IC源码（集成）编译
    IC_EXPORT        导出（编译）IC动态库
    IC_IMPORT        导入（链接）IC动态库
    IC_STATIC_EXPORT 导出（编译）IC静态库
    IC_STATIC_IMPORT 导入（链接）IC静态库
**/

#include"../../../icCore/Common/Macros/icEnv.h"

ic_info("默认模式")
    #if !defined(IC_EXPORT) && !defined(IC_IMPORT) && !defined(IC_STATIC_EXPORT) && !defined(IC_STATIC_IMPORT) && !defined(IC_COMPILE)
        #define IC_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info("ic_declare")
    #if defined(IC_COMPILE)                //IC源码（集成）编译
        #define ic_declare          ic_c
    #elif defined(IC_EXPORT)               //导出（编译）IC动态库
        #define ic_declare          ic_export
    #elif defined(IC_IMPORT)               //导入（链接）IC动态库
        #define ic_declare          ic_import
    #elif defined(IC_STATIC_EXPORT)        //导出（编译）IC静态库
        #define ic_declare          ic_c
    #elif defined(IC_STATIC_IMPORT)        //导入（链接）IC静态库
        #define ic_declare          ic_c
    #endif

ic_info("mini keywords")
    #define ic_dcl ic_declare