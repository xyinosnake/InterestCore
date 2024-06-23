
#pragma once

#include"../../Common/icCoreCommon.h"
#include"../Enums/icCoreStringEnums.h"

ic_info("declarations")
    ic_dcl_union(IC_TRANSLATED_CHAR_BUF);
    ic_dcl_struct(IC_TRANSLATED_CHAR_INFO);
    ic_dcl_struct(IC_TRANSLATED_STRING_INFO);

ic_info("defines")
    union IC_TRANSLATED_CHAR_BUF {
        ch8_p  buf8;
        ch16_p buf16;
        ch32_p buf32;
    };

    struct IC_TRANSLATED_CHAR_INFO {
        uint8_t result;              //ic_translated_char_result_e
        uint8_t srcLenOrResidualLen; //被转换的字符数，或发生字符数不足错误时剩余的字符数。若发生非法的起始字符错误，该值为0。
        uint8_t srcNecessaryLen;     //转换所需要的必要字符数，若转换成功，则等同于srcLenOrResidualLen。
        uint8_t srcErrPos;           //错误位置。若没有错误，该值为0。应依据result判断srcErrPos的有效性。
    };

    struct IC_TRANSLATED_STRING_INFO {
        int16_t result;              //ic_translated_char_result_e
        int16_t srcResidualLen;      //发生错误时剩余的字符数，若转换成功，该值为0。需配合srcErrPosIfErr使用。
        int16_t srcCharNecessaryLen; //发生错误时，转换所需要的必要字符数。
        int16_t srcErrStartPosShift; //发生错误时，起始字符相对于错误位置的向右偏移量（Utf8-> 0 1 2 3 Utf16-> 0 1 Utf32-> 0）
        size_t  srcErrStartPos;      //错误的起始字符位置。若没有错误，该值为0。应依据result判断srcErrPos的有效性。
    };