
#pragma once

#include"../../../../ic/icCore/Common/Macros/icInfo.h"

ic_info("using xN")
    #define icpp_using_x1(ns, n1)               using ns n1
    #define icpp_using_x2(ns, n1, n2)           using ns n1; using ns n2
    #define icpp_using_x3(ns, n1, n2, n3)       using ns n1; using ns n2; using ns n3
    #define icpp_using_x4(ns, n1, n2, n3, n4)   using ns n1; using ns n2; using ns n3; using ns n4