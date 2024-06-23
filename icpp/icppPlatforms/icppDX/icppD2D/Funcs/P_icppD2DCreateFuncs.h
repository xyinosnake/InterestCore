
#pragma once

#include"../../../../icpp/Common/icppCommon.h"
#include"../icppD2DHeaders.h"
#include"../Macros/icppD2DMacros.h"

ic_info("declarations")
    icpp_d2d_dcl HRESULT ic_call icppD2DCreateHwndRT(
        ID2D1HwndRenderTarget**  ppD2D1HwndRT,
        ID2D1Factory*            pFac,
        HWND                     hWnd           ic_dfv(0),
        D2D_SIZE_U               pixelCxy       ic_dfv(D2D_SIZE_U{ 0, 0 }),
        D2D1_PRESENT_OPTIONS     presentOptions ic_dfv(D2D1_PRESENT_OPTIONS_NONE),
        D2D1_RENDER_TARGET_TYPE  type           ic_dfv(D2D1_RENDER_TARGET_TYPE_DEFAULT),
        DXGI_FORMAT              dxgiFormat     ic_dfv(DXGI_FORMAT_UNKNOWN),
        D2D1_ALPHA_MODE          alphaMode      ic_dfv(D2D1_ALPHA_MODE_UNKNOWN),
        FLOAT                    dpiX           ic_dfv(0.0f),
        FLOAT                    dpiY           ic_dfv(0.0f),
        D2D1_RENDER_TARGET_USAGE usage          ic_dfv(D2D1_RENDER_TARGET_USAGE_NONE),
        D2D1_FEATURE_LEVEL       minLevel       ic_dfv(D2D1_FEATURE_LEVEL_DEFAULT)
    ) ic_noexc;

    icpp_d2d_dcl HRESULT ic_call icppD2DCreateBitmapFromFile(
        ID2D1Bitmap**       ppD2D1Bitmap,
        ID2D1RenderTarget*  pRT, 
        IWICImagingFactory* pFac,
        const WCHAR*        FileName,
        UINT                FrameNum ic_dfv(0),
        DXGI_FORMAT         PxFm     ic_dfv(DXGI_FORMAT_UNKNOWN)
    ) ic_noexc;

ic_info("declarations in ns") icpp_ns_x2(icpp, d2d)
    icpp_t1(ID2D1Fac_xt) ic_inl HRESULT ic_call createFac(ID2D1Fac_xt** ppFac,
        D2D1_FACTORY_TYPE facType ic_dfv(D2D1_FACTORY_TYPE_MULTI_THREADED),
        D2D1_DEBUG_LEVEL  dbLevel ic_dfv(ICPP_D2D_DEFAULT_DEBUG_LEVEL)
    ) ic_noexc;
icpp_end_ns_x2

ic_info("definitionss") icpp_ns_x2(icpp, d2d)
    icpp_t1(ID2D1Fac_xt) ic_inl HRESULT ic_call createFac(ID2D1Fac_xt** ppFac,
        D2D1_FACTORY_TYPE facType, D2D1_DEBUG_LEVEL dbLevel) ic_noexc {
        return D2D1CreateFactory(facType, __uuidof(ID2D1Fac_xt),
            (const D2D1_FACTORY_OPTIONS*)&dbLevel, reinterpret_cast<void**>(ppFac));
    }
icpp_end_ns_x2