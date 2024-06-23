
#pragma once

/**
说明：
    ICPP_DXC_COMPILE       icppDXC源码（集成）编译
    ICPP_DXC_EXPORT        导出（编译）icppDXC动态库
    ICPP_DXC_IMPORT        导入（链接）icppDXC动态库
    ICPP_DXC_STATIC_EXPORT 导出（编译）icppDXC静态库
    ICPP_DXC_STATIC_IMPORT 导入（链接）icppDXC静态库
**/

#include"../../../../icpp/Common/Macros/icppLink.h"

ic_info("默认模式")
    #if !defined(ICPP_DXC_EXPORT) && !defined(ICPP_DXC_IMPORT) && !defined(ICPP_DXC_STATIC_EXPORT) && !defined(ICPP_DXC_STATIC_IMPORT) && !defined(ICPP_DXC_COMPILE)
        #define ICPP_DXC_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info()
    #if defined(ICPP_DXC_STATIC_IMPORT)
        #define icpp_dxc_need_statics 0
    #else
        #define icpp_dxc_need_statics 1
    #endif

ic_info("icpp_dxc_declare")
    #if defined(ICPP_DXC_COMPILE)                //IC源码（集成）编译
        #define icpp_dxc_declare          ic_c
    #elif defined(ICPP_DXC_EXPORT)               //导出（编译）IC动态库
        #define icpp_dxc_declare          ic_export
    #elif defined(ICPP_DXC_IMPORT)               //导入（链接）IC动态库
        #define icpp_dxc_declare          ic_import
    #elif defined(ICPP_DXC_STATIC_EXPORT)        //导出（编译）IC静态库
        #define icpp_dxc_declare          ic_c
    #elif defined(ICPP_DXC_STATIC_IMPORT)        //导入（链接）IC静态库
        #define icpp_dxc_declare          ic_c
    #endif

ic_info("mini keywords")
    #define icpp_dxc_dcl icpp_dxc_declare