
#pragma once

#include"../../../../ic/icCore/Common/Macros/icInfo.h"

ic_info("icppT<>")
    #define icpp_t()                    template<>

ic_info("icppTN")
    #define icpp_t1(t1)                 template<typename t1>
    #define icpp_t2(t1, t2)             template<typename t1, typename t2>
    #define icpp_t3(t1, t2, t3)         template<typename t1, typename t2, typename t3>
    #define icpp_t4(t1, t2, t3, t4)     template<typename t1, typename t2, typename t3, typename t4>

ic_info("icppVT")
    #define icpp_v1(v1)                 template<v1>
    #define icpp_v2(v1, v2)             template<v1, v2>
    #define icpp_t1v1(t1, v1)           template<typename t1, v1>
    #define icpp_v1t1(t1, v1)           template<v1, typename t1>

ic_info("icppC")
    #define icpp_c1(c1)                 template<c1>
    #define icpp_c2(c1, c2)             template<c1, c2>
