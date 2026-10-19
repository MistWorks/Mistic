#pragma once
#include "types.h"
#include "align.h"
#include "herr.h"

usize log2floor(usize x);
usize log2ceil(usize x);
usize pow(usize base, usize exp);
usize abs(ssize x);
usize isqrt(usize x);
usize gcd(usize a, usize b);
usize lcm(usize a, usize b);
usize nextpow2(usize x);
