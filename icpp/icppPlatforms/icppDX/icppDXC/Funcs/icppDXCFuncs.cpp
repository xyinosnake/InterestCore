
#ifndef ICPP_DXC_FUNCS
#define ICPP_DXC_FUNCS

#include"./icppDXCFuncs.h"

ic_info("definitions")
    icpp_dxc_dcl const WICPixelFormatGUID* ic_call icppDXCConvertDXGIPixelFormatToWICPixelFormat(DXGI_FORMAT fm) ic_noexc {
        const WICPixelFormatGUID* pPxFm;
        switch (fm) {
    #define case_m(dxgi, wic) case dxgi: pPxFm = &wic; break;
            case_m(DXGI_FORMAT_UNKNOWN,			   GUID_WICPixelFormatDontCare);
            case_m(DXGI_FORMAT_R8G8B8A8_UNORM,	   GUID_WICPixelFormat32bppPRGBA);
            case_m(DXGI_FORMAT_B8G8R8A8_UNORM,	   GUID_WICPixelFormat32bppPBGRA);
            case_m(DXGI_FORMAT_R32G32B32A32_FLOAT, GUID_WICPixelFormat128bppPRGBAFloat);
            default: pPxFm = nullptr; break;
    #undef case_m
        }
        return pPxFm;
    }
#endif