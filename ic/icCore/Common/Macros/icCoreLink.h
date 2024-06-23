
#pragma once

/**
说明：
    IC_CORE_COMPILE       IC CORE源码（集成）编译
    IC_CORE_EXPORT        导出（编译）IC CORE动态库
    IC_CORE_IMPORT        导入（链接）IC CORE动态库
    IC_CORE_STATIC_EXPORT 导出（编译）IC CORE静态库
    IC_CORE_STATIC_IMPORT 导入（链接）IC CORE静态库
**/

#include"./icEnv.h"
#include"./icInfo.h"

ic_info("默认模式")
    #if !defined(IC_CORE_EXPORT) && !defined(IC_CORE_IMPORT) && !defined(IC_CORE_STATIC_EXPORT) && !defined(IC_CORE_STATIC_IMPORT) && !defined(IC_CORE_COMPILE)
        #define IC_CORE_COMPILE      //如果没有定义5种模式中的任意一种，默认就是源码（集成）编译模式
    #endif

ic_info("ic_c")
    #ifdef __cplusplus
        #define ic_c extern"C"
    #else
        #define ic_c
    #endif

ic_info("ic_core_declare")
    #if defined(IC_CORE_COMPILE)                //IC源码（集成）编译
        #define ic_core_declare          ic_c
    #elif defined(IC_CORE_EXPORT)               //导出（编译）IC动态库
        #define ic_core_declare          ic_export
    #elif defined(IC_CORE_IMPORT)               //导入（链接）IC动态库
        #define ic_core_declare          ic_import
    #elif defined(IC_CORE_STATIC_EXPORT)        //导出（编译）IC静态库
        #define ic_core_declare          ic_c
    #elif defined(IC_CORE_STATIC_IMPORT)        //导入（链接）IC静态库
        #define ic_core_declare          ic_c
    #endif

ic_info("call ways（Windows下，仅x86有差别，x64下完全等价）")
    #if defined(IC_OS_WINDOWS)
        #if defined(IC_CE_ICC) || defined(IC_CE_MSC)
            #define ic_call       __cdecl   // IC 标准调用方式
            #define ic_t_call     __stdcall // IC 线程函数调用方式
            #define ic_win32_call __stdcall // IC Win32函数调用方式
        #elif defined(IC_CE_GNUC) || defined(IC_CE_CLANG)
            #define ic_call       __attribute__((__cdecl__))   // IC 标准调用方式
            #define ic_t_call     __attribute__((__stdcall__)) // IC 线程函数调用方式
            #define ic_win32_call __attribute__((__stdcall__)) // IC Win32函数调用方式
        #endif
    #else
        #define ic_call   // IC 标准调用方式
        #define ic_t_call // IC 线程函数调用方式
    #endif

ic_info("ic_hide")
    #if defined(IC_USE_HIDE) || defined(IC_CE_CLANG) || (defined(IC_CE_GNUC) && !defined(IC_OS_WINDOWS))
        #define ic_hide __attribute__((visibility("hidden")))
    #else
        #define ic_hide
    #endif

ic_info("DLL")
    #if defined(IC_OS_UNIX_LIKE) || defined(IC_CE_GNUC)
        #ifdef __cplusplus
            #define ic_export extern"C" __attribute__((visibility("default"))) //DLL导出
            #define ic_import extern"C"                                        //DLL导入
        #else
            #define ic_export __attribute__((visibility("default"))) //DLL导出
            #define ic_import extern                                 //DLL导入
        #endif
    #elif defined(IC_OS_WINDOWS)
        #ifdef __cplusplus
            #define ic_export extern"C" __declspec(dllexport) //DLL导出
            #define ic_import extern"C" __declspec(dllimport) //DLL导入
        #else
            #define ic_export __declspec(dllexport) //DLL导出
            #define ic_import __declspec(dllimport) //DLL导入
        #endif
    #endif

ic_info("mini keywords")
    #define ic_core_dcl ic_core_declare
    #define ic_exp      ic_export
    #define ic_imp      ic_import