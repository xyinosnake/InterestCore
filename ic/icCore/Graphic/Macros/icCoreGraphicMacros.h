
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../Types/icCoreGraphicTypes.h"

ic_info("RGBA & BGRA")
    #define ic_RGBA(r, g, b, a)     ((RGBA_t)(((uint8_t)(r) | ((uint16_t)((uint8_t)(g)) << 8)) | (((uint32_t)(uint8_t)(b)) << 16) | (((uint32_t)(uint8_t)(a)) << 24)))
    #define ic_BGRA(b, g, r, a)     ((BGRA_t)(((uint8_t)(b) | ((uint16_t)((uint8_t)(g)) << 8)) | (((uint32_t)(uint8_t)(r)) << 16) | (((uint32_t)(uint8_t)(a)) << 24)))
    #define ic_RGB(r, g, b)         ((RGBA_t)(((uint8_t)(r) | ((uint16_t)((uint8_t)(g)) << 8)) | (((uint32_t)(uint8_t)(b)) << 16) | 0xFF000000))
    #define ic_BGR(b, g, r)         ((BGRA_t)(((uint8_t)(b) | ((uint16_t)((uint8_t)(g)) << 8)) | (((uint32_t)(uint8_t)(r)) << 16) | 0xFF000000))