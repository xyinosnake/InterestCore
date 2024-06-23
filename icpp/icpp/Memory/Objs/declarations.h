
#pragma once

#include"../../Common/icppCommon.h"

ic_info("declarations")
    class icppStaticAllocator;               //static allocator
    class icppStaticAllocator2;              //static allocator 2
    class icppStaticCountedAllocator;        //static counted allocator
    class icppStaticCountedAllocator2;       //static counted allocator 2
    class icppStaticPosixAllocator;          //static posix allocator
    class icppStaticPosixAllocator2;         //static posix allocator 2
    class icppStaticCountedPosixAllocator;   //static posix allocator
    class icppStaticCountedPosixAllocator2;  //static posix allocator 2
    class icppStaticThreadAllocator;         //static thread allocator
    class icppStaticThreadAllocator2;        //static thread allocator 2
    class icppStaticCountedThreadAllocator;  //static thread allocator
    class icppStaticCountedThreadAllocator2; //static thread allocator 2
    icpp_t1(elem_xt) class icppItvG;         //interval G
    icpp_alias(icppItv, icppItvG<void>);     //interval
    icpp_t1(elem_xt) class icppSegG;         //segment G
    icpp_alias(icppSeg, icppSegG<void>);     //segment
    icpp_t2(elem_xt, staticAlloc_xt = icppStaticAllocator)
        class icppP3ArrayG;                  //P3 array

ic_info("in ns alias") icpp_ns_x1(icpp)
    icpp_alias(StaticAllocator,        icppStaticAllocator);
    icpp_alias(StaticAllocator2,       icppStaticAllocator2);
    icpp_alias(StaticThreadAllocator,  icppStaticThreadAllocator);
    icpp_alias(StaticThreadAllocator2, icppStaticThreadAllocator2);
    icpp_t1(elem_xt) icpp_alias(ItvG, icppItvG<elem_xt>);
                     icpp_alias(Itv, icppItv);
    icpp_t1(elem_xt) icpp_alias(SegG, icppSegG<elem_xt>);
                     icpp_alias(Seg, icppSeg);
    icpp_t2(elem_xt, staticAlloc_xt = icppStaticAllocator)
        icpp_alias(P3ArrayG, icppP3ArrayG<elem_xt, staticAlloc_xt>);
icpp_end_ns_x1