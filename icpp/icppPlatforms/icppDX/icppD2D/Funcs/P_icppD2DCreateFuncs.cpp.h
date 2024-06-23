
#pragma once

#include"./P_icppD2DCreateFuncs.h"
#include"./P_icppD2DGenFuncs.h"
#include"../../icppDXC/Funcs/icppDXCFuncs.h"
#include"../../icppWIC/Funcs/icppWICFuncs.h"

ic_info("definitions")
    icpp_d2d_dcl HRESULT ic_call icppD2DCreateHwndRT(
        ID2D1HwndRenderTarget**  ppD2D1HwndRT,
        ID2D1Factory*            pFac,
        HWND                     hWnd,
        D2D_SIZE_U               pixelCxy,
        D2D1_PRESENT_OPTIONS     presentOptions,
        D2D1_RENDER_TARGET_TYPE  type,
        DXGI_FORMAT              dxgiFormat,
        D2D1_ALPHA_MODE          alphaMode,
        FLOAT                    dpiX,
        FLOAT                    dpiY,
        D2D1_RENDER_TARGET_USAGE usage,
        D2D1_FEATURE_LEVEL       minLevel) ic_noexc {
        ic_if_do(*(UINT64*)&pixelCxy == 0, ic_if_return(!icWin32GetClientSize((SIZE*)&pixelCxy, hWnd), E_FAIL));
        D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRTProps;
        D2D1_RENDER_TARGET_PROPERTIES      RTProps;
        icppD2DGen_D2D1_HWND_RENDER_TARGET_PROPERTIES(&hwndRTProps,
            hWnd, pixelCxy.width, pixelCxy.height, presentOptions);
        icppD2DGen_D2D1_RENDER_TARGET_PROPERTIES(&RTProps,
            type, dxgiFormat, alphaMode, dpiX, dpiY, usage, minLevel);
        return pFac->CreateHwndRenderTarget(&RTProps, &hwndRTProps, ppD2D1HwndRT);
    }

#if 1
    icpp_d2d_dcl HRESULT ic_call icppD2DCreateBitmapFromFile(
          ID2D1Bitmap**       ppD2D1Bitmap,
          ID2D1RenderTarget*  pRT, 
          IWICImagingFactory* pFac,
    const WCHAR*              FileName, 
          UINT                FrameNum,
          DXGI_FORMAT         PxFm
    ) ic_noexc {
        HRESULT                   r;
        IWICBitmapDecoder*        pDecoder = NULL; //解码器
        IWICFormatConverter*      pFc      = NULL; //转换器
        const WICPixelFormatGUID* wicPxFm;
        ic_if_do(PxFm == DXGI_FORMAT_UNKNOWN, PxFm = pRT->GetPixelFormat().format);
        wicPxFm = icppDXCConvertDXGIPixelFormatToWICPixelFormat(PxFm);
        ic_if_do_and_goto(wicPxFm == NULL, r = E_FAIL, pos_End);
        r = pFac->CreateDecoderFromFilename(
            FileName, NULL, GENERIC_READ,
            WICDecodeMetadataCacheOnDemand, //节省内存
            &pDecoder);
        ic_if_goto(FAILED(r), pos_End);
        r = icppWICCreateFormatConverterFromDecoder(&pFc,
            pDecoder, pFac, FrameNum, wicPxFm);
        ic_if_goto(FAILED(r), pos_End);
        r = pRT->CreateBitmapFromWicBitmap(pFc, ppD2D1Bitmap);
    pos_End:
        ic_if_do(pDecoder, pDecoder->Release());
        ic_if_do(pFc,      pFc->Release());
        return r;
    }
#endif