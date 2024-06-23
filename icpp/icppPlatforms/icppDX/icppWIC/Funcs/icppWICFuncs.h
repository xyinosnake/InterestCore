
#pragma once

#include"../icppWICHeaders.h"
#include"../Macros/icppWICMacros.h"

ic_info("declarations")
    icpp_wic_dcl HRESULT ic_call icppWICCreateImagingFactory(void** ppImgFac, 
        REFCLSID CLSID_WICImgFacX ic_dfv(CLSID_WICImagingFactory1)) ic_noexc;
    
    icpp_wic_dcl HRESULT ic_call icppWICCreateFormatConverterFromDecoder(
        IWICFormatConverter**     ppWICFormatConverter,
        IWICBitmapDecoder*        pDecoder,
        IWICImagingFactory*       fac, 
        UINT                      index, 
        const WICPixelFormatGUID* pDstFormat) ic_noexc;
    
ic_info("declarations in ns") icpp_ns_x2(icpp, wic)
    icpp_t1(fac_xt) ic_inl HRESULT ic_call createImgFac(fac_xt** ppImgFac) ic_noexc;
icpp_end_ns_x2

ic_info("inl definitions in ns") icpp_ns_x2(icpp, wic)
    icpp_t1(fac_xt) ic_inl HRESULT ic_call createImgFac(fac_xt** ppImgFac) ic_noexc {
        return icppWICCreateImagingFactory((void**)ppImgFac, CLSID_WICImagingFactory1);
    }
icpp_end_ns_x2