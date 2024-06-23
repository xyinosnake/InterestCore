#ifndef IC_C
#define IC_C

#include"../icCore/icCore.h"
#include"./ic.h"

ic_info("*.c")
    #include"./Common/Funcs/icCommonFuncs.c"
    #include"./Memory/Funcs/icMemoryFuncs.c"
    /*#include"Platforms..." Platforms Funcs are in the other dll. /*/
    #include"./Intrinsics/Funcs/icIntrinsicsFuncs.c"
#endif