
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #ifdef IC_OS_LINUX
        #include<sys/io.h>
        #include<linux/fb.h>
    #endif
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<sys/mman.h>
    #include<fcntl.h>
    #include<unistd.h>
    #include<wchar.h>
    #include<stddef.h>
    #include<sys/ioctl.h>
    #include<pthread.h>

ic_info("headers")
    #include"../../Common/icCoreHeaders.h"
