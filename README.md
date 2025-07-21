# MiniCRT
A minimal C runtime library (MiniCRT) for Linux (and optionally Windows), written from scratch without using the standard C library (libc). Supports custom memory allocation, file I/O, and basic printf. Designed for educational purposes and low-level systems programming.
Features
Minimal C runtime: heap, I/O, printf, string functions
No dependency on libc
Custom entry point (mini_crt_entry)
Supports both Linux and Windows (with conditional code)
Easy to debug and extend
How to Compile MiniCRT
On Linux
Apply to README.md
Explanation of flags:
-fno-builtin: Disables GCC's built-in function optimization (prevents replacement of functions like strlen, strcmp).
-nostdlib: Prevents use of standard library files and startup files from Glibc and GCC.
-fno-stack-protector: Disables stack protection (avoids undefined reference to __stack_chk_fail).
-fno-pic: Disables Position-Independent Code (important for manual .bss section handling).
On Windows
Apply to README.md
/DWIN32: Defines the WIN32 macro.
/GS-: Disables stack protection.
Compile & Run test.c
On Linux
Apply to README.md
-e mini_crt_entry: Specify entry function.
On Windows
Apply to README.md
File Descriptions
entry.c: Program entry, argument parsing, heap and IO initialization, calls main.
malloc.c: Custom heap allocator.
stdio.c: File I/O using system calls.
printf.c: Minimal printf implementation (supports %d).
string.c: Basic string functions.
minicrt.ld: Linker script for custom entry and section layout.
test.c: Example/test program.
Debugging Notes
Use GDB for debugging.
If you encounter crashes, check for calling convention issues (e.g., EBX register preservation in inline assembly).
The project has been debugged and tested in WSL2 Ubuntu 22.04.4 LTS.
