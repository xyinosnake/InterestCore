
#pragma once

#include"../../../../ic/icCore/Common/Macros/icInfo.h"

ic_info("icpp_namespace_xN")
    #define icpp_namespace_x1(n1)                               namespace n1 {
    #define icpp_namespace_x2(n1, n2)                           namespace n1 { namespace n2 {
    #define icpp_namespace_x3(n1, n2, n3)                       namespace n1 { namespace n2 { namespace n3 {
    #define icpp_namespace_x4(n1, n2, n3, n4)                   namespace n1 { namespace n2 { namespace n3 { namespace n4 {
    #define icpp_namespace_x5(n1, n2, n3, n4, n5)               namespace n1 { namespace n2 { namespace n3 { namespace n4 { namespace n5 {
    #define icpp_namespace_x6(n1, n2, n3, n4, n5, n6)           namespace n1 { namespace n2 { namespace n3 { namespace n4 { namespace n5 { namespace n6 {
    #define icpp_namespace_x7(n1, n2, n3, n4, n5, n6, n7)       namespace n1 { namespace n2 { namespace n3 { namespace n4 { namespace n5 { namespace n6 { namespace n7 {
    #define icpp_namespace_x8(n1, n2, n3, n4, n5, n6, n7, n8)   namespace n1 { namespace n2 { namespace n3 { namespace n4 { namespace n5 { namespace n6 { namespace n7 { namespace n8 {

ic_info("icpp_end_namespace_xN")
    #define icpp_end_namespace_x1   }
    #define icpp_end_namespace_x2   }}
    #define icpp_end_namespace_x3   }}}
    #define icpp_end_namespace_x4   }}}}
    #define icpp_end_namespace_x5   }}}}}
    #define icpp_end_namespace_x6   }}}}}}
    #define icpp_end_namespace_x7   }}}}}}}
    #define icpp_end_namespace_x8   }}}}}}}}

ic_info("micro keyword")
    #define icpp_ns_x1 icpp_namespace_x1
    #define icpp_ns_x2 icpp_namespace_x2
    #define icpp_ns_x3 icpp_namespace_x3
    #define icpp_ns_x4 icpp_namespace_x4
    #define icpp_ns_x5 icpp_namespace_x5
    #define icpp_ns_x6 icpp_namespace_x6
    #define icpp_ns_x7 icpp_namespace_x7
    #define icpp_ns_x8 icpp_namespace_x8

ic_info("micro keyword")
    #define icpp_end_ns_x1 icpp_end_namespace_x1
    #define icpp_end_ns_x2 icpp_end_namespace_x2
    #define icpp_end_ns_x3 icpp_end_namespace_x3
    #define icpp_end_ns_x4 icpp_end_namespace_x4
    #define icpp_end_ns_x5 icpp_end_namespace_x5
    #define icpp_end_ns_x6 icpp_end_namespace_x6
    #define icpp_end_ns_x7 icpp_end_namespace_x7
    #define icpp_end_ns_x8 icpp_end_namespace_x8