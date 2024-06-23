
module icd.common.types.ic_def_t;

mixin(ic_info("import"));
    import icd.common.macros;

mixin(ic_info("declarations"));
    string ic_def_t(string tName, string ctName, string pName, string cpName, string target);

mixin(ic_info("definitions"));
    string ic_def_t(string tName, string ctName, string pName, string cpName, string target) {
        return "alias " ~ tName  ~ " = "       ~ target ~ ";\r\n" ~
               "alias " ~ ctName ~ " = const " ~ target ~ ";\r\n" ~
               "alias " ~ pName  ~ " = "       ~ tName ~ "*;\r\n" ~
               "alias " ~ cpName ~ " = const(" ~ tName ~ ")*;";
    }