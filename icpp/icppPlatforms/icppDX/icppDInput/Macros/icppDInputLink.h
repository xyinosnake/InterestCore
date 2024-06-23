
#pragma once

/**
说明：
    ICPP_DINPUT_COMPILE       icppDInput源码（集成）编译
    ICPP_DINPUT_EXPORT        导出（编译）icppDInput动态库
    ICPP_DINPUT_IMPORT        导入（链接）icppDInput动态库
    ICPP_DINPUT_STATIC_EXPORT 导出（编译）icppDInput静态库
    ICPP_DINPUT_STATIC_IMPORT 导入（链接）icppDInput静态库
**/

#include"../../../../icpp/Common/Macros/icppLink.h"

ic_info("默认模式")
    #if !defined(ICPP_DINPUT_EXPORT) && !defined(ICPP_DINPUT_IMPORT) && !defined(ICPP_DINPUT_STATIC_EXPORT) && !defined(ICPP_DINPUT_STATIC_IMPORT) && !defined(ICPP_DINPUT_COMPILE)
        #define ICPP_DINPUT_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info()
    #if defined(ICPP_DINPUT_STATIC_IMPORT)
        #define icpp_dinput_need_statics 0
    #else
        #define icpp_dinput_need_statics 1
    #endif

ic_info("icpp_dinput_declare")
    #if defined(ICPP_DINPUT_COMPILE)                //IC源码（集成）编译
        #define icpp_dinput_declare          ic_c
    #elif defined(ICPP_DINPUT_EXPORT)               //导出（编译）IC动态库
        #define icpp_dinput_declare          ic_export
    #elif defined(ICPP_DINPUT_IMPORT)               //导入（链接）IC动态库
        #define icpp_dinput_declare          ic_import
    #elif defined(ICPP_DINPUT_STATIC_EXPORT)        //导出（编译）IC静态库
        #define icpp_dinput_declare          ic_c
    #elif defined(ICPP_DINPUT_STATIC_IMPORT)        //导入（链接）IC静态库
        #define icpp_dinput_declare          ic_c
    #endif

ic_info("mini keywords")
    #define icpp_dinput_dcl icpp_dinput_declare