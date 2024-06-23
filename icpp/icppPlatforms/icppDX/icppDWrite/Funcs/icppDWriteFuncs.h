
#pragma once

#include"../../../../icpp/Common/icppCommon.h"
#include"../icppDWriteHeaders.h"
#include"../Macros/icppDWriteMacros.h"

ic_info("declarations")
    icpp_dwrite_dcl HRESULT ic_call icppDWriteSetNormalLineSpacing(IDWriteTextFormat* pTextFormat, IDWriteFactory* pFac) ic_noexc;
    icpp_dwrite_dcl HRESULT ic_call icppDWriteCreateTextFormat(
        IDWriteTextFormat**    ppTxFm,
        IDWriteFactory*        pFac, 
        const WCHAR*           szFontFamilyName,
        FLOAT                  Size,
        BOOL                   bSetNormalLineSpacing ic_dfv(TRUE),
        DWRITE_FONT_WEIGHT     weight                ic_dfv(DWRITE_FONT_WEIGHT_NORMAL),
        DWRITE_FONT_STYLE      style                 ic_dfv(DWRITE_FONT_STYLE_NORMAL),
        DWRITE_FONT_STRETCH    stretch               ic_dfv(DWRITE_FONT_STRETCH_NORMAL),
        IDWriteFontCollection* fontCollection        ic_dfv(NULL),
        const WCHAR*           LocaleName            ic_dfv(L"zh_CN")
    ) ic_noexc;
    icpp_dwrite_dcl void ic_call icppDWriteGetStringRectF(D2D_RECT_F* pRc, const WCHAR* cs, UINT32 stringLength,
        IDWriteFactory* pDwFac, IDWriteTextFormat* pTxFm, FLOAT maxWidth ic_dfv(32768.0f), FLOAT maxHeight ic_dfv(32768.0f)) ic_noexc;