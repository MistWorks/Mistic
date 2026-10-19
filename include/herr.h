#pragma once
#include "types.h"

typedef enum {
    ERR_NONE = 0,
    ERR_NULL,
    ERR_OVERFLOW,
    ERR_UNREACHABLE,
    ERR_RANGE, 
    ERR_INVARIANT, 
} errtype;

extern const char* lasterr;

void herr(errtype s);
void __attribute__((noreturn)) hpanic(errtype s);
