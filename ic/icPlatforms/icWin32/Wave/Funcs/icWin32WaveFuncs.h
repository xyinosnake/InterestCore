
#pragma once

#include"../../Common/icWin32Common.h"
#include"../../../../icCore/Wave/icCoreWave.h"


ic_info("declarations")
    ic_win32_dcl void ic_call icWin32Decompose_WAVEFORMATEX(
        const WAVEFORMATEX* pWAVEFORMATEX,
        int*                sampleRate,
        int*                numberOfChannels,
        int*                pBytesPerSample,
        int*                pFormat
    ) ic_noexc;
    ic_win32_dcl void ic_call icWin32Gen_WAVEFORMATEX(
        WAVEFORMATEX* pWAVEFORMATEX,
        int           sampleRate,
        int           channelsCount,
        int           bytesPerSample,
        int           format
    ) ic_noexc;
    ic_inl HMMIO ic_call icWin32OpenWavFileW(const WCHAR* pszWavFileName) ic_noexc;
    ic_inl HMMIO ic_call icWin32OpenWavFileA(const CHAR* pszWavFileName) ic_noexc;

ic_info("inl definitions")
    ic_inl HMMIO ic_call icWin32OpenWavFileW(const WCHAR* pszWavFileName) ic_noexc {
        return mmioOpenW((WCHAR*)pszWavFileName, NULL, MMIO_ALLOCBUF | MMIO_READ);
    }

    ic_inl HMMIO ic_call icWin32OpenWavFileA(const CHAR* pszWavFileName) ic_noexc {
        return mmioOpenA((CHAR*)pszWavFileName, NULL, MMIO_ALLOCBUF | MMIO_READ);
    }