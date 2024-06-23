
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Common/Types/icCoreCommonTypes.h"
#include"../Types/icCoreGraphicTypes.h"
#include"../Structs/icCoreGraphicStructs.h"

ic_info("declarations")
    ic_inl RGBA_t ic_call icRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a ic_dfv(255)) ic_noexc;
    ic_inl BGRA_t ic_call icBGRA(uint8_t b, uint8_t g, uint8_t r, uint8_t a ic_dfv(255)) ic_noexc;
    ic_inl RGBA_t ic_call icRGB(uint8_t r, uint8_t g, uint8_t b) ic_noexc;
    ic_inl BGRA_t ic_call icBGR(uint8_t b, uint8_t g, uint8_t r) ic_noexc;

ic_info("inlines")
    ic_inl RGBA_t ic_call icRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) ic_noexc {
        IC_32_RGBA_U8X4 clr = { r, g, b, a };
        return *(RGBA_t*)&clr;
    }

    ic_inl BGRA_t ic_call icBGRA(uint8_t b, uint8_t g, uint8_t r, uint8_t a) ic_noexc {
        IC_32_BGRA_U8X4 clr = { b, g, r, a };
        return *(BGRA_t*)&clr;
    }

    ic_inl RGBA_t ic_call icRGB(uint8_t r, uint8_t g, uint8_t b) ic_noexc {
        return icRGBA(r, g, b, 255);
    }

    ic_inl BGRA_t ic_call icBGR(uint8_t b, uint8_t g, uint8_t r) ic_noexc {
        return icBGRA(b, g, r, 255);
    }
