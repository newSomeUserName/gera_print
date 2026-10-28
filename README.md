*This project has been created as part of the 42 curriculum by tgerman.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the libc `printf()` function, packaged as a
static library, `libftprintf.a`. The goal is to learn how variadic functions
work in C (`va_start`, `va_arg`, `va_end`) and how to parse a format string.

```c
int ft_printf(const char *format, ...);
```

It writes to standard output and returns the number of characters printed.

**Mandatory conversions:**

| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` for a NULL pointer) |
| `%p` | a pointer in hexadecimal with a `0x` prefix (`(nil)` for NULL) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned hexadecimal integer, lowercase / uppercase |
| `%%` | a literal percent sign |

**Bonus:** any combination of the flags `-`, `0`, `.` (precision) and a minimum
field width, plus the flags `#`, `+` and ` ` (space), for every conversion.

## Instructions

Build the library:

```sh
make          # mandatory part -> libftprintf.a
make bonus    # bonus part (flags, width, precision) -> libftprintf.a
make clean    # remove object files
make fclean   # remove object files and the library
make re       # rebuild from scratch
```

Use it in your program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("%s has %d items at %p\n", "list", 42, (void *)0x1234);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

## Algorithm and data structures

### Mandatory part

`ft_printf` walks the format string one character at a time. Ordinary
characters are written directly. When it finds `%`, the next character is
passed to a dispatcher (`ft_dispatch_char`), which reads the matching argument
with `va_arg` and calls the right printer. Each printer returns how many
characters it wrote, and those counts are added up to produce the return value.

All numbers go through one recursive function, `ft_putnmb_base(n, base, len)`.
It prints `n / len` first and then the digit `base[n % len]`. Passing the base
as a string (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`) lets
`%d`, `%u`, `%x`, `%X` and `%p` share the same code. The recursion depth is at
most 20 calls for a 64-bit value, so no buffer or `malloc` is needed. `%d`
converts the `int` to a `long` before negating it, so `INT_MIN` is handled
correctly.

### Bonus part

The bonus version parses each conversion specification into a struct:

```c
typedef struct s_spec
{
	int		minus;	/* '-' : left-justify */
	int		zero;	/* '0' : pad with zeros */
	int		hash;	/* '#' : 0x / 0X prefix */
	int		plus;	/* '+' : always print a sign */
	int		space;	/* ' ' : space before positive numbers */
	long	width;	/* minimum field width */
	long	prec;	/* precision, -1 when not given */
	char	conv;	/* conversion character */
}	t_spec;
```

Parsing follows the order of the printf grammar: flags, then width, then `.`
and precision, then the conversion character. Storing everything in one struct
first, before printing, keeps the parser and the printers separate. Each
printer gets the whole spec and does not need to know how it was parsed.

All integer conversions (`d i u x X p`) are printed by one function,
`ft_print_nbr`, which builds the output from four parts:

```
[space padding][prefix][zero padding][digits][space padding]
```

- **prefix**: `-`, `+`, ` `, `0x` or `0X`, chosen by the caller
- **zero padding**: `precision - digits` if a precision is given, otherwise
  enough zeros to fill the width when the `0` flag is set (ignored with `-`)
- **space padding**: whatever is left of the width, placed on the left, or on
  the right with `-`

Every part's length is computed before anything is written, so the return value
is known without buffering the output. Two edge cases follow the original
printf: a value of `0` with precision `0` prints no digits, and `#` adds no
prefix to `0`.

## Resources

- `man 3 printf` and `man 3 stdarg`
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: Variadic functions](https://en.cppreference.com/w/c/variadic)
- [printfTester by Tripouille](https://github.com/Tripouille/printfTester),
  used for testing against the original printf

### Use of AI

An AI assistant (Claude) was used to review the finished project against the
subject, to run the printfTester suite, and to draft this README. The library
code was written by me.
