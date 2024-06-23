
#pragma once

#include"./icInfo.h" //ic_info

ic_info("macros")
    #include"./icTopmost.h"        // IC Topmost 置顶宏
    #include"./ic-Config.h"        // IC Config(Gen By CMake)
    #include"./icEnv.h"            // IC Environment Macros 环境宏（字长、操作系统等）
    #include"./icCoreLink.h"       // IC Core Link
    #include"./icMacroN.h"         // IC Macro xN
    #include"./icInline.h"         // IC Inline
    #include"./icThreadOwn.h"      // IC ThreadOwn
    #include"./ic_noXX.h"          // IC Noexcept & Nodiscard
    #include"./icAlign.h"          // IC Align & Alignof
    #include"./icCmdColor.h"       // IC Terminal Command Line Color (New - 24.05.27)
    #include"./icCmdEscapeCode.h"  // IC Terminal Command Line Escape Code (New - 24.06.22)
    #include"./icSetMembers.h"     // IC Set Members (New - 24.06.07)

ic_info("ic_deprecated（弃用警告）")
    #if defined(IC_CE_MSC)
        #define ic_deprecated(msg)         __declspec(deprecated(msg))
    #elif defined(IC_CE_GNUC)
        #define ic_deprecated(msg)         __attribute__((deprecated))
    #else
        #define ic_deprecated(msg)
    #endif

ic_info("缺陷与Bug")
    ic_info("defect")
    ic_info("bug")

ic_info("ic_null & ic_nothing")
    #ifdef __cplusplus
        #define ic_null 0
    #else
        #define ic_null ((void*)0)
    #endif
    #define ic_nothing

ic_info("single")
    #define ic_single(...)                 __VA_ARGS__
    #define ic_sg                          ic_single

ic_info("C++参数默认值")
    #ifdef __cplusplus
        #define ic_default_value(...)      = __VA_ARGS__
    #else
        #define ic_default_value(...)
    #endif
    #define ic_dfv                         ic_default_value

ic_info("ic_target(GNUC)")
    #if defined(IC_CE_GNUC) || defined(IC_CE_CLANG)
        #define ic_target(...) __attribute__((target(__VA_ARGS__)))
    #else
        #define ic_target(...)
    #endif
    #define ic_tgt ic_target

ic_info("ic_alias")
    #define ic_alias(name, target)         typedef target name
    #define ic_dcl_struct(name)            typedef struct name name
    #define ic_dcl_union(name)             typedef union name name
    #define ic_dcl_f(name, callWay, rtn_t) typedef rtn_t(callWay* name)
    #define ic_def_enum(name)              typedef enum name

ic_info("宽 & 窄")
    #define ic_w(s)                        L##s
    #define ic_n(s)                           s
    #define icW(s)                         L##s
    #define icN(s)                            s
    #ifdef IC_OS_WINDOWS
        #define icA(s)                        s
    #endif

ic_info("循环辅助关键字")
    #define ic_for_times(n)                for (uint64_t ic_times = 0; ic_times < n; ++ic_times)
    #define ic_loop()                      while (true)

ic_info("无条件集成")
    #define ic_init_x1(i1)                           i1
    #define ic_init_x2(i1, i2)                       i1; i2
    #define ic_init_x3(i1, i2, i3)                   i1; i2; i3
    #define ic_do_and_goto(d, pos)                   d; goto pos
    #define ic_do_and_break(d)                       d; break
    #define ic_do_and_return(d, r)                   d; return r
    #define ic_do_x1(d1)                             d1
    #define ic_do_x2(d1, d2)                         d1; d2
    #define ic_do_x3(d1, d2, d3)                     d1; d2; d3
    #define ic_do_x4(d1, d2, d3, d4)                 d1; d2; d3; d4
    #define ic_do_x5(d1, d2, d3, d4, d5)             d1; d2; d3; d4; d5
    #define ic_label_do(label, d)                    label: d
    #define ic_label_return(label, r)                label: return r
    #define ic_label_do_and_return(label, d, r)      label: d; return r
    #define ic_swap(type_xt, va, vb)                 { type_xt __ic_H_tempVal = va; va = vb; vb = __ic_H_tempVal; } // 交换va和vb的值。
    #define ic_swap_ptr(type_xt, pa, pb)             ic_swap(type_xt, *pa, *pb)
    #define ic_swap_obj(pTempObj, pOA, pOB, fAssign) { fAssign(pTempObj, pOA); fAssign(pOA, pOB); fAssign(pOB, pTempObj); } // 交换oa和ob的值。
    #define ic_greater(a, b)                          ((a) > (b) ? (a) : (b))
    #define ic_less(a, b)                             ((a) < (b) ? (a) : (b))

