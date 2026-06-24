# s21_string (group project)

Custom implementation of core functionality from the C Standard Library `string.h`, including formatted input/output functions and additional string manipulation utilities.

The project focuses on low-level memory management, string processing, variadic functions, parsing algorithms, and recreating the behavior of standard C library functions.

## Overview

The library provides custom implementations of common string and memory manipulation functions without relying on the original `string.h` implementations.

In addition to standard functionality, the project includes custom versions of:

* `sprintf`
* `sscanf`
* additional string transformation utilities

The goal was to reproduce the behavior of the standard library as accurately as possible while maintaining portability and extensive test coverage.

## Implemented Functions

### Memory Operations

* `memchr`
* `memcmp`
* `memcpy`
* `memset`

### String Operations

* `strcat`-related functionality (`strncat`)
* `strchr`
* `strncmp`
* `strncpy`
* `strcspn`
* `strerror`
* `strlen`
* `strpbrk`
* `strrchr`
* `strstr`
* `strtok`

### Formatted Output

Custom implementation of:

```c
int s21_sprintf(char *str, const char *format, ...);
```

Supported features include:

* integer formatting
* floating-point formatting
* string and character formatting
* width and precision modifiers
* length modifiers
* formatting flags

### Formatted Input

Custom implementation of:

```c
int s21_sscanf(const char *str, const char *format, ...);
```

Including support for:

* numeric conversions
* string parsing
* floating-point values
* width modifiers
* length modifiers
* assignment control

### Additional Utilities

* `s21_to_upper`
* `s21_to_lower`
* `s21_insert`
* `s21_trim`

## Technical Details

* Language: C11
* Compiler: GCC
* Build system: Makefile
* Testing framework: Check
* Code style: Google C Style
* Development approach: structured programming

## Testing

The project includes:

* unit tests for all implemented functions;
* comparison against the behavior of the standard C library;
* code coverage analysis using `gcov`;
* automated test execution through Makefile targets.

## Build

```bash
make
```

Build library only:

```bash
make s21_string.a
```

Run tests:

```bash
make test
```

Generate coverage report:

```bash
make gcov_report
```
