*This project has been created as part of the 42 curriculum by edolemai.*

# ft_printf

## Description

The **ft_printf** project consists of recreating the standard C `printf()` function.

The goal is to understand and implement variadic functions in C using `va_start`, `va_arg` and `va_end`.

This project introduces formatted output, argument handling and number conversion between different bases.

The implementation creates a static library named `libftprintf.a` containing a custom version of `printf()` called `ft_printf()`.

### Supported conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal number in lowercase. |
| `%X` | Prints an unsigned hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

To compile the library, clone the repository and run:

```bash
make
```

This generates the static library:

```bash
libftprintf.a
```

### Available Makefile rules

| Command | Description |
|---|---|
| `make` | Compiles the library. |
| `make all` | Compiles the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Recompiles the project from scratch. |

### Usage

To use `ft_printf()` in your own C project, include the header:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror -Iincludes main.c -L. -lftprintf -o programme
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

## Algorithm and Data Structures

### 1. Format parsing

The main function `ft_printf()` reads the format string character by character using an index.

When a normal character is encountered, it is printed directly.

When a `%` character is encountered, the next character is interpreted as a conversion specifier.

The function `ft_check()` handles one step of the format string: it prints plain characters directly, or, after a `%`, identifies the specifier and calls the corresponding output function. It then moves the index past what it has just processed (one character for plain text, two for a conversion).

Edge cases:

- A lone `%` at the end of the format string makes `ft_printf()` return `-1`, like the original `printf()`.
- A `NULL` format string returns `-1`.
- If `write()` fails (for example when the standard output is closed), `ft_printf()` returns `-1`.

### 2. Variadic arguments

The project uses the C standard library's variadic argument macros:

- `va_start`: Initializes the argument list.
- `va_arg`: Retrieves the next argument with the expected type.
- `va_end`: Ends the argument list.

The `va_list` structure allows `ft_printf()` to process a variable number of arguments.

Each conversion retrieves its corresponding argument and sends it to the appropriate function.

The `va_list` is passed to the helper functions **by pointer** (`va_list *`). The C standard states that if a function receives a `va_list` by value and calls `va_arg` on it, the caller's copy becomes indeterminate. Passing a pointer guarantees that every helper advances the same list, on every platform (on some systems, such as Windows or ARM, passing it by value makes every conversion read the first argument again).

### 3. Number conversion algorithm

The project uses recursive algorithms to print numbers.

For decimal numbers, the algorithm divides the number by 10 until the remaining value is smaller than 10.

For hexadecimal numbers, the same principle is applied using the length of the selected base.

The remainder determines which character must be printed from the base string.

This approach allows the same base conversion function to handle both lowercase and uppercase hexadecimal output.

### 4. Data structures

No complex data structures such as linked lists, arrays or trees are required for this project.

The implementation relies on:

- `va_list` to manage variadic arguments.
- An integer index to navigate through the format string.
- An integer counter passed by pointer to track the number of printed characters.
- `uintmax_t` to handle unsigned values during base conversion.
- `uintptr_t` to convert pointer addresses into an integer representation.

Passing the character counter by pointer allows all output functions to update the same counter.

### 5. Output functions

The output is handled using the `write()` system call.

The project is divided into several helper functions:

| Function | Responsibility |
|---|---|
| `ft_putchar` | Prints one character and updates the counter (sets it to `-1` if `write()` fails). |
| `ft_putstr` | Prints a string (`(null)` for a `NULL` pointer). |
| `ft_putnbr` | Prints a signed decimal number. |
| `ft_putnbr_unsigned` | Prints an unsigned decimal number. |
| `ft_putnbr_base` | Prints a number in a specified base. |
| `ft_putptr` | Prints a pointer as `0x` + hexadecimal (`(nil)` for `NULL`). |
| `ft_check` | Handles one step of the format string (plain text or a `%` conversion). |
| `ft_printf` | Parses the format string and handles variadic arguments. |

This modular approach makes the code easier to understand, maintain and extend.

## Resources

The following resources were useful for understanding the concepts involved in this project:

- [printf() – Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h – C documentation](https://en.cppreference.com/w/c/variadic.html)
- [write() – Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- [stdint.h – Integer types](https://en.cppreference.com/w/c/types/integer.html)

### AI Usage

AI tools were used as learning and support resources during this project.

They helped with:

- Understanding variadic functions and the use of `va_list`.
- Clarifying the behavior of the different `printf()` conversion specifiers.
- Understanding integer types such as `uintptr_t` and `uintmax_t`.
- Structuring and documenting the project in this README.