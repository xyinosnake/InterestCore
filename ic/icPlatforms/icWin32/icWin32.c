#ifndef IC_WIN32_C
#define IC_WIN32_C

#include"./icWin32.h"

ic_info("*.c")
    #include"./Common/Funcs/icWin32CommonFuncs.c"
    #include"./String/Funcs/icWin32StringFuncs.c"
    #include"./Memory/Funcs/icWin32MemoryFuncs.c"
    #include"./Window/Funcs/icWin32WindowFuncs.c"
    #include"./Console/Funcs/icWin32ConsoleFuncs.c"
    #include"./Icon/Funcs/icWin32IconFuncs.c"
    #include"./Registry/Funcs/icWin32RegistryFuncs.c"
#endif