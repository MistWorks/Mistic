# Convention

Mistic is a freestanding library. It does not impose a policy on how errors are handled. The rules below are the **default contract** and your project may override them

## Error levels
Mistic distinguishes two levels of errors:

### Panic (fatal)
The program cannot continue. Examples:
- `log2floor(0)`, `log2ceil(0)`
- `strlen(NULL)`, `striseq(NULL, x)`
- `copy(NULL, src, n)` with `n > 0`

**Valid no-op cases** (not panics):
- `copy(NULL, NULL, 0)`
- `copyfb(NULL, NULL, 0)`
- `fill(NULL, val, 0)`
- `iseq(NULL, NULL, 0)` → `true`

Default `hpanic()` calls `__builtin_trap()`

### Error (recoverable)
The program can continue. Examples:
- Overlapping buffers in `copy()` (you can use `copyfb`)
- `format(val, base)` with `base < 2` or `base > 36`
- Truncation in `strcopy`

The error code is stored in `lasterr` (of type `errtype`)

Default `herr()` writes to `lasterr` and returns

## Overriding
You can override `hpanic` and `herr` in your project with strong 
definitions. See [contributing guide for more details](CONTRIBUTING.md)

Recommended patterns:
#### 1. Define `lasterr` in owerriden `herr`
It need to store ocerred error when it is, because standard Mistic `herr` is not called anymore

#### 2. Add logging to `hpanic`
Standard `hpanic` just shuts down the system without any messages and logging, because it don't have access to it. Your version should:
- Print the error message
- Show details
- Log it and save it somewhere
- Stop the system