
#pragma once

#include"./declarations.h"

ic_info("allocator")
    #include"./StaticAllocator/icppStaticAllocator.h"
    #include"./StaticThreadAllocator/icppStaticThreadAllocator.h"

ic_info("...")
    #include"./Itv/icppItv.h"
    #include"./Seg/icppSeg.h"
    #include"./P3Array/icppP3Array.h"