
#pragma once

#include"../../ic/ic/ic.h"
#include"./Platforms/icppPlatforms.h"
#include"./Common/icppCommon.h"
#include"./Memory/icppMemory.h"
#include"./String/icppString.h"
#include"./File/icppFile.h"

#ifdef ICPP_COMPILE //默认
    #include"./icpp.cpp"
#endif