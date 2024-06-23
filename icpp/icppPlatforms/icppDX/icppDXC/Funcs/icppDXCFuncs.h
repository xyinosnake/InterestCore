
#pragma once

#include"../Macros/icppDXCMacros.h"
#include"../icppDXCHeaders.h"

ic_info("declarations")
    icpp_dxc_dcl const WICPixelFormatGUID* ic_call icppDXCConvertDXGIPixelFormatToWICPixelFormat(DXGI_FORMAT fm) ic_noexc;