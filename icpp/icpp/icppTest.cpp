
#if 0
    #define IC_CORE_IMPORT
    #define IC_IMPORT
    #define IC_WIN32_IMPORT
    #define ICPP_IMPORT
    #pragma comment(lib, "C:/InterestCore/lib/ic.lib")
    #pragma comment(lib, "C:/InterestCore/lib/icCore.lib")
    #pragma comment(lib, "C:/InterestCore/lib/icWin32.lib")
    #pragma comment(lib, "C:/InterestCore/lib/icpp.lib")
#endif

#include"./icpp.h"

// #include<cstdint>
using namespace std;
using namespace icpp;

int main() {
    icInit();
        // icCoreHello(ic_hf_all_v);
        // icWin32Hello(ic_hf_all_v);
        // icHello(ic_hf_all_v);
        // icppHello(ic_hf_all_v);
        cout << (SSeg8("Xyino ") + "Snake").c_str() << endl;
        cout << (size_t)icAlloc(1);
    icUninit();
    //system("pause");
}