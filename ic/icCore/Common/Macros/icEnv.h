
#pragma once

//icCore环境宏

#include"./icInfo.h"

ic_info("调试 & 发布")
#if defined(IC_DEBUG) && defined(IC_RELEASE)
    #error Both IC_DEBUG and IC_RELEASE are defined!
#elif !defined(IC_DEBUG) && !defined(IC_RELEASE)
    #ifdef NDEBUG
        #define IC_RELEASE
    #else
        #define IC_DEBUG
    #endif
#endif

ic_info("字长定义")
    #ifndef IC_WORD_SIZE
        #if defined(__WORD_SIZE)
            #define IC_WORD_SIZE __WORD_SIZE
        #elif defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64) || defined(_M_ARM64) || \
            defined(__aarch64__) || defined(_M_IA64) || defined(__ia64__) || defined(__x86_64__)
            #define IC_WORD_SIZE 64 //字长（位数）
        #elif defined(_M_IX86) || defined(__i386__) || defined(_M_ARM) || defined(__arm__)
            #define IC_WORD_SIZE 32 //字长（位数）
        #else
            #define IC_WORD_SIZE 0 //未知的字长（位数）
        #endif
    #endif

ic_info("操作系统定义")
    #if defined(_WIN32)
        #define IC_OS_WINDOWS //Windows操作系统
    #elif defined(__linux__)
        #define IC_OS_LINUX   //Linux操作系统
    #elif defined(__ANDROID__)
        #define IC_OS_ANDROID //Android操作系统
    #elif defined(__APPLE__)
        #define IC_OS_APPLE   //苹果操作系统
    #elif defined(__unix__)
        #define IC_OS_UNIX    //Unix操作系统
    #else
        #define IC_OS_UNKNOWN //未知操作系统
    #endif

ic_info("不支持的操作系统")
    #if defined(IC_OS_UNKNOWN) && !defined(IC_USE_UNSUPPORTED_OS)
        #error Unsupported OS!
    #endif

ic_info("类Unix操作系统")
    #if defined(IC_OS_LINUX) || defined(IC_OS_ANDROID) || defined(IC_OS_APPLE) || defined(IC_OS_UNIX)
        #define IC_OS_UNIX_LIKE
    #endif

ic_info("使用UTF8")
    //今后IC假定程序使用Utf8作为字符串基本格式。

ic_info("编译环境定义（编译器宏）")
    #if defined(_MSC_VER) && !defined(__clang__) && !(defined(__ICC) || defined(__INTEL_COMPILER))
        #define IC_CE_MSC     //MSC编译环境（Microsoft C/C++ Compiler）
    #endif
    #if defined(__ICC) || defined(__INTEL_COMPILER)
        #define IC_CE_ICC     //ICC编译环境（Intel C/C++ Compiler）
    #endif
    #if defined(__GNUC__) || defined(__GNUG__)
        #define IC_CE_GNUC    //GNUC编译环境（GNU C/C++ Compiler）
    #endif
    #if defined(__clang__)
        #define IC_CE_CLANG   //Clang编译环境（Clang C/C++ Compiler）
    #endif
    #if !defined(IC_CE_MSC) && !defined(IC_CE_ICC) && !defined(IC_CE_GNUC) && !defined(IC_CE_CLANG)
        #define IC_CE_UNKNOWN //未知编译环境
    #endif

ic_info("Can: #pragma comment(lib, "...")")
    #if defined(IC_CE_MSC) || defined(IC_CE_ICC) || defined(IC_CE_CLANG)
        #define IC_CAN_PRAGMA_LIB
    #endif

#if defined(IC_CAN_PRAGMA_LIB) && !defined(IC_NO_LIBS)
    #define IC_USE_DEFAULT_LIBS
#endif

ic_info("不支持的编译器")
    #if defined(IC_CE_UNKNOWN) && !defined(IC_USE_UNSUPPORTED_COMPILER)
        #error Your compiler is not supported by IC! Please use the supported compilers(MSC, GNUC, ICC, CLANG).
    #endif

ic_info("硬件定义（CPU宏）")
    #if defined(_M_X64) || defined(__x86_64__)
        #define IC_M_x86_64     // x86-64
    #elif defined(_M_IX86) || defined(__i386__)
        #define IC_M_x86        // x86-32
    #elif defined(_M_ARM) || defined(__arm__)
        #define IC_M_ARM        // ARM-32
    #elif defined(_M_ARM64) || defined(__aarch64__)
        #define IC_M_ARM64      // ARM-64
    #elif defined(_M_IA64) || defined(__ia64__)
        #define IC_M_IA64       // IA64
    #elif defined(__riscv)
        #define IC_M_RISCV
    /**************The old CPUs*********************/
    #elif defined(_M_PPC) || defined(__powerpc__)
        #define IC_M_PPC
    #elif defined(_M_M68K_) || defined(__m68k__)
        #define IC_M_M68K
    #elif defined(_M_MIPS) || defined(__mips__)
        #define IC_M_MIPS
    #elif defined(_M_ALPHA__) || defined(__alpha__)
        #define IC_M_ALPHA
    #endif

ic_info("字节端序")
    #if defined(IC_LE) && defined(IC_BE)
        #error Both IC_LE and IC_BE are defined!
    #endif
    #if !defined(IC_LE) && !defined(IC_BE)
        #if defined(IC_M_x86_64) || defined(IC_M_x86) || defined(_M_ARM) || defined(_M_ARM64) || defined(IC_M_RISCV)
            #define IC_LE
        #else
            #define IC_BE
        #endif
    #endif
