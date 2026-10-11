#include "types.h"
#include "string.h"

usize strlen(const char* str) {
    if (str == NULL) {
        return 0;
    }
    usize i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

bool striseq(const char* a, const char* b) {
    if (a == NULL || b == NULL) {
        return false;
    }
    usize i = 0; 
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] > b[i]) {
            return false;
        } else if (a[i] < b[i]) {
            return false;
        }
        i++;
    }

    if (a[i] == '\0' && b[i] != '\0') {
        return false;
    }
    if (a[i] != '\0' && b[i] == '\0') {
        return false;
    }

    return true;
}

void strcopy(const char* a, char* b) {
    if (a == NULL || b == NULL) {
        return;
    }
    usize len = 0;
    usize i = 0;
    while (b[i] != '\0' && a[i] != '\0') {
        len++;
        i++;
    }

    for (usize n = 0; n < len; n++) {
        b[n] = a[n];
    }
    b[len] = '\0';
}
