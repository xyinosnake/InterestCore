
#pragma once

/**
说明：
    ICPP_WIC_COMPILE       icppWIC源码（集成）编译
    ICPP_WIC_EXPORT        导出（编译）icppWIC动态库
    ICPP_WIC_IMPORT        导入（链接）icppWIC动态库
    ICPP_WIC_STATIC_EXPORT 导出（编译）icppWIC静态库
    ICPP_WIC_STATIC_IMPORT 导入（链接）icppWIC静态库
**/

#include"../../../../icpp/Common/Macros/icppLink.h"

ic_info("默认模式")
    #if !defined(ICPP_WIC_EXPORT) && !defined(ICPP_WIC_IMPORT) && !defined(ICPP_WIC_STATIC_EXPORT) && !defined(ICPP_WIC_STATIC_IMPORT) && !defined(ICPP_WIC_COMPILE)
        #define ICPP_WIC_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info()
    #if defined(ICPP_WIC_STATIC_IMPORT)
        #define icpp_wic_need_statics 0
    #else
        #define icpp_wic_need_statics 1
    #endif

ic_info("icpp_wic_declare")
    #if defined(ICPP_WIC_COMPILE)                //IC源码（集成）编译
        #define icpp_wic_declare          ic_c
    #elif defined(ICPP_WIC_EXPORT)               //导出（编译）IC动态库
        #define icpp_wic_declare          ic_export
    #elif defined(ICPP_WIC_IMPORT)               //导入（链接）IC动态库
        #define icpp_wic_declare          ic_import
    #elif defined(ICPP_WIC_STATIC_EXPORT)        //导出（编译）IC静态库
        #define icpp_wic_declare          ic_c
    #elif defined(ICPP_WIC_STATIC_IMPORT)        //导入（链接）IC静态库
        #define icpp_wic_declare          ic_c
    #endif

ic_info("mini keywords")
    #define icpp_wic_dcl icpp_wic_declare