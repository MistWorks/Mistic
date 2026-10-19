#include "format.h"

char* format(u64 val, u8 base) {
    static const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char buf[65];
    char* p = buf;
    if (base < 2 || base > 36) {
        herr(ERR_RANGE);
        return NULL;
    }

    do {
        *p++ = digits[val % base];
    } while (val /= base);

    *p = '\0';
    for (char *l = buf, *r = p - 1; l < r; l++, r--) { char t = *l; *l = *r; *r = t; }
    return buf;
}
