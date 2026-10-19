#include "types.h"
#include "string.h"

usize strlen(const char* str) {
    if (str == NULL) hpanic(ERR_NULL);
    usize i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

bool striseq(const char* a, const char* b) {
    if (a == NULL || b == NULL) hpanic(ERR_NULL);
    usize i = 0; 
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

void strcopy(char* dst,  const char* src) {
    if (src == NULL || dst == NULL) hpanic(ERR_NULL);
    usize i = 0;
    while (dst[i] != '\0' && src[i] != '\0') {
    dst[i] = src[i];
    i++;
    }
    if (dst[i] == '\0' && src[i] != '\0') herr(ERR_RANGE);
    dst[i] = '\0';
}
