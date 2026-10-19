#include "memory.h"

void copy(void* dst, const void* src, usize n) {
    if (n == 0) return;
    if (dst == NULL || src == NULL) hpanic(ERR_NULL);
    if ((usize)dst < (usize)src + n && (usize)src < (usize)dst + n) herr(ERR_RANGE);
    u8 *d = (u8*)dst;
    const u8 *s = (const u8*)src;
    for (usize i = 0; i < n; i++) {
        d[i] = s[i];
    }
}

void copyfb(void* dst, const void* src, usize n) {
    if (n == 0) return;
    if (dst == NULL || src == NULL) hpanic(ERR_NULL);
    u8 *d = (u8*)dst;
    const u8 *s = (const u8*)src;
    for (usize i = n; i > 0; i--) {
        d[i-1] = s[i-1];
    }
}

void fill(void* dst, u8 val, usize n) {
    if (n == 0) return;
    if (dst == NULL) hpanic(ERR_NULL);
    u8 *d = (u8*)dst;
    for (usize i = 0; i < n; i++) {
        d[i] = val;
    }
}

bool iseq(const void* a, const void* b, usize n) {
    if (n == 0) return true;
    if (a == NULL || b == NULL) hpanic(ERR_NULL);
    const u8 *first = (const u8*)a;
    const u8 *second = (const u8*)b;
    for (usize i = 0; i < n; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}


// Needed functions for compiler. You can use they, but i recommend use standard functions
void* memcpy(void* dest, const void* src, usize n) {
    copy(dest, src, n);
    return dest;
}

void* memset(void* dest, int val, usize n) {
    fill(dest, val, n);
    return dest;
}
