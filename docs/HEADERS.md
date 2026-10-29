## Special headers

### types.h
Fixed-width type aliases used throughout the project

| Type    | Size             | Signed | Notes                                                                  |
| ------- | ---------------- | ------ | ---------------------------------------------------------------------- |
| `u8`    | 1 byte           | no     |                                                                        |
| `u16`   | 2 bytes          | no     |                                                                        |
| `u32`   | 4 bytes          | no     |                                                                        |
| `u64`   | 8 bytes          | no     | `unsigned long long`, **not** `unsigned long` (which is 32-bit on x86) |
| `usize` | 8 bytes          | no     | Pointer-sized, because the target is x86_**64**                        |
| `ssize` | 8 bytes          | yes    | Signed counterpart of `usize`                                          |
| `s8`    | 1 byte           | yes    |                                                                        |
| `s16`   | 2 bytes          | yes    |                                                                        |
| `s32`   | 4 bytes          | yes    |                                                                        |
| `s64`   | 8 bytes          | yes    |                                                                        |
| `bool`  | 1 byte (`_Bool`) | —      | Contains only `0` or `1`                                               |
| `true`  | 1                | —      | There is no built-in `true` in C                                       |
| `false` | 0                | —      | Same reason as `true`                                                  |
| `NULL`  | `((void*)0)`     | —      |                                                                        |

Rules:

- It's recommended to use the fixed-width aliases instead of `int`, `char`, `short`, etc. 
- Every unsigned type has a signed analog (`u8`/`s8`, `usize`/`ssize`, …)

Also there is couple of **macros** for the size types:
- `USIZE_MAX`
- `SSIZE_MAX`
- `SSIZE_MIN`

### align.h
Alignment and power-of-two helpers, implemented as macros.

| Macro               | Formula                                          | Purpose |
| ------------------- | ------------------------------------------------ | ------- |
| `DIV_ROUND_UP(x,a)` | `(((x) + (a) - 1) / (a))`                        | Divide `x` by `a`, rounding up |
| `ALIGN_UP(x,a)`     | `(DIV_ROUND_UP(x, a) * (a))`                     | Round `x` up to a multiple of `a` |
| `ALIGN_DOWN(x,a)`   | `((x) / (a) * (a))`                              | Round `x` down to a multiple of `a` |
| `IS_ALIGNED(x,a)`   | `((x) % (a) == 0)`                               | True if `x` is a multiple of `a` |
| `IS_POW2(x)`        | `((x) != 0 && (((x) & ((x) - 1)) == 0))`         | True if `x` is a power of two |
| `ALIGN_UP_POW2(x,a)`| `(((x) + ((a) - 1)) & ~((a) - 1))`               | Round `x` up to a multiple of `a`, where `a` is a power of two |

Notes and constraints:

- `ALIGN_UP`, `ALIGN_DOWN`, `DIV_ROUND_UP` accept **any** non-zero `a`
- `ALIGN_UP_POW2` requires `a` to be a **power of two**. If `a` is not
  a power of two, the result is undefined
- `DIV_ROUND_UP` can overflow when `x + a - 1` exceeds `USIZE_MAX`.
- Macros are not hygienic: do not pass expressions with side effects
  (`x++`, function calls) as arguments
- `IS_ALIGNED(x, 1)` is always true; `a` must not be zero

Examples:

```c
ALIGN_UP(13, 8)       // 16
ALIGN_DOWN(13, 8)     // 8
IS_ALIGNED(16, 8)     // true
IS_POW2(64)           // true
IS_POW2(0)            // false
ALIGN_UP_POW2(13, 8)  // 16
```

## Modules headers
This headers mostly declares their modules functions. For details see:
- [Math module](API/Freestanding/MATH.md)
- [Memory module](API/Freestanding/MEMORY.md)
- [String module](API/Freestanding/STRING.md)
- [Formatting module](API/Freestanding/FORMAT.md)
- [Error handling](API/System/HERR.md)