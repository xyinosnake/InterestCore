
module icd.common.macros.info;

mixin(ic_info("declarations"));
    string ic_info(string info);

mixin(ic_info("definitions"));
    string ic_info(string info) {
        return "";
    }