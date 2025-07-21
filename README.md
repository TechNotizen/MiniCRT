# MiniCRT

A minimal C runtime library (MiniCRT) for Linux (and optionally Windows), written from scratch without using the standard C library (libc). Supports custom memory allocation, file I/O, and basic printf. Designed for educational purposes and low-level systems programming.

---

## Features

- Minimal C runtime: heap, I/O, printf, string functions
- No dependency on libc
- Custom entry point (`mini_crt_entry`)
- Supports both Linux and Windows (with conditional code)
- Easy to debug and extend

---

## How to Compile MiniCRT

### On Linux

```
gcc -c -m32 -ggdb -fno-builtin -nostdlib -fno-stack-protector -fno-pic entry.c malloc.c stdio.c string.c printf.c
ar -rs minicrt.a malloc.o printf.o stdio.o string.o

```

**Explanation of flags:**
- `-fno-builtin`: Disables GCC's built-in function optimization (prevents replacement of functions like `strlen`, `strcmp`).
- `-nostdlib`: Prevents use of standard library files and startup files from Glibc and GCC.
- `-fno-stack-protector`: Disables stack protection (avoids undefined reference to `__stack_chk_fail`).
- `-fno-pic`: Disables Position-Independent Code (important for manual `.bss` section handling).

### On Windows

```
cl /c /DWIN32 /GS- entry.c malloc.c printf.c stdio.c string.c
lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:minicrt.lib
```
- `/DWIN32`: Defines the WIN32 macro.
- `/GS-`: Disables stack protection.

---

## Compile & Run test.c

### On Linux

```
gcc -c -m32 -ggdb -fno-builtin -nostdlib -fno-stack-protector -fno-pic test.c
ld -m elf_i386 -static -e mini_crt_entry entry.o test.o minicrt.a -o test -T minicrt.ld
./test arg1 arg2 123
```
- `-e mini_crt_entry`: Specify entry function.

### On Windows

```
cl /c /DWIN32 test.c
link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry
```

---

## File Descriptions

- `entry.c`: Program entry, argument parsing, heap and IO initialization, calls main.
- `malloc.c`: Custom heap allocator.
- `stdio.c`: File I/O using system calls.
- `printf.c`: Minimal printf implementation (supports `%d`).
- `string.c`: Basic string functions.
- `minicrt.ld`: Linker script for custom entry and section layout.
- `test.c`: Example/test program.

---

## Debugging Notes

- Use GDB for debugging.
- If you encounter crashes, check for calling convention issues (e.g., EBX register preservation in inline assembly).
- The project has been debugged and tested in WSL2 Ubuntu 22.04.4 LTS.
- printf function can only support simple output now, use it carefully
