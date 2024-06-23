
#pragma once

#include"./icInfo.h" //ic_info

/*
说明：
    禁用按键回显估计可以用于密码。尚未测试。
*/

ic_info("Escape Code")
    ic_info("Clear - 清除屏幕，并将光标移动到左上角")
        #define icCmdClear()             "\033[2J"
    ic_info("Reset - 重置文本格式（下划线、删除线、加粗、前景色、背景色）")
        #define icCmdReset()             "\033[0m"
    ic_info("Underline - 下划线")
        #define icCmdUnderline()         "\033[4m"
        #define icCmdUnderlineReset()    "\033[24m"
    ic_info("Strickout - 删除线")
        #define icCmdStrickout()         "\033[9m"
        #define icCmdStrickoutReset()    "\033[29m"
    ic_info("Overstriking - 加粗")
        #define icCmdOverstriking()      "\033[1m"
        #define icCmdOverstrikingReset() "\033[22m"
    ic_info("KeyEcho - 按键回显")
        #define icCmdEnableKeyEcho()     "\033[?1h"
        #define icCmdDisableKeyEcho()    "\033[?1l"
    ic_info("Cursor - 光标")
        #define icCmdShowCursor()        "\033[?25h"
        #define icCmdHideCursor()        "\033[?25l"