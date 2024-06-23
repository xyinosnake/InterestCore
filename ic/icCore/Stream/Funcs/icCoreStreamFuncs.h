
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Common/Types/icCoreCommonTypes.h"
#include"../Macros/icCoreStreamMacros.h"
#include"../Enums/icCoreStreamEnmus.h"

ic_info("decs")
    #define                         icCreateStream icCreateStreamN
    ic_core_dcl ic_stream_h ic_call icCreateStreamN(cnch_p fName, ic_file_e e) ic_noexc;
    ic_core_dcl ic_stream_h ic_call icCreateStreamW(cwch_p fName, ic_file_e e) ic_noexc;
    ic_core_dcl bool        ic_call icDestroyStream(ic_stream_h hStream) ic_noexc;
    ic_core_dcl bool        ic_call icWriteStream(ic_stream_h hStream, cvoid_p pData, size_t btSz) ic_noexc;
    ic_core_dcl bool        ic_call icReadStream(ic_stream_h hStream, void_p pData, size_t btSz) ic_noexc;
    ic_core_dcl uint64_t    ic_call icSizeOfStream(ic_stream_h hStream) ic_noexc;
    ic_core_dcl uint64_t    ic_call icGetStreamPos(ic_stream_h hStream) ic_noexc;
    ic_core_dcl bool        ic_call icSetStreamPos(ic_stream_h hStream, uint64_t uBtPos) ic_noexc;
    ic_core_dcl bool        ic_call icSetStreamBuf(ic_stream_h hStream, size_t len, int mode ic_dfv(_IOFBF)) ic_noexc;
    ic_core_dcl bool        ic_call icFlushStream(ic_stream_h hStream) ic_noexc;