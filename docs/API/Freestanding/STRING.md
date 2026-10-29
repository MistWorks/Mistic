# String module
Short functions list:

| Name                                    | Returns | Panic/Error when                                                                         |
| --------------------------------------- | ------- | ---------------------------------------------------------------------------------------- |
| `strlen(const char* str)`               | usize   | `hpanic()` when `str == NULL                                                             |
| `striseq(const char* a, const char* b)` | bool    | `hpanic()` when `a == NULL or b == NULL`                                                 |
| `strcopy(char* dst, const char* src)`   | void    | `hpanic()` when `dst == NULL or src == NULL` and `herr` when `strlen(dst) < strlen(src)` |

## Details about each
### strlen(const char* src)
#### What is it
String length counter

#### How does work
Count every byte and stop when byte` == '\0'`. For example:
1. `const char* str = "Hello!";`
2. `usize size = strlen(str);`
3. str == "Hello!\0"
4. 'H' == str\[0], 'e' == str\[1], 'l' == str\[2], 'l' == str\[3], 'o' == str\[4], '!' == str\[5]
5. `size == 6`

#### Errors
Of course, if `str == NULL`, function processing is undefined, so Mistic calls to `hpanic` with `ERR_NULL` error code

### striseq(const char* a, const char* b)
#### What is it
String length comparator

#### How does work
Returns `true` (1) if strings are same, and `false` (0) if they are don't
To calculate this, function just compare every single byte and verify that `'\0'` bytes are in the same position

#### Errors
Of course, if `a == NULL or b == NULL`, function processing is undefined, so Mistic calls to `hpanic` with `ERR_NULL` error code

### strcopy(char* dst, const char* src)
#### What is it
Copying `src` string to `dst` string

#### How does it work
Per-byte copying through cycle that returns nothing

#### Errors
`hpanic` with `ERR_NULL` error code when `dst == NULL` or `src == NULL`
`hpanic` with `ERR_RANGE` error code when `strlen(dst) < strlen(src)`. But when `strlen(dst) > strlen(src)`, `dst` just cutted