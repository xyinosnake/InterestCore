
#include"./icCore.h"


int main() {
    icCoreInit(ic_itf_default_v);
    icWriteConsoleCS8 ("wc\r\n");
    icWriteConsoleCS16(L"wc\r\n");
    //ch32_t buf32[] = { (ch32_t)'w', (ch32_t)'c', (ch32_t)'\0' };
    icWriteConsoleCS32(U"wcwc");
    icCoreUninit();
    system("pause");
}