ic_info("断言")
    #ifdef IC_DEBUG
        #define ic_assert(b, msg)          icAssert((bool)(b), #b, msg,  __FUNCTION__, NULL, __FILE__, __LINE__, __TIMESTAMP__)
    #else
        #define ic_assert(b, msg)
    #endif

ic_info("line")
    #define ic_line_x2(x1, x2)             x1; x2;
    #define ic_line_x3(x1, x2, x3)         x1; x2; x3; 
    #define ic_line_x4(x1, x2, x3, x4)     x1; x2; x3; x4; 
    #define ic_line_x5(x1, x2, x3, x4, x5) x1; x2; x3; x4; x5

ic_info("inc & dec")
    #define ic_inc_x2(xx1, xx2)            ++xx1; ++xx2
    #define ic_inc_x3(xx1, xx2, xx3)       ++xx1; ++xx2; ++xx3
    #define ic_dec_x2(xx1, xx2)            --xx1; --xx2
    #define ic_dec_x3(xx1, xx2, xx3)       --xx1; --xx2; --xx3

ic_info("stv(same type value)")
    #define ic_stv_x1(t, v1)                             t v1
    #define ic_stv_x2(t, v1, v2)                         t v1; t v2
    #define ic_stv_x3(t, v1, v2, v3)                     t v1; t v2; t v3
    #define ic_stv_x4(t, v1, v2, v3, v4)                 t v1; t v2; t v3; t v4
    #define ic_stv_x5(t, v1, v2, v3, v4, v5)             t v1; t v2; t v3; t v4; t v5
    #define ic_stv_x6(t, v1, v2, v3, v4, v5, v6)         t v1; t v2; t v3; t v4; t v5; t v6
    #define ic_stv_x7(t, v1, v2, v3, v4, v5, v6, v7)     t v1; t v2; t v3; t v4; t v5; t v6; t v7
    #define ic_stv_x8(t, v1, v2, v3, v4, v5, v6, v7, v8) t v1; t v2; t v3; t v4; t v5; t v6; t v7; t v8

ic_info("条件集成")
    #define ic_init_if(i, b)                        i; if (b)                               // 初始化并判定。
    #define ic_if_do(b, d)                          if (b) { d; }                           // 如果条件b为真，执行d。
    #define ic_if_do_x2(b, d1, d2)                  if (b) { d1; d2; }                      // 如果条件b为真，执行d1、d2。
    #define ic_if_do_x3(b, d1, d2, d3)              if (b) { d1; d2; d3; }                  // 如果条件b为真，执行d1、d2、d3。
    #define ic_if_do_and_goto(b, d, pos)            if (b) { d; goto pos; }                 // 如果条件b为真，执行d，并跳转到pos处。
    #define ic_if_do_and_return(b, d, r)            if (b) { d; return r; }                 // 如果条件b为真，执行d，并返回r。
    #define ic_if_do_and_break(b, d)                if (b) { d; break; }                    // 如果条件b为真，执行d，并break。
    #define ic_if_do_x2_and_goto(b, d1, d2, pos)    if (b) { d1; d2; goto pos; }            // 如果条件b为真，执行d1、d2，并跳转到pos处。
    #define ic_if_do_x2_and_return(b, d1, d2, r)    if (b) { d1; d2; return r; }            // 如果条件b为真，执行d1、d2，并返回r。
    #define ic_if_do_x2_and_break(b, d1, d2)        if (b) { d1; d2; break; }               // 如果条件b为真，执行d1、d2，并break。
    #define ic_if_else_do(b, da, db)                if (b) { da; } else { db; }             // 如果条件b为真，执行da，否则执行db。
    #define ic_if_else_do_x2(b, da1, da2, db1, db2) if (b) { da1; da2; } else { db1; db2; } // 如果条件b为真，执行da1、da2，否则执行db1、db2。
    #define ic_if_goto(b, pos)                      if (b) { goto pos; }                    // 如果条件b为真，就跳跃至pos处。
    #define ic_if_return(b, value)                  if (b) { return value; }                // 如果条件b为真，返回value。
    #define ic_if_break(b)                          if (b) { break; }                       // 如果条件b为真，就break。
    #define ic_if_continue(b)                       if (b) { continue; }                    // 如果条件b为真，就continue。
    #define ic_if_else_return(b, ra, rb)            return ((b) ? (ra) : (rb))              // 如果条件b为真，返回ra，否则返回rb。
    #define ic_if_do_else_if_do(b1, d1, b2, d2)     if (b1) { d1; } else if (b2) { d2; }    // 如果b1，执行d1，否则如果b2，执行d2。
    #define ic_if_swap(b, type_xt, va, vb)          if (b) ic_swap(type_xt, va, vb)         // 如果条件b为真，就交换va和vb的值。
    #define ic_else_do(d)                           else { d; }                             // 否则执行d。
    #define ic_else_do_x2(d1, d2)                   else { d1; d2; }                        // 否则执行d1、d2。
    #define ic_else_do_x3(d1, d2, d3)               else { d1; d2; d3; }                    // 否则执行d1、d2、d3。
    #define ic_else_do_x4(d1, d2, d3, d4)           else { d1; d2; d3; d4 }                 // 否则执行d1、d2、d3、d4。
    #define ic_else_goto(pos)                       else { goto pos; }                      // 否则跳转到pos处。
    #define ic_else_return(r)                       else { return r; }                      // 否则返回r。
    #define ic_init_if_do(i, b, d)                  i; if (b) { d; }                        // 执行i，如果条件b为真，执行d。
    #define ic_init_if_do_x2(i, b, d1, d2)          i; if (b) { d1; d2; }                   // 执行i，如果条件b为真，执行d1、d2。
    #define ic_init_if_do_x3(i, b, d1, d2, d3)      i; if (b) { d1; d2; d3; }               // 执行i，如果条件b为真，执行d1、d2、d3。
    #define ic_init_if_return(i, b, value)          i; if (b) { return value; }             // 执行i，如果条件b为真，返回value。

