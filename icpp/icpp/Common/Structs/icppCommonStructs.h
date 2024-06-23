
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

// #include"../Types/icppCommonTypes.h"
// #include"../../../ic/Common/Structs/icCommonStructs.h"

ic_info("declarations")
    icpp_t1(obj_xt) struct ICPP_ITV_G; // Interval
    icpp_t1(obj_xt) struct ICPP_SEG_G; // Segment
    icpp_t1v1(obj_xt, size_t N) struct ICPP_PN_G;   // Pointer x N
    icpp_t1(obj_xt) using ICPP_P3_G = ICPP_PN_G<obj_xt, 3>; // Pointer x 3
    icpp_t1(obj_xt) using ICPP_P4_G = ICPP_PN_G<obj_xt, 4>; // Pointer x 4
    icpp_v1(size_t N) struct ICPP_BLOCK_G; // Block (Byte x N)
    using ICPP_ITV = ICPP_ITV_G<void>; // Interval
    using ICPP_SEG = ICPP_SEG_G<void>; // Segment
    using ICPP_P3  = ICPP_P3_G<void>;  // Pointer x 3
    using ICPP_P4  = ICPP_P4_G<void>;  // Pointer x 4
    icpp_t1v1(value_xt, size_t CAP) struct ICPP_MIXED_P3_G; // Mixed P3

ic_info("ns declarations") icpp_ns_x1(icpp)
    icpp_t1(obj_xt) using ITV_G = ICPP_ITV_G<obj_xt>;  // Interval
    icpp_t1(obj_xt) using SEG_G = ICPP_SEG_G<obj_xt>;  // Segment
    icpp_t1v1(obj_xt, size_t N) using PN_G = ICPP_PN_G<obj_xt, N>; // Pointer x N
    icpp_t1(obj_xt) using P3_G = ICPP_P3_G<obj_xt>;    // Pointer x 3
    icpp_t1(obj_xt) using P4_G = ICPP_P4_G<obj_xt>;    // Pointer x 4
    icpp_v1(size_t N) using BLOCK_G = ICPP_BLOCK_G<N>; // Block (Byte x N)
    using ITV = ICPP_ITV;
    using SEG = ICPP_SEG;
    using P3  = ICPP_P3;
    using P4  = ICPP_P4;
    icpp_t1v1(value_xt, size_t CAP) using MIXED_P3_G = ICPP_MIXED_P3_G<value_xt, CAP>; // Mixed P3
icpp_end_ns_x1

ic_info("definitions")
    icpp_t1(obj_xt) struct ICPP_ITV_G {
        obj_xt* left;  // start position of interval.
        obj_xt* right; // end   position of interval.
    };

    icpp_t1(obj_xt) struct ICPP_SEG_G{
        obj_xt* position;
        size_t  distance; // size of bytes.
    };

    icpp_t1v1(obj_xt, size_t N) struct ICPP_PN_G {
        obj_xt* ptr[N];
    };

    icpp_v1(size_t N) struct ICPP_BLOCK_G {
        uint8_t block[N];
    };

    icpp_t1v1(value_xt, size_t CAP) struct ICPP_MIXED_P3_G {
        value_xt* ptr[1];      // p0 = ptr[0]; p1 = (void*)distance; p2 = *(void**)buffer;
        size_t    distance;    // size of bytes.
        value_xt  buffer[CAP]; // at least IC_WORD_SIZE / 8.
        static_assert(sizeof(value_xt) * CAP >= sizeof(void*), "CAP is too small.");
    };
