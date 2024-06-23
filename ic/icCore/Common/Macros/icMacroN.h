
#pragma once

#include"./icInfo.h"

ic_info("ic_macro_xN")
    #define ic_macro_x1(Mac, t1)                                                                            Mac(t1) 
    #define ic_macro_x2(Mac, t1, t2)                                                                        Mac(t1); Mac(t2)
    #define ic_macro_x3(Mac, t1, t2, t3)                                                                    Mac(t1); Mac(t2); Mac(t3)
    #define ic_macro_x4(Mac, t1, t2, t3, t4)                                                                Mac(t1); Mac(t2); Mac(t3); Mac(t4)
    #define ic_macro_x5(Mac, t1, t2, t3, t4, t5)                                                            Mac(t1); Mac(t2); Mac(t3); Mac(t4); Mac(t5)
    #define ic_macro_x6(Mac, t1, t2, t3, t4, t5, t6)                                                        Mac(t1); Mac(t2); Mac(t3); Mac(t4); Mac(t5); Mac(t6)
    #define ic_macro_x7(Mac, t1, t2, t3, t4, t5, t6, t7)                                                    Mac(t1); Mac(t2); Mac(t3); Mac(t4); Mac(t5); Mac(t6); Mac(t7)
    #define ic_macro_x8(Mac, t1, t2, t3, t4, t5, t6, t7, t8)                                                Mac(t1); Mac(t2); Mac(t3); Mac(t4); Mac(t5); Mac(t6); Mac(t7); Mac(t8)

ic_info("ic_macro_xN_param_x2")
    #define ic_macro_x1_param_x2(Mac, a1, b1)                                                               Mac(a1, b1)
    #define ic_macro_x2_param_x2(Mac, a1, b1, a2, b2)                                                       Mac(a1, b1); Mac(a2, b2)
    #define ic_macro_x3_param_x2(Mac, a1, b1, a2, b2, a3, b3)                                               Mac(a1, b1); Mac(a2, b2); Mac(a3, b3)
    #define ic_macro_x4_param_x2(Mac, a1, b1, a2, b2, a3, b3, a4, b4)                                       Mac(a1, b1); Mac(a2, b2); Mac(a3, b3); Mac(a4, b4)
    #define ic_macro_x5_param_x2(Mac, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5)                               Mac(a1, b1); Mac(a2, b2); Mac(a3, b3); Mac(a4, b4); Mac(a5, b5)
    #define ic_macro_x6_param_x2(Mac, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6)                       Mac(a1, b1); Mac(a2, b2); Mac(a3, b3); Mac(a4, b4); Mac(a5, b5); Mac(a6, b6)
    #define ic_macro_x7_param_x2(Mac, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6, a7, b7)               Mac(a1, b1); Mac(a2, b2); Mac(a3, b3); Mac(a4, b4); Mac(a5, b5); Mac(a6, b6); Mac(a7, b7)
    #define ic_macro_x8_param_x2(Mac, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6, a7, b7, a8, b8)       Mac(a1, b1); Mac(a2, b2); Mac(a3, b3); Mac(a4, b4); Mac(a5, b5); Mac(a6, b6); Mac(a7, b7); Mac(a8, b8)

ic_info("ic_macro_xN_param_x3")
    #define ic_macro_x1_param_x3(Mac, a1, b1, c1)                                                           Mac(a1, b1, c1)
    #define ic_macro_x2_param_x3(Mac, a1, b1, c1, a2, b2, c2)                                               Mac(a1, b1, c1); Mac(a2, b2, c2)
    #define ic_macro_x3_param_x3(Mac, a1, b1, c1, a2, b2, c2, a3, b3, c3)                                   Mac(a1, b1, c1); Mac(a2, b2, c2); Mac(a3, b3, c3)
    #define ic_macro_x4_param_x3(Mac, a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4)                       Mac(a1, b1, c1); Mac(a2, b2, c2); Mac(a3, b3, c3); Mac(a4, b4, c4)

ic_info("ic_macro_xN_param_x4")
    #define ic_macro_x1_param_x4(Mac, a1, b1, c1, d1)                                                       Mac(a1, b1, c1, d1)
    #define ic_macro_x2_param_x4(Mac, a1, b1, c1, d1, a2, b2, c2, d2)                                       Mac(a1, b1, c1, d1); Mac(a2, b2, c2, d2)
    #define ic_macro_x3_param_x4(Mac, a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3)                       Mac(a1, b1, c1, d1); Mac(a2, b2, c2, d2); Mac(a3, b3, c3, d3)
    #define ic_macro_x4_param_x4(Mac, a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, a4, b4, c4, d4)       Mac(a1, b1, c1, d1); Mac(a2, b2, c2, d2); Mac(a3, b3, c3, d3) Mac(a4, b4, c4, d4)