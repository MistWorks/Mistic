# Format module
Short functions list:


| Name                       | Returns | Panic/Error when                      |
| -------------------------- | ------- | ------------------------------------- |
| `format(u64 val, u8 base)` | char*   | `herr` when `2 > base` or `base > 36` |

## Details about each
### format(u64 val, u8 base)
#### What is it
Converter number with selected counter system to string

#### How does it work
Remainders got by `val % base` is the `digit[]` massive index, so function do cycle of same calculation and slightly moves `val` down by `val /= base`

The result of calculation is the reversed answer, so by another cycle it reversing it and returns `char*` for a `static char buf[]`

**Important**: the function always returns pointer to only one `static char buf[]`, so its *not* thread-safe and multi-usable

#### Errors
When `base < 2` or `base > 36` result will be broken, Mistic calls to `herr` with `ERR_RANGE` error code, because `format()` supports only counter system between 2 and 36