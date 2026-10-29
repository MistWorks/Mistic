# Memory module
Short functions list:

| Name                                          | Returns | Panic/Error when                                                                             |
| --------------------------------------------- | ------- | -------------------------------------------------------------------------------------------- |
| `copy(void* dst, const void* src, usize n)`   | void    | `hpanic` when `dst == NULL` or `src == NULL` and `herr` when `dst` and `src` are overlapping |
| `copyfb(void* dst, const void* src, usize n)` | void    | `hpanic` when `dst == NULL` or `src == NULL`                                                 |
| `fill(void* dst, u8 val, usize n)`            | void    | `hpanic` when `dst == NULL`                                                                  |
| `iseq(const void* a, const void* b, usize n)` | bool    | `hpanic` when `a == NULL` or `b == NULL`                                                     |

## Details about each
### copy(void* dst, const void* src, usize n)
#### What is it
Copying `n` byte from `src` to `dst` through cycle

#### How does it work
Per-byte copying. Cycle starts on 0 byte and grows to `n`. If `n == 0`, it returns instantly

#### Errors
When `src == NULL` or `dst == NULL`, Mistic calls to `hpanic` with `ERR_NULL` error code
If `dst` and `src` are overlapping, Mistic calls to `herr` with `ERR_RANGE` error code

### copyfb(void* dst, const void* src, usize n)
#### What is it
Copying `n` byte from `src` to `dst` through reversed cycle. It's needed when buffers are overlapping

#### How does it work
Per-byte copying. Cycle starts on `n` byte and falls to 0. If `n == 0`, it returns instantly

#### Errors
When `src == NULL` or `dst == NULL`, Mistic calls to `hpanic` with `ERR_NULL` error code

### fill(void* dst, u8 val, usize n)
#### What is it
Fill `n` bytes from `dst` with `val`

#### How does it work
Per-byte cycle, returns nothing

#### Errors
If `dst == NULL` Mistic calls to `hpanic` with `ERR_NULL` error code

### iseq(const void* a, const void* b, usize n)
#### What is it
Comparing `n` bytes from `a` and `b`

#### How does it work
Per-byte cycle, returns bool. `true` = they are equal, `false` = they are different

If `n == 0`, always `iseq(a, b, 0) == true`. Even if `a == NULL` and/or `b == NULL`

#### Errors
If `a == NULL` or `b == NULL` Mistic calls to `hpanic` with `ERR_NULL` error code