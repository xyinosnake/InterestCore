
#pragma once

#ifndef DIRECTINPUT_VERSION
    #define DIRECTINPUT_VERSION DIRECTINPUT_HEADER_VERSION
#elif DIRECTINPUT_VERSION != DIRECTINPUT_HEADER_VERSION
    #error #XYS_DirectInput错误：DIRECTINPUT_VERSION已经定义，且非最新版本。请检查头文件。
#endif

#include<dinput.h>