
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Graphic/Macros/icCoreGraphicMacros.h"
#include"../../Graphic/Types/icCoreGraphicTypes.h"

ic_info("ic控制台颜色枚举") ic_def_enum(ic_console_text_color_e) {
    ic_ctc_reset_v  = 0,
    ic_ctc_hold_v   = 1,

    ic_ctc_red_v    = ic_RGB(0xFF, 0x00, 0x00),
    ic_ctc_green_v  = ic_RGB(0x00, 0xFF, 0x00),
    ic_ctc_blue_v   = ic_RGB(0x00, 0x00, 0xFF),

    ic_ctc_yellow_v = ic_RGB(0xFF, 0xFF, 0x00),
    ic_ctc_purple_v = ic_RGB(0xFF, 0x00, 0xFF),
    ic_ctc_cyan_v   = ic_RGB(0x00, 0xFF, 0xFF),

    ic_ctc_white_v  = ic_RGB(0xFF, 0xFF, 0xFF),
    ic_ctc_black_v  = ic_RGB(0x00, 0x00, 0x00),
} ic_console_text_color_e;
ic_alias(ic_ctc_e, ic_console_text_color_e);