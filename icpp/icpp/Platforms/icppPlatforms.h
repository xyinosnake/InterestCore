
#pragma once

#include"../Common/Macros/icppCommonMacros.h"

ic_info("switch os")
    #if defined(IC_OS_WINDOWS)
        #include"../../icppPlatforms/icppWin32/icppWin32.h"
    #elif defined(IC_OS_UNIX_LIKE)
        #include"../../icppPlatforms/icppUnix/icppUnix.h"
    #endif