
#pragma once

#include"./icInfo.h" //ic_info

/*
特别说明：
　　如果要写跨平台颜色终端程序，就是说，不只是要在Windows上使用颜色终端，
就一定要注意颜色恢复符号必须要写在换行符之前。一个颜色绝对不能换行！否则会发生意想不到的视觉Bug。
*/

ic_info("Terminal Color String")
    #define icCmdFgClr(R, G, B)                    "\x1B[38;2;" #R ";" #G ";" #B "m"
    #define icCmdBgClr(R, G, B)                    "\x1B[48;2;" #R ";" #G ";" #B "m"
    #define icCmdFgClrReset()                      "\x1B[39m"
    #define icCmdBgClrReset()                      "\x1B[49m"
    #define icCmdClr(FgR, FgG, FgB, BgR, BgG, BgB) icCmdFgClr(FgR, FgG, FgB)icCmdBgClr(BgR, BgG, BgB)
    #define icCmdClrReset()                        icCmdFgClrReset()icCmdBgClrReset()