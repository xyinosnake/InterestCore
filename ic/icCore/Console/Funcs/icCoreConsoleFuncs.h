
#pragma once

#include"../Enums/icCoreConsoleEnums.h"
#include"../../Graphic/Types/icCoreGraphicTypes.h"
#include"../../String/icCoreString.h"

ic_info("declarations")
    #define                    icClearConsoleScreen()  printf("\033[2J\033[H")
    ic_core_dcl size_t ic_call icBgClrToS8(ch8_t* dst, RGBA_t clr) ic_noexc;
    ic_core_dcl size_t ic_call icFgClrToS8(ch8_t* dst, RGBA_t clr) ic_noexc;
    ic_core_dcl bool   ic_call icSetConsoleTextColor(RGBA_t txClr ic_dfv(ic_ctc_hold_v), RGBA_t bkClr ic_dfv(ic_ctc_hold_v)) ic_noexc;
    #define                    icResetConsoleTextColor()       icSetConsoleTextColor(ic_ctc_hold_v, ic_ctc_hold_v)
    #define                    icSetCTC                        icSetConsoleTextColor
    #define                    icResetCTC                      icResetConsoleTextColor
    ic_core_dcl bool   ic_call icSetConsoleTextColorFG(RGBA_t fgClr ic_dfv(ic_ctc_hold_v)) ic_noexc;
    ic_core_dcl bool   ic_call icSetConsoleTextColorBG(RGBA_t bgClr ic_dfv(ic_ctc_hold_v)) ic_noexc;
    #define                    icFlushConsoleWriteBuf()        icFlushStream(stdout)
    #define                    icFlushCWB()                    icFlushConsoleWriteBuf()
    #define                    icSetConsoleWriteBuf(len, mode) icSetStreamBuf(stdout, len, mode)
    #define                    icSetCWB(len, mode)             icSetConsoleWriteBuf(len, mode)

    ic_core_dcl size_t ic_call icWriteConsoleUtf8 (cch8_p  s, size_t sLen) ic_noexc;
    ic_core_dcl size_t ic_call icWriteConsoleUtf16(cch16_p s, size_t sLen) ic_noexc;
    ic_core_dcl size_t ic_call icWriteConsoleUtf32(cch32_p s, size_t sLen) ic_noexc;
    ic_inl      size_t ic_call icWriteConsoleCS8 (cch8_p  cs)  ic_noexc;
    ic_inl      size_t ic_call icWriteConsoleCS16(cch16_p cs) ic_noexc;
    ic_inl      size_t ic_call icWriteConsoleCS32(cch32_p cs) ic_noexc;

    ic_core_dcl size_t ic_call icReadConsoleUtf8 (ch8_t*  pMem, size_t bufMax) ic_noexc;
    ic_core_dcl size_t ic_call icReadConsoleUtf16(ch16_t* pMem, size_t bufMax) ic_noexc;
    ic_core_dcl size_t ic_call icReadConsoleUtf32(ch32_t* pMem, size_t bufMax) ic_noexc;

ic_info("definitions")
    ic_inl size_t ic_call icWriteConsoleCS8(cch8_p cs) ic_noexc {
        return icWriteConsoleUtf8(cs, icStrLen8 (cs));
    }

    ic_inl size_t ic_call icWriteConsoleCS16(cch16_p cs) ic_noexc {
        return icWriteConsoleUtf16(cs, icStrLen16(cs));
    }

    ic_inl size_t ic_call icWriteConsoleCS32(cch32_p cs) ic_noexc {
        return icWriteConsoleUtf32(cs, icStrLen32(cs));
    }