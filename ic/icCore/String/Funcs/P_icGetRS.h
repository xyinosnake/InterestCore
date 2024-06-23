
#pragma once

#include"./icCoreStringFuncs.h"

ic_info("dcls");
    ic_core_dcl cch8_p  ic_call icGetRS8 () ic_noexc; //RS means Radix String.
    ic_core_dcl cch16_p ic_call icGetRS16() ic_noexc; //RS means Radix String.
    ic_core_dcl cch32_p ic_call icGetRS32() ic_noexc; //RS means Radix String.
    #define                     icGetHexURS8  icGetRS8   //URS means Uppercase Radix String.
    #define                     icGetHexURS16 icGetRS16  //URS means Uppercase Radix String.
    #define                     icGetHexURS32 icGetRS32  //URS means Uppercase Radix String.
    ic_core_dcl cch8_p  ic_call icGetHexLRS8 () ic_noexc;
    ic_core_dcl cch16_p ic_call icGetHexLRS16() ic_noexc;
    ic_core_dcl cch32_p ic_call icGetHexLRS32() ic_noexc;