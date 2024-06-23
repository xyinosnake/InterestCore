
#ifndef IC_CORE_STREAM_FUNCS
#define IC_CORE_STREAM_FUNCS

#include"./icCoreStreamFuncs.h"

ic_info("defs")
    ic_core_dcl ic_stream_h ic_call icCreateStreamN(cnch_p fName, ic_file_e e) ic_noexc {
        static cnch_p sMode[] = { "rb", "wb", "rb+", "ab" };
               cnch_p mode    = sMode[e];
        ic_stream_h fh = (ic_stream_h)fopen(fName, mode);
        ic_if_do(e == ic_fm_read_write_v, ic_fseek64((FILE*)fh, 0, SEEK_SET));
        return (ic_stream_h)fh;
    }

    ic_core_dcl ic_stream_h ic_call icCreateStreamW(cwch_p fName, ic_file_e e) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        static cwch_p sMode[] = { L"rb", L"wb", L"rb+", L"ab" };
               cwch_p mode    = sMode[e];
        ic_stream_h fh = (ic_stream_h)_wfopen(fName, mode);
        ic_if_do(e == ic_fm_read_write_v, ic_fseek64((FILE*)fh, 0, SEEK_SET));
        return (ic_stream_h)fh;
    #else
        return NULL;
    #endif
    }

    ic_core_dcl bool ic_call icDestroyStream(ic_stream_h hStream) ic_noexc {
        return fclose((FILE*)hStream) == 0;
    }

    ic_core_dcl bool ic_call icWriteStream(ic_stream_h hStream, cvoid_p pData, size_t btSz) ic_noexc {
        return fwrite(pData, 1, btSz, (FILE*)hStream) == btSz;
    }

    ic_core_dcl bool ic_call icReadStream(ic_stream_h hStream, void_p pData, size_t btSz) ic_noexc {
        return fread(pData, 1, btSz, (FILE*)hStream) == btSz;
    }

    ic_core_dcl uint64_t ic_call icSizeOfStream(ic_stream_h hStream) ic_noexc {
        long long llOldPos  = ic_ftell64((FILE*)hStream);
        ic_fseek64((FILE*)hStream, 0, SEEK_CUR);
        uint64_t btSzOfFile = (uint64_t)ic_ftell64((FILE*)hStream);
        ic_fseek64((FILE*)hStream, llOldPos, SEEK_SET);
        return btSzOfFile;
    }

    ic_core_dcl uint64_t ic_call icGetStreamPos(ic_stream_h hStream) ic_noexc {
        return (uint64_t)ic_ftell64((FILE*)hStream);
    }

    ic_core_dcl bool ic_call icSetStreamPos(ic_stream_h hStream, uint64_t uBtPos) ic_noexc {
        return ic_fseek64((FILE*)hStream, (long long)uBtPos, SEEK_SET) == 0;
    }

    ic_core_dcl bool ic_call icSetStreamBuf(ic_stream_h hStream, size_t len, int mode) ic_noexc {
        return 0 == setvbuf((FILE*)hStream, NULL, mode, len);
    }

    ic_core_dcl bool ic_call icFlushStream(ic_stream_h hStream) ic_noexc {
        return fflush((FILE*)hStream) == 0;
    }
#endif
