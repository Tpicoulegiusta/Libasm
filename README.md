# libasm

Reimplementation of standard C library functions in **x86-64 assembly** (NASM, Intel syntax, System V AMD64 ABI), built as a static library `libasm.a`.
Project from the 42 curriculum.

## Functions

| Function | Prototype | Notes |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s);` | |
| `ft_strcpy` | `char *ft_strcpy(char *dst, const char *src);` | Returns `dst` |
| `ft_strcmp` | `int ft_strcmp(const char *s1, const char *s2);` | Compares as `unsigned char`, like libc |
| `ft_strdup` | `char *ft_strdup(const char *s);` | Built on `malloc`, `ft_strlen` and `ft_strcpy`; returns `NULL` if `malloc` fails |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size);` | Detects `nmemb * size` overflow and sets `errno` to `ENOMEM` |
| `ft_write` | `ssize_t ft_write(int fd, const void *buf, size_t count);` | Direct `write` syscall, sets `errno` on failure |
| `ft_read` | `ssize_t ft_read(int fd, void *buf, size_t count);` | Direct `read` syscall, sets `errno` on failure |

## What this project covers

- **Calling convention**: arguments in `rdi`, `rsi`, `rdx`, return value in `rax`, caller/callee-saved registers.
- **Raw syscalls**: `read` and `write` go through `syscall` directly. A negative kernel return value is turned into a positive `errno` code via `__errno_location` (thread-safe `errno`), and the function returns `-1`, as libc does.
- **Stack alignment**: the stack is kept 16-byte aligned before every call to an external function (`malloc`, `__errno_location`).
- **Position-independent code**: external calls go through the PLT (`wrt ..plt`), so the library links into PIE executables.
- **Overflow detection**: `ft_calloc` checks the carry flag after `mul` to reject sizes that don't fit in 64 bits.

## Build and test

Requirements: Linux x86-64, `nasm`, `gcc`, `make`.

```bash
git clone https://github.com/Tpicoulegiusta/Libasm.git
cd Libasm
make              # builds libasm.a and one test program per function
./main_ft_strlen  # each test prints the result of ft_xxx next to the real libc function
./main_ft_read
```

Other rules: `make clean`, `make fclean`, `make re`.

## Using the library

```c
#include <stdio.h>

extern size_t ft_strlen(const char *s);

int main(void)
{
    printf("%zu\n", ft_strlen("hello"));
    return 0;
}
```

```bash
gcc main.c -L. -lasm -o demo
```

## Project structure

```
.
├── Makefile
├── ft_*.s          # assembly sources, one function per file
└── main_ft_*.c     # test programs comparing each function with libc
```