ic_info("while")
    #define ic_while_do(b, d)                               while(b) { d; }                      //满足条件b，循环执行d。
    #define ic_while_do_return(b, d, r)                     while(b) { d; } return r             //满足条件b，循环执行d。返回r。
    #define ic_while_do_x2(b, d1, d2)                       while(b) { d1; d2; }                 //满足条件b，循环执行d1、d2。
    #define ic_while_do_x2_return(b, d1, d2, r)             while(b) { d1; d2; } return r        //满足条件b，循环执行d1、d2。返回r。
    #define ic_while_do_x3(b, d1, d2, d3)                   while(b) { d1; d2; d3; }             //满足条件b，循环执行d1、d2、d3。
    #define ic_while_do_x3_return(b, d1, d2, d3, r)         while(b) { d1; d2; d3; } return r    //满足条件b，循环执行d1、d2、d3。返回r。
    #define ic_init_while_do(i, b, d)                       i; while(b) { d; }                   //满足条件b，循环执行d。
    #define ic_init_while_do_return(i, b, d, r)             i; while(b) { d; } return r          //初始化i。满足条件b，循环执行d。返回r。
    #define ic_init_while_do_x2(i, b, d1, d2)               i; while(b) { d1; d2; }              //初始化i。满足条件b，循环执行d1、d2。
    #define ic_init_while_do_x2_return(i, b, d1, d2, r)     i; while(b) { d1; d2; } return r     //初始化i。满足条件b，循环执行d1、d2。返回r。
    #define ic_init_while_do_x3(i, b, d1, d2, d3)           i; while(b) { d1; d2; d3; }          //初始化i。满足条件b，循环执行d1、d2、d3。
    #define ic_init_while_do_x3_return(i, b, d1, d2, d3, r) i; while(b) { d1; d2; d3; } return r //初始化i。满足条件b，循环执行d1、d2、d3。返回r

ic_info("do while")
    #define ic_do_while(d, b)                           do { d; } while(b)
    #define ic_do_while_return(d, b, r)                 do { d; } while(b); return r
    #define ic_do_x2_while(d1, d2, b)                   do { d1; d2; } while(b)
    #define ic_do_x2_while_return(d1, d2, b, r)         do { d1; d2; } while(b); return r
    #define ic_init_do_while(i, d, b)                   i; do { d; } while(b)
    #define ic_init_do_while_return(i, d, b, r)         i; do { d; } while(b); return r
    #define ic_init_do_x2_while(i, d1, d2, b)           i; do { d1; d2; } while(b)
    #define ic_init_do_x2_while_return(i, d1, d2, b, r) i; do { d1; d2; } while(b); return r

ic_info("for")
    #define ic_for_do(i, b, e, d)                       for (i; b; e) { d; }
    #define ic_for_do_x2(i, b, e, d1, d2)               for (i; b; e) { d1; d2; }

ic_info("main函数")
    #define ic_def_main( args, nArgs)    int ic_call  main(int nArgs,  char  ** args) ic_noexc
    #define ic_def_wmain(args, nArgs)    int ic_call wmain(int nArgs, wchar_t** args) ic_noexc