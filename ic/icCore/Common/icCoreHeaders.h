
#pragma once

#include"./Macros/icCoreCommonMacros.h"

ic_info("headers")
    #ifdef __cplusplus
        #include<cassert>
        #include<cstdio>
        #include<cstdlib>
        #include<cstdint>
        #include<cctype>
        #include<cstring>
        #include<clocale>
        #include<ctime>
        #include<cmath>
        #include<cstdarg>
        #include<cwchar>
    #else
        #include<assert.h>
        #include<stdio.h>
        #include<stdlib.h>
        #include<stdint.h>
        #include<ctype.h>
        #include<string.h>
        #include<locale.h>
        #include<stdbool.h>
        #include<time.h>
        #include<math.h>
        #include<stdarg.h>
        #include<wchar.h>
    #endif