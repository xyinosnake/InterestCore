
#pragma once

#define ic_def_t(tName, ctName, pName, cpName, target) \
    typedef       target  tName;\
    typedef const target ctName;\
    typedef       tName*  pName;\
    typedef const tName* cpName

#define ic_expand_t(tName, ctName, pName, cpName) \
    typedef const tName  ctName;\
    typedef       tName*  pName;\
    typedef const tName* cpName
