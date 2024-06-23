
#pragma once

#include"./P_icppD2DGenFuncs.h"

ic_info("definitions")
    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_HWND_RENDER_TARGET_PROPERTIES(
        D2D1_HWND_RENDER_TARGET_PROPERTIES* pHwndRTPros,
        HWND hWnd, UINT32 pixelCx, UINT32 pixelCy,
        D2D1_PRESENT_OPTIONS presentOptions
    ) ic_noexc {
        ic_spm_x4(pHwndRTPros, hwnd = hWnd, 
            pixelSize.width = pixelCx, pixelSize.height = pixelCy,
            presentOptions = presentOptions);
    }

    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_PIXEL_FORMAT(D2D1_PIXEL_FORMAT* pPixelFormat, 
        DXGI_FORMAT dxgiFormat, D2D1_ALPHA_MODE alphaMode) ic_noexc {
        ic_spm_x2(pPixelFormat, format = dxgiFormat, alphaMode = alphaMode);
    }

    icpp_d2d_dcl void ic_call icppD2DGen_D2D1_RENDER_TARGET_PROPERTIES(
        D2D1_RENDER_TARGET_PROPERTIES* pRTProps,D2D1_RENDER_TARGET_TYPE type,
        DXGI_FORMAT dxgiFormat, D2D1_ALPHA_MODE alphaMode,
        FLOAT dpiX, FLOAT dpiY, D2D1_RENDER_TARGET_USAGE usage,
        D2D1_FEATURE_LEVEL minLevel) ic_noexc {
        ic_spm_x7(pRTProps, type = type, 
            pixelFormat.format = dxgiFormat,
            pixelFormat.alphaMode = D2D1_ALPHA_MODE_UNKNOWN,
            dpiX = dpiX, dpiY = dpiY, usage = usage, minLevel = minLevel);
    }