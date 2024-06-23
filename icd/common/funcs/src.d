
//module:
    module icd.common.funcs.src;

//import:
    import icd.common.funcs;
    import std.stdio;

mixin(ic_info("definitions"));
    __gshared string g_icdDep = "icd(icCore, icUnix | icWin32, ic)";
    extern(C) export cch8_p icdDep() nothrow @nogc {
        return cast(cch8_p)g_icdDep;
    }

    extern(C) export void icdHello() nothrow {
        try {
            writeln(
                "[icd]Hello, I'm icd!\r\n" ~
                "Dependences->" ~ g_icdDep
            );
        } catch (Exception e) {}
    }