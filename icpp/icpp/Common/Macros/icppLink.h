
#pragma once

/**
说明：
    ICPP_COMPILE       ICPP源码（集成）编译
    ICPP_EXPORT        导出（编译）ICPP动态库
    ICPP_IMPORT        导入（链接）ICPP动态库
    ICPP_STATIC_EXPORT 导出（编译）ICPP静态库
    ICPP_STATIC_IMPORT 导入（链接）ICPP静态库
**/

#include"../../../../ic/icCore/Common/Macros/icCoreLink.h"

ic_info("默认模式")
    #if !defined(ICPP_EXPORT) && !defined(ICPP_IMPORT) && !defined(ICPP_STATIC_EXPORT) && !defined(ICPP_STATIC_IMPORT) && !defined(ICPP_COMPILE)
        #define ICPP_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info()
    #if defined(ICPP_STATIC_IMPORT)
        #define icpp_need_statics 0
    #else
        #define icpp_need_statics 1
    #endif

ic_info("icpp_declare")
    #if defined(ICPP_COMPILE)                //IC源码（集成）编译
        #define icpp_declare          ic_c
    #elif defined(ICPP_EXPORT)               //导出（编译）IC动态库
        #define icpp_declare          ic_export
    #elif defined(ICPP_IMPORT)               //导入（链接）IC动态库
        #define icpp_declare          ic_import
    #elif defined(ICPP_STATIC_EXPORT)        //导出（编译）IC静态库
        #define icpp_declare          ic_c
    #elif defined(ICPP_STATIC_IMPORT)        //导入（链接）IC静态库
        #define icpp_declare          ic_c
    #endif

ic_info("mini keywords")
    #define icpp_dcl icpp_declare