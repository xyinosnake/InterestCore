
#pragma once

#include"./icppTN.h"

ic_info("inl cst bool")
    #define icpp_bv   inline constexpr bool

ic_info("concept")
    #define icpp_t1c(c, t1)              icpp_t1(t1) concept c = requires
    #define icpp_t2c(c, t1, t2)          icpp_t2(t1, t2) concept c = requires
    #define icpp_t3c(c, t1, t2, t3)      icpp_t3(t1, t2, t3) concept c = requires
    #define icpp_t4c(c, t1, t2, t3, t4)  icpp_t4(t1, t2, t3, t4) concept c = requires