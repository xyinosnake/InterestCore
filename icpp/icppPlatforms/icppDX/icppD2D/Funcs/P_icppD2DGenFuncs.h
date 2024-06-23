
#pragma once

#include"../../../../icpp/Common/icppCommon.h"
#include"../icppD2DHeaders.h"
#include"../Macros/icppD2DMacros.h"

ic_info("declarations")
    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_HWND_RENDER_TARGET_PROPERTIES(
        D2D1_HWND_RENDER_TARGET_PROPERTIES* pHwndRTPros,
        HWND hWnd, UINT32 pixelCx ic_dfv(0), UINT32 pixelCy ic_dfv(0),
        D2D1_PRESENT_OPTIONS presentOptions ic_dfv(D2D1_PRESENT_OPTIONS_NONE)
    ) ic_noexc;

    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_PIXEL_FORMAT(
        D2D1_PIXEL_FORMAT* pPixelFormat,
        DXGI_FORMAT        dxgiFormat ic_dfv(DXGI_FORMAT_UNKNOWN),
        D2D1_ALPHA_MODE    alphaMode  ic_dfv(D2D1_ALPHA_MODE_UNKNOWN)
    ) ic_noexc;

    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_RENDER_TARGET_PROPERTIES(
        D2D1_RENDER_TARGET_PROPERTIES* pRTProps,
        D2D1_RENDER_TARGET_TYPE        type       ic_dfv(D2D1_RENDER_TARGET_TYPE_DEFAULT),
        DXGI_FORMAT                    dxgiFormat ic_dfv(DXGI_FORMAT_UNKNOWN),
        D2D1_ALPHA_MODE                alphaMode  ic_dfv(D2D1_ALPHA_MODE_UNKNOWN),
        FLOAT                          dpiX       ic_dfv(0.0f),
        FLOAT                          dpiY       ic_dfv(0.0f),
        D2D1_RENDER_TARGET_USAGE       usage      ic_dfv(D2D1_RENDER_TARGET_USAGE_NONE),
        D2D1_FEATURE_LEVEL             minLevel   ic_dfv(D2D1_FEATURE_LEVEL_DEFAULT)
    ) ic_noexc;