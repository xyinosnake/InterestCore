
module icd.common.macros.cmd_color;

mixin(ic_info("import"));
    import std.conv;
    import icd.common.macros.info;
    import icd.common.types.value_types;

/*
特别说明：
　　如果要写跨平台颜色终端程序，就是说，不只是要在Windows上使用颜色终端，
就一定要注意颜色恢复符号必须要写在换行符之前。一个颜色绝对不能换行！否则会发生意想不到的视觉Bug。
*/

mixin(ic_info("declarations - Terminal Color String"));
    string icCmdFgClr(uint8_t R, uint8_t G, uint8_t B);
    string icCmdBgClr(uint8_t R, uint8_t G, uint8_t B);
    string icCmdFgClrReset();
    string icCmdBgClrReset();
    string icCmdClr(uint8_t FgR, uint8_t FgG, uint8_t FgB, uint8_t BgR, uint8_t BgG, uint8_t BgB);
    string icCmdClrReset();

mixin(ic_info("definitions - Terminal Color String"));
    string icCmdFgClr(uint8_t R, uint8_t G, uint8_t B) {
        return "\x1B[38;2;" ~ to!string(R) ~ ";" ~ to!string(G) ~ ";" ~ to!string(B) ~ "m";
    }

    string icCmdBgClr(uint8_t R, uint8_t G, uint8_t B) {
        return "\x1B[48;2;" ~ to!string(R) ~ ";" ~ to!string(G) ~ ";" ~ to!string(B) ~ "m";
    }

    string icCmdFgClrReset() {
        return "\x1B[39m";
    }

    string icCmdBgClrReset() {
        return "\x1B[49m";
    }

    string icCmdClr(uint8_t FgR, uint8_t FgG, uint8_t FgB, uint8_t BgR, uint8_t BgG, uint8_t BgB) {
        return icCmdFgClr(FgR, FgG, FgB) ~ icCmdBgClr(BgR, BgG, BgB);
    }

    string icCmdClrReset() {
        return icCmdFgClrReset() ~ icCmdBgClrReset();
    }