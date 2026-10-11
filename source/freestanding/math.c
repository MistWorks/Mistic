#include "types.h"
#include "align.h"
#include "math.h"

usize log2floor(usize x) {
    if (x == 0) return -1;

    usize k = 0;
    while (x > 1) {
        x >>= 1;
        k++;
    }
    return k;
}

usize log2ceil(usize x) {
    if (x == 0) return -1;

    usize k = log2floor(x);
    if (IS_POW2(x)) {
        return k;
    } else {
        return ++k;
    }
}

usize pow(usize base, usize exp) {
    if (exp == 0) return 1;

    usize newbase = base;
    while (exp > 1) {
        newbase *= base;
        exp--;
    }
    return newbase;
}

usize abs(ssize x) {
    if (x >= 0) {
        return (usize)x;
    } else {
        return 0 - (usize)x;
    }
}

usize isqrt(usize x) {
    usize res = 0;
    usize bit = 1ULL << 62; 

    while (bit > x) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (x >= res + bit) {
            x -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

usize gcd(usize a, usize b) {
    while (b != 0) {
        usize t = b;
        b = a % b;
        a = t;
    }
    return a;
}

usize lcm(usize a, usize b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

usize nextpow2(usize x) {
    if (x == 0) return 1;
    if (x > (1ULL << 63)) return -1;

    usize k = log2ceil(x);
    return 1ULL << k;
}
