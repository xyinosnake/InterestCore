
#pragma once

#include"../Common/Macros/icCommonMacros.h"

ic_info("switch os")
    #if defined(IC_OS_WINDOWS)
        #if defined(IC_PLATFORMS_IMPORT)
            #define IC_WIN32_IMPORT
        #endif
        #include"../../icPlatforms/icWin32/icWin32.h"
    #elif defined(IC_OS_UNIX_LIKE)
        #if defined(IC_PLATFORMS_IMPORT)
            #define IC_UNIX_IMPORT
        #endif
        #include"../../icPlatforms/icUnix/icUnix.h"
    #endif