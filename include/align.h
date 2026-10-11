#pragma once

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1)/(d))
#define ALIGN_UP(x, a) (DIV_ROUND_UP(x, a) * (a))
#define ALIGN_DOWN(x, a) ((x) / (a) * (a))
#define IS_ALIGNED(x, a) ((x) % (a) == 0)
#define IS_POW2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0))
#define ALIGN_UP_POW2(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
