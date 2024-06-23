#if 0
    #include"./Common/icCoreCommon.h"
    #include"./Memory/icCoreMemory.h"
    #include"./String/icCoreString.h"
    #include"./Math/icCoreMath.h"
    #include"./Geometry/icCoreGeometry.h"
    #include"./Algorithm/icCoreAlgorithm.h"
    #include"./System/icCoreSystem.h"
    #include"./Stream/icCoreStream.h"
    #include"./File/icCoreFile.h"
    #include"./FileMapping/icFileMapping.h"

#ifdef IC_CORE_COMPILE //默认
    #include"./icCore.c"
#endif

#else
    #include"./icCore.h"
#endif

#if 0
    #include<IC-dead/v-0.2/IC/ic/ic.h>
#endif

/*
    UTF-8编码（字符的表示长度取决于它们的代码点）：
        单字节字符（1字节）：0xxxxxxx (x 从 0 到 7)
        双字节字符（2字节）：110xxxxx 10xxxxxx
        三字节字符（3字节）：1110xxxx 10xxxxxx 10xxxxxx
        四字节字符（4字节）：11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    
    UTF-16编码（有双字代理对）
        代码点的数值：codePoint = 0x10000 + ((highSurrogate - 0xD800) << 10) + (lowSurrogate - 0xDC00)
        高位代理项先出现，紧接着是低位代理项。
*/
#define ch_xt        ch8_t
#define vsnprintf_xf vsnprintf

int main() {
    icCoreInit(ic_itf_default_v);
    char buf[256];
    nch_p cs = "请输入密码：" icCmdDisableKeyEcho();
    printf("%s", cs);
    scanf("%s", buf);
    
    printf(icCmdEnableKeyEcho() "您输入的密码是：%s\r\n", buf);
    icCoreUninit();
    system("pause");
}

/*

#define MAX 48
    int32_t buf [] = { 1,2,3,4,5,6,7,8, 1,2,3,4,5,6,7,8, 1,2,3,4,5,6,7,8, 1,2,3,4,5,6,7,8, 1,2,3,4,5,6,7,8, 1,2,3,4,5,6,7,8,  };
    int32_t buf2[] = { 1,2,3,4,5,6,7,8 };
    int32_t val;
    for (cint32_p it = buf, ed = buf + MAX; it != ed; ++it) { printf("%d ", *it); }

ic_def_compare_f(icLessI32, pa, pb) {
    return *(int32_t*)pa < *(int32_t*)pb;
}

ic_def_compare_f(icGreaterI32, pa, pb) {
    return *(int32_t*)pa > *(int32_t*)pb;
}

ic_def_assign_f(icAssignI32, pa, pb) {
    *(int32_t*)pa = *(int32_t*)pb;
}

*/