
#ifndef ICPP_WIC_FUNCS
#define ICPP_WIC_FUNCS

#include"./icppWICFuncs.h"

ic_info("definitions")
    icpp_wic_dcl HRESULT ic_call icppWICCreateImagingFactory(void** ppImgFac, REFCLSID CLSID_WICImgFacX) ic_noexc {
        return CoCreateInstance(CLSID_WICImgFacX, NULL, CLSCTX_INPROC_SERVER, 
            IID_IWICImagingFactory, (void**)ppImgFac);
    }

    icpp_wic_dcl HRESULT ic_call icppWICCreateFormatConverterFromDecoder(
        IWICFormatConverter**     ppWICFormatConverter,
        IWICBitmapDecoder*        pDecoder,
        IWICImagingFactory*       fac, 
        UINT                      index, 
        const WICPixelFormatGUID* pDstFormat) ic_noexc {
        HRESULT                r;
        IWICBitmapFrameDecode* pFrameDecode = NULL; /*/帧解码器/*/
        r = pDecoder->GetFrame(index, &pFrameDecode);
        ic_if_goto(FAILED(r), pos_End);
        IWICFormatConverter* pWICFormatConverter;
        r = fac->CreateFormatConverter(&pWICFormatConverter);
        ic_if_goto(FAILED(r), pos_End);
        *ppWICFormatConverter = pWICFormatConverter;
        r = pWICFormatConverter->Initialize(
            pFrameDecode,
            *pDstFormat,               // 仅支持三种格式，其他格式暂不支持...
            WICBitmapDitherTypeNone,   // 抖动，一般设为None，其他选项意义不明。
            NULL, 0.0f,
            WICBitmapPaletteTypeCustom // 调色板，可以肯定除非有调色板，否则无用。
        );
    pos_End:
        ic_if_do(pFrameDecode, pFrameDecode->Release());
        return r;
    }
#endif