#include "herr.h"

const char* lasterr = NULL;

void __attribute__((weak)) herr(errtype s) {
    switch (s) {
        case ERR_NULL:        lasterr = "NULL";     break;
        case ERR_OVERFLOW:    lasterr = "OVERFLOW"; break;
        case ERR_UNREACHABLE: lasterr = "UNREACH";  break;
        case ERR_RANGE:       lasterr = "RANGE";    break;
        case ERR_INVARIANT:   lasterr = "INVARIANT";
        default:              lasterr = " UNKNOWN";
    }
}

void __attribute__((weak, noreturn)) hpanic(errtype s) {
    (void)s;
    __builtin_trap();
}
