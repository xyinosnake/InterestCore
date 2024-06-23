
module icd.common.funcs;

mixin(ic_info("import"));
    public import icd.common.macros;
    public import icd.common.types;
    public import icd.common.enums;

mixin(ic_info("declarations"));
    mixin(ic_info("template declarations")); static if (false) {
        bool icValInItv(value_xt)(value_xt value, value_xt left, value_xt right) nothrow @nogc pure;
        bool icValInClosedItv(value_xt)(value_xt value, value_xt left, value_xt right) nothrow @nogc pure;
        ref value_xt icSetBits(value_xt)(ref value_xt v, value_xt mask) nothrow @nogc pure;
        ref value_xt icClearBits(value_xt)(ref value_xt v, value_xt mask) nothrow @nogc pure;
        ref value_xt icSetOrClearBits(value_xt)(bool b, value_xt v, value_xt mask) nothrow @nogc pure;
        value_xt icGetBit(value_xt)(value_xt v, value_xt mask) nothrow @nogc pure;
    }
    extern(C) void   icdHello() nothrow;
    extern(C) cch8_p icdDep() nothrow @nogc;

mixin(ic_info("definitions"));
    mixin(ic_info("template definitions")); static if (true) {
        bool icValInItv(value_xt)(value_xt value, value_xt left, value_xt right) nothrow @nogc pure {
            return value >= left && value < right;
        }

        bool icValInClosedItv(value_xt)(value_xt value, value_xt left, value_xt right) nothrow @nogc pure {
            return value >= left && value <= right;
        }

        ref value_xt icSetBits(value_xt)(ref value_xt v, value_xt mask) nothrow @nogc pure {
            return v |= mask;
        }

        ref value_xt icClearBits(value_xt)(ref value_xt v, value_xt mask) nothrow @nogc pure {
            return v &= ~mask;
        }

        ref value_xt icSetOrClearBits(value_xt)(bool b, value_xt v, value_xt mask) nothrow @nogc pure {
            return v = b ? (v | mask) : (v & ~mask);
        }

        value_xt icGetBit(value_xt)(value_xt v, value_xt mask) nothrow @nogc pure {
            return v & mask;
        }
    }