#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "s21_string.h"

typedef struct flags {
    int minus;
    int plus;
    int space;
    int hash;
    int zero;
    int width;
    int precision;
    char length_modifier[3];
    char specifier;
} flags;

int s21_sprintf(char *str, const char *format, ...);
int flags_check(flags* flags);
const char* parse_format(const char* format, flags* flags);
void format_int(char *buffer, int size, long long value, flags* flags);
void format_unsigned_int(char* buffer, int size, unsigned long long value, flags* flags, int uppercase, int base);
void format_float(char *buffer, int size, long double value, flags* flags);
void format_char(char *buffer, char value, flags* flags);
void reverse_string(char *str, int len);
void format_string(char *buffer, const char *value, flags* flags);
void format_pointer(char *buffer, int size, void *value, flags* flags);
void format_scientific(char* buffer, int size, long double value, flags* flags, int uppercase);
void format_hash(char* str, flags* flags);

#endif  // S21_STRING_H
