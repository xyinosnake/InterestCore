
#ifndef ICPP_DWRITE_FUNCS
#define ICPP_DWRITE_FUNCS

#include"./icppDWriteFuncs.h"

ic_info("definitions")
    icpp_dwrite_dcl HRESULT ic_call icppDWriteSetNormalLineSpacing(IDWriteTextFormat* pTextFormat, IDWriteFactory* pFac) ic_noexc {
        HRESULT             r;
        IDWriteTextLayout*  pTextLayout;
        DWRITE_TEXT_METRICS met;
        WCHAR               c = L'A';
        r = pFac->CreateTextLayout(&c, 1, pTextFormat, 32768.0f, 32768.0f, &pTextLayout);
        ic_if_return(FAILED(r), r);
        r = pTextLayout->GetMetrics(&met);
        ic_if_goto(FAILED(r), pos_Err);
        r = pTextFormat->SetLineSpacing(DWRITE_LINE_SPACING_METHOD_UNIFORM, met.height, met.height * 0.8f); // A reasonable ratio to lineSpacing is 80%.
        ic_if_goto(FAILED(r), pos_Err);
        return r;
    pos_Err:
        ic_do_and_return(pTextLayout->Release(), r);
    }

    icpp_dwrite_dcl HRESULT ic_call icppDWriteCreateTextFormat(
        IDWriteTextFormat**    ppTxFm,
        IDWriteFactory*        pFac, 
        const WCHAR*           szFontFamilyName,
        FLOAT                  Size,
        BOOL                   bSetNormalLineSpacing,
        DWRITE_FONT_WEIGHT     weight,
        DWRITE_FONT_STYLE      style,
        DWRITE_FONT_STRETCH    stretch,
        IDWriteFontCollection* fontCollection,
        const WCHAR*           LocaleName
    ) ic_noexc {
        // zh-CN - 中国
        // en-US - 美国
        HRESULT            r;
        IDWriteTextFormat* pTxFm;
        r = pFac->CreateTextFormat(szFontFamilyName, fontCollection,
                weight, style, stretch, Size, LocaleName, ppTxFm);
        ic_if_return(FAILED(r), r);
        ic_if_do_x3(bSetNormalLineSpacing, pTxFm = *ppTxFm,
            r = icppDWriteSetNormalLineSpacing(pTxFm, pFac), ic_if_goto(FAILED(r), pos_Err));
        return r;
    pos_Err:
        ic_do_x2(pTxFm->Release(), *ppTxFm = NULL);
        return r;
    }

    icpp_dwrite_dcl void ic_call icppDWriteGetStringRectF(D2D_RECT_F* pRc, const WCHAR* cs, UINT32 stringLength, 
        IDWriteFactory* pDwFac, IDWriteTextFormat* pTxFm, FLOAT maxWidth, FLOAT maxHeight) ic_noexc {
        IDWriteTextLayout*  pTL = NULL;
        DWRITE_TEXT_METRICS txMet;
        pDwFac->CreateTextLayout(cs, stringLength, pTxFm, maxWidth, maxHeight, &pTL);
        pTL->GetMetrics(&txMet);
        pTL->Release();
        *pRc = {
            txMet.left,
            txMet.top,
            txMet.widthIncludingTrailingWhitespace,
            txMet.height
        };
    }
#endif