
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("macros")
    #if defined(IC_OS_WINDOWS)
        #define ic_ftell64 _ftelli64
        #define ic_fseek64 _fseeki64
    #else //defined(IC_OS_UNIX_LIKE)
        // ic_c int64_t ic_call ftello64(FILE*) ic_noexcept;
        // ic_c int32_t ic_call fseeko64(FILE*, int64_t, int) ic_noexcept;
        #define ic_ftell64 ftello64
        #define ic_fseek64 fseeko64
    #endif