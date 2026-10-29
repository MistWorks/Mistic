# Contributing

There is a [contributing guide](https://github.com/MistWorks/Docs/CONTRIBUTING.md) in [MistWorks/Docs](https://github.com/MistWorks/Docs). Basically follow these instructions

But to contribute to Mistic, you also have to follow its specification

## Mistic-specific rules

### Code boundaries
- All functions that work without user support are in `freestanding/`
- Functions that require user support (or can be improved by it) are in `sys/`

### Code specific
- Mistic **must not depend** on anything
- **But** modules can depend on each other
- Freestanding **only**: no `<stdint.h>`, `<elf.h>`, or any other standard/system headers

### Error model
- `hpanic` — fatal, weak, `noreturn`
- `herr` — recoverable, weak. If you override it, update `lasterr` (or document why you don't)
### Tests
There is no automated test suite yet. Changes must be compiled and manually verified in a real Mist or Minit build (or on the host)