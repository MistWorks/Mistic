# Error handling module
Short functions list:

| Name                | Returns      | What it does by default       |
| ------------------- | ------------ | ----------------------------- |
| `hpanic(errtype s)` | **Noreturn** | Abort system execution        |
| `herr(errtype s)`   | void         | Write error code to `lasterr` |

## Details about each
### hpanic
#### What is it
The way function in Mistic got the state in which it can't continue work. Uses `__builtin_trap()` to abort execution of the system

Gets `errtype s` to way if you override standard `hpanic` and need to get error information

#### Override recommendations
1. Handle error code to know what exactly happened
2. Show error info somewhere
3. Halt the system instead of aborting it up

### herr
#### What is it
The way function in Mistic got the state in which it got unexpected value, but can continue work. Write error code to `lasterr`

#### Override recommendations
1. Save given `errtype s` to the `lasterr`
2. Set up handlers to each error type