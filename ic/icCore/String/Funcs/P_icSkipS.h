
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("declarations")
    ic_core_dcl ch8_p  ic_call icSkipSpaces8 (cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icSkipSpaces16(cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icSkipSpaces32(cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl ch8_p  ic_call icSkipGraphs8 (cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icSkipGraphs16(cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icSkipGraphs32(cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl ch8_p  ic_call icSkipSpacesBackward8 (cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icSkipSpacesBackward16(cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icSkipSpacesBackward32(cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl ch8_p  ic_call icSkipGraphsBackward8 (cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icSkipGraphsBackward16(cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icSkipGraphsBackward32(cch32_p bg, cch32_p ed) ic_noexc;