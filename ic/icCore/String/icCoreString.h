
#pragma once

#include"./Enums/icCoreStringEnums.h"
#include"./Structs/icCoreStringStructs.h"
#include"./Funcs/icCoreStringFuncs.h"

/*
    UTF-8编码（字符的表示长度取决于它们的代码点）：
        单字节字符（1字节）：0xxxxxxx (x 从 0 到 7)
        双字节字符（2字节）：110xxxxx 10xxxxxx
        三字节字符（3字节）：1110xxxx 10xxxxxx 10xxxxxx
        四字节字符（4字节）：11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

    UTF-16编码（有双字代理对）
        代码点的数值：codePoint = 0x10000 + ((highSurrogate - 0xD800) << 10) + (lowSurrogate - 0xDC00)
        高位代理项先出现，紧接着是低位代理项。
        char16_t buf[2];
        buf[0]为highSurrogate，buf[1]为lowSurrogate。

    UTF-32编码：
        平面代码，不存在代理情形。


    重要：
        不存在utf32能表示而utf8、utf16不能表示的unicode字符。

    大端小端：
        转换函数的大小端依赖于机器。如果需要逆机器序的转换，必须进行附加的前或后处理。
*/