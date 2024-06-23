
module icd.common.macros;

mixin(ic_info("import"));
           import icd.common.macros.topmost;
    public import icd.common.macros.info;
    public import icd.common.macros.cmd_color;

mixin(ic_info("declarations"));
    string ic_alias(string name, string target);
    string icd_dcl_f(string name, string rtnType, string args, string sEx);

mixin(ic_info("definitions"));
    string ic_alias(string name, string target) {
        return "alias " ~ name ~ " = " ~ target ~ ";";
    }

    string icd_dcl_f(string name, string rtnType, string args, string sEx) {
        return "alias " ~ name ~ " = " ~ rtnType ~ " function" ~ args ~ " " ~ sEx ~ ";";
    }