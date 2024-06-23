#ifndef IC_WIN32_WAVE_FUNCS
#define IC_WIN32_WAVE_FUNCS

#include"./icWin32WaveFuncs.h"

ic_info("definitions")
    ic_win32_dcl void ic_call icWin32Decompose_WAVEFORMATEX(
        const WAVEFORMATEX* pWAVEFORMATEX,
        int*                pSampleRate,
        int*                pChannelsCount,
        int*                pBytesPerSample,
        int*                pFormat
    ) ic_noexc {
        *pFormat         = pWAVEFORMATEX->wFormatTag;         //格式标签
        *pChannelsCount  = pWAVEFORMATEX->nChannels;          //声道数
        *pSampleRate     = pWAVEFORMATEX->nSamplesPerSec;     //采样率
        *pBytesPerSample = pWAVEFORMATEX->wBitsPerSample / 8; //比特率 -> 同声道数无关（独立）（sizeof(type)） * 8 -> 固定值
    }
    
    ic_win32_dcl void ic_call icWin32Gen_WAVEFORMATEX(
        WAVEFORMATEX* pWAVEFORMATEX,
        int           sampleRate,
        int           channelsCount,
        int           bytesPerSample,
        int           format
    ) ic_noexc {
        WORD  nBlockAlign     = bytesPerSample * channelsCount; //内存块对齐尺寸 = 比特率 / 8 * 声道数 （单位：字节）
        DWORD nAvgBytesPerSec = nBlockAlign * sampleRate;       //比特率（所有声道，每秒） 块大小 * 采样率
        pWAVEFORMATEX->wFormatTag      = format;                //格式标签
        pWAVEFORMATEX->nChannels       = channelsCount;         //声道数
        pWAVEFORMATEX->nSamplesPerSec  = sampleRate;            //采样率
        pWAVEFORMATEX->nAvgBytesPerSec = nAvgBytesPerSec;
        pWAVEFORMATEX->nBlockAlign     = nBlockAlign;
        pWAVEFORMATEX->wBitsPerSample  = (WORD)(bytesPerSample * 8); //比特率 -> 同声道数无关（独立）（sizeof(type)） * 8 -> 固定值
        pWAVEFORMATEX->cbSize          = 0;
        //欲播放浮点格式音频，应手动设置 format 为 WAVE_FORMAT_IEEE_FLOAT。
        /*
        内嵌说明：
            wFormatTag      格式标签 - 默认为 WAVE_FORMAT_PCM（整数型），常用 WAVE_FORMAT_IEEE_FLOAT（浮点型）
            nChannels       声道数 - 完全独立的参数，与其他任何参数均无关。1为单声道，2为立体声。其他数目（比如像5.0）从未测试。
            nSamplesPerSec  采样率 - 完全独立的参数，与其他任何参数均无关。常用44100，96000等。凡是声卡驱动能够识别的数值均可设入。
            wBitsPerSample  比特率 - 完全独立的参数，同声道数无关。与其他任何参数同样无关。注意单位是bit不是byte。sizeof的结果值需要 * 8。
            nBlockAlign     对齐数 = 比特率 / 8 * 声道数; 单位是字节。<!>我尚未测试24位wav是否有特殊要求。
            nAvgBytesPerSec 平均数据传输速率 = nSamplesPerSec * nBlockAlign; （单位是 字节/秒）官方文档要求是必须这样设置。且存在其他设置方式。唯一一个难以规范的成员。
            cbSize          附加额外数据大小。PCM状态下，应设置为0。极少使用的成员。
        */
    }

    ic_win32_dcl void ic_call icWin32ConvertWaveFormatExToICWaveFormat(
	    IC_WAVE_FORMAT*     pWaveFormat, 
	    const WAVEFORMATEX* pWAVEFORMATEX
    ) ic_noexc{
        ic_stv_x4(int, sampleRate, channelsCount, bytesPerSample, format);
        icWin32Decompose_WAVEFORMATEX(pWAVEFORMATEX,
            &sampleRate, &channelsCount, &bytesPerSample, &format);
        ic_wave_sample_type_e sampleType;
        ic_if_do(format == 0x0003, sampleType = ic_wave_sample_type_float_v) //WAVE_FORMAT_IEEE_FLOAT
        else {
            switch (bytesPerSample) {
            case 1:	 sampleType = ic_wave_sample_type_unsigned_integer_v; break;
            default: sampleType = ic_wave_sample_type_signed_integer_v;   break;
            }
        }
        icWin32Gen_WAVEFORMATEX(pWaveFormat, sampleRate, bytesPerSample, channelsCount, sampleType);
    }

    ic_win32_dcl void ic_call icWin32ConvertICWaveFormatToWaveFormatEx(
        WAVEFORMATEX*         pWAVEFORMATEX,
        const IC_WAVE_FORMAT* pWaveFormat
    ) ic_noexc {
        icWin32Gen_WAVEFORMATEX(
            pWAVEFORMATEX,
            pWaveFormat->sampleRate,
            pWaveFormat->channelCount,
            pWaveFormat->sampleSize,
            pWaveFormat->sampleType == ic_wave_sample_type_float_v ?
            0x0003 /* WAVE_FORMAT_IEEE_FLOAT */ : WAVE_FORMAT_PCM);
    }
#endif