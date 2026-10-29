# Math module
Short functions list:

| Name                         | Returns | Panic/Error when                 |
| ---------------------------- | ------- | -------------------------------- |
| `log2floor(usize x)`         | usize   | `hpanic()` when `x == 0`         |
| `log2ceil(usize x)`          | usize   | `hpanic()` when `x == 0`         |
| `pow(usize base, usize exp)` | usize   | `hpanic()` when overflow         |
| `abs(ssize x)`               | usize   | `hpanic()` when `x == SSIZE_MIN` |
| `isqrt(usize x)`             | usize   | —                                |
| `gcd(usize a, usize b)`      | usize   | —                                |
| `lcm(usize a, usize b)`      | usize   | `hpanic()` when `x > USIZE_MAX`  |
| `nextpow2(usize x)`          | usize   | `hpanic` when `x > 2^63`         |

## Details about each
### log2floor(usize x)
#### What is it
Logarithm that returns highest integer number below $log_2x$. For example:
- `log2floor(9) == 3`
- `log2floor(70) == 6`
- etc. 

#### How does it work
The answer is always the `usize` integer number
It gets by adding `>> 1` mask to the `x` and counting it while `x > 1`. For example:
1. $log2floor(17)$
2. `17 = 0b10001`
3. `10001 >> 1 == 1000; k = 1`
4. `1000 >> 1 == 100; k = 2`
5. `100 >> 1 == 10; k = 3`
6. `10 >> 1 == 1; k = 4`
7. $log2floor(17) == 4$

#### Errors
So, `x >= 1` is the requirement. If `x == 1; k = 0` and $log2floor(1) == 0$

**But** if `x == 0`, the answer is undefined and program can't continue working. In this case, Mistic calls to `hpanic` with `ERR_INVARIANT` error code. It's mean that you have to check `x != 0` elsewhere program will be stopped by force (if you don't [override hpanic](../CONVENTION.md))

---
### log2ceil(usize x)
#### What is it
Logarithm that returns least integer number upper than $log_2x$. For example:
- `log2ceil(9) == 4`
- `log2ceil(70) == 7`
- etc. 

#### How does it work
It works pretty simple:
1. Get `log2floor(x)`
2. Check if `x` is a power of 2 by `IS_POW2` macros
3. If it so, `log2floor(x) == log2ceil(x) == log2(x)`
4. If it don't, `log2ceil(x) == log2floor(x) + 1`

For example:
1. $log2ceil(17)$
2. `IS_POW2(17) == false`
3. `log2floor(17) == 4`
4. `log2ceil(17) == log2floor(17) + 1`
5. $log2ceil(17) == 5$

Or:
1. $log2ceil(32)$
2. `IS_POW2(32) == true`
3. `log2floor(32) == 5`
4. `log2ceil(32) == log2floor(32)`
5. $log2ceil(32) == 5$

#### Errors
Because `log2ceil` is just wrapper of `log2floor`, it has same limit: `x >= 1`. Else (`x == 0`) — `hpanic(ERR_INVARIANT)`

---
### pow(usize base, usize exp)
#### What is it
`base` number powered with `exp`

#### How does it work
Answer is the integer number that gets with the cycle by {умножение} `base` on itself `exp` times through `newbase`. For example:
1. $pow(3, 3)$
2. `newbase == 1; cycles count == 3`
3. `newbase == 3; cycles count == 2`
4. `newbase == 9; cycles count == 1`
5. `newbase == 27; cycles count == 0`
6. $pow(3, 3) == 27$

**Important** $pow(base, 0) == 1$ is always true, even if `base == 0`

#### Errors
Because `pow()` can get into large numbers, it not excluded that it maybe bigger than `USIZE_MAX`. If it so, i.e. if `newbase > USIZE_MAX / bade` (do don't get into overflow), Mistic calls to `hpanic` with `ERR_OVERFLOW` error code

---
### abs(ssize x)
#### What is it
Returns the absolute value of a signed integer as an unsigned integer

#### How does it work
If `x >= 0`, it simply casts x to usize. If `x < 0`, it negates `x` and casts it to usize

#### Errors
`hpanic` if `x == SSIZE_MIN`, because the positive counterpart of SSIZE_MIN cannot be represented in ssize (it exceeds SSIZE_MAX)

---
### isqrt(usize x)
#### What is it
Integer square root. Returns the floor of the square root of `x` (the largest integer `k` such that `k * k <= x`).

#### How does it work
Uses the binary algorithm. It processes the number in blocks of two bits, building the result bit by bit

#### Errors
—

---
### gcd(usize a, usize b)
#### What is it
Greatest Common Divisor. Finds the largest integer that divides both a and b without a remainder

#### How does it work
Uses the [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

#### Errors
—

---
### lcm(usize a, usize b)
#### What is it
Least Common Multiple. Finds the smallest integer that is divisible by both `a` and `b`

#### How does it work
If either `a` or `b` is 0, it returns 0. Otherwise, it computes `(a / gcd(a, b)) * b` to avoid intermediate overflow


#### Errors
`hpanic` if the final multiplication overflows `USIZE_MAX`

---
### nextpow2(usize x)
#### What is it
Returns the smallest power of two that is greater than or equal to x.

#### How does it work
`nextpow2(0) == 1`. For `x > 0`, it calculates `k = log2ceil(x)` and returns `1 << k`

#### Errors
hpanic(ERR_OVERFLOW) if x > 2^63, because the result cannot be represented in usize