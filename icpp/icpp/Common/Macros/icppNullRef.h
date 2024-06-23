
#pragma once

#include"../Objs/NullRef/icppNullRef.h"

ic_info("macros")
    #define icpp_nullref (H_icppGetNullref())
    #ifndef nullref
        #define nullref icpp_nullref
    #endif