# Mistic
Mistic is a small C standard library that made specially for [Mist](https://github.com/MistWorks/Mist) and [Minit](https://github.com/MistWorks/Minit) and other [MistWorks](https://github.com/MistWorks) projects. It **doesn't** have any dependencies and made fully from scratch, so it may be used for bare-metal and freestanding programs

## Docs navigation
Currently, Mistic have modules such as
- [Math module](API/Freestanding/MATH.md)
- [Memory module](API/Freestanding/MEMORY.md)
- [String module](API/Freestanding/STRING.md)
- [Formatting module](API/Freestanding/FORMAT.md)

Also see [headers](HEADERS.md) specific and [error handling](API/System/HERR.md)

If you want to contribute or use it in your project, see:
- [Contributing guide](CONTRIBUTING.md)
- [Mistic convention](CONVENTION.md)

## Status and limits
- Unified error handling through [error handling system module](API/System/HERR.md) 
- [Math module](API/Freestanding/MATH.md) suppurts only integer numbers
- `herr` and `hpanic` are weak symbols, so you can **rewrite** them. See [error handling module](API/System/HERR.md) 
## Fast start
If you don't want to learn all details and just want to try, make sure that you have:
- git
- clang
- llvm-ar
- make
On your PC
Then do:

- Main directory (If it hasn't been created before):
``` shell
mkdir MistWorks && cd MistWorks
```

- Clone repo:
```shell
git clone https://github.com/MistWorks/Mistic
```

- Build:
```shell
cd Mistic
make
```

- Don't forget to link it into your project. For example, how it's done in Minit:
``` Makefile
$(BUILD_DIR)/second.elf: $(SECOND_OBJS) boot/second/linker.ld $(MISTIC)/build/mistic.a
        $(LD) -m elf_x86_64 -T boot/second/linker.ld -nostdlib -o $@ $(SECOND_OBJS) $(MISTIC)/build/mistic.a
```

- Use it!

## Get help
- [Issues](https://github.com/MistWorks/Mistic/issues)
- My [email](mailto:imdevyz@gmail.com)
- My [Telegram channel](https://t.me/DevyzLog) and [DM](https://t.me/ImDevyz)
- My Discord username: `imdevyz`

## License
All MistWorks projects use MIT License. So, you can do anything with the code, just don't forget to credit me
