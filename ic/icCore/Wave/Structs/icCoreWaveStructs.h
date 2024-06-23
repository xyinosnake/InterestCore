
#pragma once

#include"../../Common/Types/icCoreCommonTypes.h"
#include"../Enums/icCoreWaveEnums.h"

ic_info("declarations")
    ic_dcl_struct(IC_WAVE_FORMAT); //IC波形格式结构体

ic_info("definitions")
    struct IC_WAVE_FORMAT {
        uint32_t sampleRate;   //采样率（单位：fps）
        uint16_t sampleSize;   //（单）采样长度（单位：字节）
        uint8_t  channelCount; //声道数
        uint8_t  sampleType;   //采样类型
    };