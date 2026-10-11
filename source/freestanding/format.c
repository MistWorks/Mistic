#include "format.h"

char* format(u64 val, u8 base) {
    static const char digits[] = "0123456789ABCDEF";
    static char buf[65];
    char* p = buf;
    if (base < 2 || base > 16) {
        buf[0] = '\0';
        return buf;
    }
    
    do {
        *p++ = digits[val % base];
    } while (val /= base);
    
    *p = '\0';
    for (char *l = buf, *r = p - 1; l < r; l++, r--) { char t = *l; *l = *r; *r = t; }
    return buf;
}
