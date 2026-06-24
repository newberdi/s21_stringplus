#include "s21_sprintf.h"
#include "s21_string.h"


char* s21_strcat(char* dest, char* src);
void flag_width_int(char* buffer, flags* flags);
void flag_width_short(char* buffer, flags* flags);
void flag_width_float(char* buffer, flags* flags);
int flag_precision_for_g(char* temp, flags* flags, int int_len);
void flag_precision_for_f(char* temp, flags* flags, double long frac_part);
void flag_compare(flags* flags);
void format_short(char* buffer, int size, long double value, flags* flags);

// int main() {
//     //   char str1[5000];
// //   char str2[5000];
//     // char *format = "%-19f";
// //   float val = 23.14;
//   char buffer[100];
//
//     double small = -11111.1111;
//     printf("исходное число: %9.2lf\n", small);
//
//     sprintf(buffer, "\n%14.2lf\n", small);
//     printf("точность 5 знаков %s", buffer);
//     s21_sprintf(buffer, "\n%14.2lf\n", small);
//     printf("my точность 5 знаков %s", buffer);
//
//     sprintf(buffer, "\n%05.7lf\n", small);
//     printf("точность 7 знаков %s", buffer);
//     s21_sprintf(buffer, "\n%05.7lf\n", small);
//     printf("my точность 7 знаков %s", buffer);
//
//     sprintf(buffer, "\n%10.10lf\n", small);
//     printf("точность 8 знаков %s", buffer);
//     s21_sprintf(buffer, "\n%10.10lf\n", small);
//     printf("my точность 8 знаков %s\n", buffer);
//
//     // sprintf(buffer, "\n%07.10lf\n", small);
//     // printf("точность 10 знаков %s", buffer);
//     // s21_sprintf(buffer, "\n%07.10f\n", small);
//     // printf("my точность 10 знаков %s\n", buffer);
// //     printf("%s", buffer);
//
// //   int res1 = s21_sprintf(str1, format, val);
// //   int res2 = sprintf(str2, format, val);
// //   printf(" наш - %s\n не наш - %s\n", str1, str2);
// // printf("%d\n%d\n", res1, res2);
//
// // int num = 42;
// // double pi = 3.141592653589793;
// // void *ptr = &pi;
// // char *str = "Hello, world!";
// //     //mixed
//     // sprintf(buffer, "\n\nNumber: %+08d\nPi: %#.3f\nPointer: %p\nString: %s\n", num, pi, ptr, str);
//     // printf("%s", buffer);
//     // s21_sprintf(buffer, "Number: %+08d\nPi: %#.3f\nPointer: %p\nString: %s\n", num, pi, ptr, str);
//     // printf("%s", buffer);
// // s21_sprintf(buffer, "Number: %+08d\nPi: %#.3f\nString: %s\n", num, pi, str);
//     // printf("%s", buffer);
//     return 0;
// }

// int main () {
// char buffer[256];

//     // Типы int, decimal, integer
//     int num = 42;
//     sprintf(buffer, "Number: %+08d\n", num);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Number: %+08d\n", num);
//     printf("%s", buffer);

//     // Тип double, e (научный формат)
//     double d = 1234.56789;
//     sprintf(buffer, "Scientific: %e\n", d);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Scientific: %e\n", d);
//     printf("%s", buffer);

//     // Тип E (научный формат с заглавной E)
//     sprintf(buffer, "Scientific (uppercase): %E\n", d);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Scientific (uppercase): %E\n", d);
//     printf("%s", buffer);

//     // Тип f (десятичное число с плавающей точкой)
//     double pi = 3.141592653589793;
//     sprintf(buffer, "Pi: %+9.6f\n", pi);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Pi: %+9.6f\n", pi);
//     printf("%s", buffer);

//     // Тип g (короткий формат)
//     double small = 0.000123456789;
//     sprintf(buffer, "Short: %#g\n", small);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Short: %g\n", small);
//     printf("%s", buffer);

//     // Тип G (короткий формат с заглавной G)
//     sprintf(buffer, "Short (uppercase): %#G\n", small);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Short (uppercase): %G\n", small);
//     printf("%s", buffer);

//     // Тип o (восьмеричный формат)
//     unsigned int octal = 1324019243;
//     sprintf(buffer, "Octal: %o\n", octal);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Octal: %o\n", octal);
//     printf("%s", buffer);

//     // Тип s (строка)
//     char *str = "Hello, world!";
//     sprintf(buffer, "String: %s\n", str);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "String: %s\n", str);
//     printf("%s", buffer);

//     // Тип u (беззнаковое десятичное целое число)
//     unsigned int unum = 12345;
//     sprintf(buffer, "Unsigned: %u\n", unum);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Unsigned: %u\n", unum);
//     printf("%s", buffer);

//     // Тип x (шестнадцатеричный формат с маленькими буквами)
//     unsigned int hex = 255;
//     sprintf(buffer, "Hex: %#x\n", hex);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Hex: %#x\n", hex);
//     printf("%s", buffer);

//     // Тип p (указатель)
//     void *ptr = &num;
//     sprintf(buffer, "Pointer: %p\n", ptr);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Pointer: %p\n", ptr);
//     printf("%s", buffer);

//     // Тип n (число символов, записанных до этого места)
//     int n;
//     sprintf(buffer, "Count: %nHello%n\n", &n, &n);
//     printf("Count: %d\n", n);
//     s21_sprintf(buffer, "Count: %nHello%n\n", &n, &n);
//     printf("Count: %d\n", n);

//     // Тип % (процент)
//     sprintf(buffer, "Literal percent: %%\n");
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Literal percent: %%\n");
//     printf("%s", buffer);

//     char c = 'A';
//     sprintf(buffer, "Char: %s\n", &c);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Char: %s\n", &c);
//     printf("%s", buffer);

//     //mixed
//     sprintf(buffer, "\n\nNumber: %+08d\nPi: %#.3f\nPointer: %p\nChar: %s\nString: %s\n", num, pi, ptr, &c, str);
//     printf("%s", buffer);
//     s21_sprintf(buffer, "Number: %+08d\nPi: %#.3f\nPointer: %p\nChar: %s\nString: %s\n", num, pi, ptr, &c, str);
//     printf("%s", buffer);

//     return 0;
// }

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    const char* p = format;
    char* bufp = str;
    char temp[1024];

    while (*p) {

        if (*p == '%') {
            p++;
            flags flags = {0};

            p = parse_format(p, &flags);
            // printf("result: plus = %d, width =  %d, type = %c\n", flags.plus, flags.width, flags.specifier);
            flag_compare(&flags);
            switch (flags.specifier) {
                // cdieEfgGosuxXpn% //di
                case 'd': case 'i': {
                    long long value;
                    if (s21_strncmp(flags.length_modifier, "h", s21_strlen(flags.length_modifier)) == 0) {
                        value = (short)va_arg(args, int);
                    } else if (s21_strncmp(flags.length_modifier, "l", s21_strlen(flags.length_modifier)) == 0) {
                        value = va_arg(args, long);
                    } else {
                        value = va_arg(args, int);
                    }
                    format_int(temp, sizeof(temp), value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'u': {
                    unsigned long long value;
                    if (s21_strncmp(flags.length_modifier, "h", s21_strlen(flags.length_modifier)) == 0) {
                        value = (unsigned short)va_arg(args, unsigned int);
                    } else if (s21_strncmp(flags.length_modifier, "l", s21_strlen(flags.length_modifier)) == 0) {
                        value = va_arg(args, unsigned long);
                    } else {
                        value = va_arg(args, unsigned int);
                    }
                    format_unsigned_int(temp, sizeof(temp), value, &flags, 10, 0);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'o': {
                    unsigned long long value;
                    if (s21_strcmp(flags.length_modifier, "h") == 0) {
                        value = (unsigned short)va_arg(args, unsigned int);
                    } else if (s21_strcmp(flags.length_modifier, "l") == 0) {
                        value = va_arg(args, unsigned long);
                    } else {
                        value = va_arg(args, unsigned int);
                    }
                    format_unsigned_int(temp, sizeof(temp), value, &flags, 8, 0);
                    format_hash(temp, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'x': case 'X': {
                    unsigned long long value;
                    if (s21_strncmp(flags.length_modifier, "h", s21_strlen(flags.length_modifier)) == 0) {
                        value = (unsigned short)va_arg(args, unsigned int);
                    } else if (s21_strncmp(flags.length_modifier, "l", s21_strlen(flags.length_modifier)) == 0) {
                        value = va_arg(args, unsigned long);
                    } else {
                        value = va_arg(args, unsigned int);
                    }
                    format_unsigned_int(temp, sizeof(temp), value, &flags, 16, flags.specifier == 'X');
                    format_hash(temp, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'c': {
                    char value = (char)va_arg(args, int);
                    format_char(temp, value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 's': {
                    const char *value = va_arg(args, const char*);
                    format_string(temp, value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'p': {
                    void *value = va_arg(args, void*);
                    format_pointer(temp, sizeof(temp), value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'f': case 'F': {
                    long double value;
                    if (s21_strcmp(flags.length_modifier, "L") == 0) {
                        value = va_arg(args, long double);
                    } else {
                        value = va_arg(args, double);
                    }
                    format_float(temp, sizeof(temp), value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'g': case 'G': {
                    long double value;
                    if (s21_strcmp(flags.length_modifier, "L") == 0) {
                        value = va_arg(args, long double);
                    } else {
                        value = va_arg(args, double);
                    }
                    format_short(temp, sizeof(temp), value, &flags);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'e': case 'E': {
                    long double value;
                    if (s21_strcmp(flags.length_modifier, "L") == 0) {
                        value = va_arg(args, long double);
                    } else {
                        value = va_arg(args, double);
                    }
                    int uppercase= 0;
                    if (flags.specifier == 'E')
                    uppercase = 1;
                    format_scientific(temp, sizeof(temp), value, &flags, uppercase);
                    s21_strcpy(bufp, temp);
                    bufp += s21_strlen(temp);
                    break;
                }
                case 'n': {
                    int *value = va_arg(args, int*);
                    *value = bufp - str;
                    break;
                }
                case '%': {
                    *bufp++ = '%';
                    break;
                }
            }
        } else {
            *bufp++ = *p++;
        }
    }
    
    *bufp = '\0';
    va_end(args);
    return bufp - str;
}

const char* parse_format(const char* format, flags* flags) {
    const char* p = format;
    // Инициализация значений структуры
    // flags = {0};
    // flags->minus = 0;
    // flags->plus = 0;
    // flags->space = 0;
    // flags->hash = 0;
    // flags->zero = 0;
    // flags->width = 0;
    flags->precision = -1;
    // flags->length_modifier[0] = '\0';
    // flags->length_modifier[1] = '\0';
    // flags->length_modifier[2] = '\0';
    // flags->specifier = '\0';

    // Парсинг флагов
    while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0') {
        switch (*p) {
            case '-': flags->minus = 1; break;
            case '+': flags->plus = 1; break;
            case ' ': flags->space = 1; break;
            case '#': flags->hash = 1; break;
            case '0': flags->zero = 1; break;
        }
        p++;
    }

    // Парсинг ширины
    if (isdigit(*p)) {
        if (isdigit(*p) > 0) flags->width = strtol(p, (char**)&p, 10);
    }

    // Парсинг точности
    if (*p == '.') {
        p++;
        flags->precision = strtol(p, (char**)&p, 10);
    }

    // Парсинг модификаторов длины
    if (*p == 'h' || *p == 'l' || *p == 'L') {
        flags->length_modifier[0] = *p++;
        if ((*p == 'h' || *p == 'l') && (flags->length_modifier[0] == 'h' || flags->length_modifier[0] == 'l')) {
            flags->length_modifier[1] = *p++;
        }
    }
    
    // Parsing specifier
    if (s21_strchr("cdieEfgGosuxXpn%", *p)) {
        flags->specifier = *p++;
        // printf("SPECIFIER %c", flags->specifier);
    }
    return p;
}

void reverse_string(char *str, int len) {
    for (int i = 0; i < len / 2; ++i) {
        char t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
}

void format_short(char* buffer, int size, long double value, flags* flags) {
    char temp[size];
    int check = 0;
    int int_len = 0;
    int is_negative = value < 0;
    if (is_negative) {
        value = -value;
    }
    long long int_part = (long long)value;
    long double frac_part = value - int_part;


    

    while (int_part>0) {
        temp[int_len++] = '0' + (int_part % 10);
        int_part /= 10;
    }
    // int_len--;
    temp[int_len] = '\0';
    reverse_string(temp, int_len);
    
    int start = (is_negative || flags->plus || flags->space) ? 1 : 0;
    check = flag_precision_for_g(temp, flags, int_len);
    // printf("\n%s  %d  %d\n",temp, int_len, flags->precision);
    if (start) {
        temp[s21_strlen(temp)] = '\0';
        
        for(int i = s21_strlen(temp)+1; i > 0; i--) {
            temp[i] = temp[i-1];
        }
        if (is_negative) { temp[0] = '-';}
        if(!is_negative && flags->plus) { temp[0] = '+';}
        if(!is_negative && flags->space) { temp[0] = ' ';}
    }
    if(!check) {
        s21_strncpy(buffer + start, temp, int_len);
        // printf("\n temp = %s\n",temp);
        start += int_len;

        temp[start++] = '.';
        // printf("\n temp = %s\n",temp);
        // printf("frac part=%Lf\n", frac_part);
        for (int i = start-1; i <= flags->precision; ++i) {
            frac_part *= 10;
            int digit = (int)frac_part;
            temp[start++] = '0' + digit;
            frac_part -= digit;
            // printf("DONE\n");
        }

        temp[start] = '\0';
        int len = start;
        while(temp[len-1] == '0') {
            len--;
            temp[len] = '\0';
        }

        flag_width_short(buffer, flags);
        // printf("\n temp = %s\n",temp);
    }
    s21_strcpy(buffer, temp);
}

void format_float(char* buffer, int size, long double value, flags* flags) {
    char temp[size];

    int int_len = 0;
    int is_negative = value < 0;
    if (is_negative) {
        value = -value;
    }
    long long int_part = (long long)value;
    long double frac_part = value - int_part;

    while (int_part>0) {
        temp[int_len++] = '0' + (int_part % 10);
        int_part /= 10;
    }
    // int_len--;
    temp[int_len] = '\0';
    reverse_string(temp, int_len);
    
    int start = (is_negative || flags->plus || flags->space) ? 1 : 0;
    flag_precision_for_f(temp, flags, frac_part);
    // printf("here ->%s\n", temp);
    if (start) {
        temp[s21_strlen(temp)] = '\0';
        
        for(int i = s21_strlen(temp)+1; i > 0; i--) {
            temp[i] = temp[i-1];
        }
        if (is_negative) { temp[0] = '-';}
        if(!is_negative && flags->plus) { temp[0] = '+';}
        if(!is_negative && flags->space) { temp[0] = ' ';}
    }
    // printf("here ->%s\n", temp);
    //     int len = s21_strlen(temp);
    //     while(temp[len-1] == '0') {
    //         len--;
    //         temp[len] = '\0';
    //     }

    //     flag_width_float(temp, flags);
    //     // printf("\n temp = %s\n",temp);
    flag_width_float(temp,flags);
    s21_strcpy(buffer, temp);
}

void format_int(char* buffer, int size, long long value, flags* flags) {
    // printf("INT DONE\n");
    char temp[size];
    int len = 0;
    
    int is_negative = value < 0;
    unsigned long long abs_value = is_negative ? -value : value;

    while (abs_value > 0) {
        temp[len++] = '0' + (abs_value % 10);
        abs_value = abs_value / 10; 
    } 

        if (flags->precision > len) {
        int padding = flags->precision - len;
        while (padding-- > 0) {
            temp[len++] = '0';
        }
    }

    if (is_negative) {
        temp[len++] = '-';
    } else if (flags->plus) {
        temp[len++] = '+';
    } else if (flags->space) {
        temp[len++] = ' ';
    }

    reverse_string(temp, len);
    temp[len] = '\0';

    int padding = flags->width - len;
    if (padding > 0) {
        if (flags->minus) {
            s21_strcpy(buffer, temp);
            s21_memset(buffer + len, ' ', padding);
            buffer[flags->width] = '\0';
        } else {
            if (flags->zero) {
                if (temp[0] == '-' || temp[0] == '+' || temp[0] == ' ') {
                    buffer[0] = temp[0];
                    s21_memset(buffer + 1, '0', padding);
                    s21_strcpy(buffer + 1 + padding, temp + 1);
                } else {
                    s21_memset(buffer, '0', padding);
                    s21_strcpy(buffer + padding, temp);
                }
            } else {
                s21_memset(buffer, ' ', padding);
                s21_strcpy(buffer + padding, temp);
            }
            buffer[flags->width] = '\0';
        }
    } else {
        s21_strcpy(buffer, temp);
    }
}

void format_unsigned_int(char* buffer, int size, unsigned long long value, flags* flags, int base, int uppercase) {
    char temp[size];
    char* digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int len = 0;

    do {
        temp[len++] = digits[value % base];
        value /= base;
    } while (value > 0);

    reverse_string(temp, len);
    temp[len] = '\0';
    printf("   %d   ", flags->width);
    flag_width_int(temp, flags);
    s21_strcpy(buffer, temp);
}

void format_char(char *buffer, char value, flags* flags) {
    // printf("CHAR STARTED");
    int size = flags->width > 0 ? flags->width - 1 : 0;
    if (flags->minus) {
        buffer[0] = value;
        s21_memset(buffer + 1, ' ', size);
    } else {
        s21_memset(buffer, ' ', size);
        buffer[size] = value;
    }
    buffer[size + 1] = '\0';

}

void format_string(char *buffer, const char *value, flags* flags) {
    // printf("STRING DONE");
    int len = s21_strlen(value);
    if (flags->precision >= 0 && len > flags->precision) {
        len = flags->precision;
    }

    int padding = flags->width - len;
    if (padding > 0) {
        if (flags->minus) {
            s21_strncpy(buffer, value, len);
            s21_memset(buffer + len, ' ', padding);
        } else {
            s21_memset(buffer, ' ', padding);
            s21_strncpy(buffer + padding, value, len);
        }
        buffer[flags->width] = '\0';
    } else {
        s21_strncpy(buffer, value, len);
        buffer[len] = '\0';
    }
}

void format_pointer(char *buffer, int size, void *value, flags* flags) {
    unsigned long long address = (unsigned long long)value;
    format_unsigned_int(buffer, size, address, flags, 16, 0);
    for(int i = s21_strlen(buffer)+1; i >= 0; i--) {
       buffer[i]=buffer[i-2];
    }
    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[s21_strlen(buffer)+1] = '\0';
}

void format_scientific(char* buffer, int size, long double value, flags* flags, int uppercase) {
    // printf("FLOAT DONE\n");
    char temp[size];
    int len = 0;
    int counter = 0;
    int is_negative = value < 0;
    if (is_negative) {
        value = -value;
    }

    long long int_part = (long long)value;
    long double frac_part = value - int_part;

    int temp_len = 0;
    while(int_part > 10) {
        double ostatok = int_part % 10 ;
        frac_part = (frac_part / 10) + ostatok / 10;
        int_part /= 10;
        counter++;
    }

    temp[temp_len++] = '0' + (int_part % 10);

    if(flags->precision == -1) {
        flags->precision = 6;
    }

    int precision = (flags->precision == -1) ? 6 : flags->precision;
    long double rounding = 0.5;
    for (int i = 0; i < precision; ++i) {
        rounding /= 10.0;
    }
    frac_part += rounding;
    if (frac_part >= 1.0) {
        int_part += 1;
        frac_part -= 1.0;
    }

    int start = (is_negative || flags->plus || flags->space) ? 1 : 0;
    s21_strncpy(buffer + start, temp, temp_len);
    start += temp_len;

    buffer[start++] = ',';
    for (int i = 0; i < flags->precision; ++i) {
        frac_part *= 10;
        int digit = (int)frac_part;
        buffer[start++] = '0' + digit;
        frac_part -= digit;
    }

    buffer[start] = '\0';
    len = start;

    if (is_negative) {
        buffer[0] = '-';
    } else if (flags->plus) {
        buffer[0] = '+';
    } else if (flags->space) {
        buffer[0] = ' ';
    }

    // Обрабатываем ширину и заполнение
    int total_len = len;
    int padding = flags->width - total_len;

    if (padding > 0) {
        if (flags->zero && !flags->minus) {
            if (is_negative || flags->plus || flags->space) {
                s21_memmove(buffer + 1 + padding, buffer + 1, total_len - 1);
                s21_memset(buffer + 1, '0', padding);
            } else {
                s21_memmove(buffer + padding, buffer, total_len);
                s21_memset(buffer, '0', padding);
            }
            buffer[flags->width] = '\0';
        } else {
            if (flags->minus) {
                s21_memset(buffer + len, ' ', padding);
                buffer[flags->width] = '\0';
            } else {
                s21_memmove(buffer + padding, buffer, total_len);
                s21_memset(buffer, ' ', padding);
                buffer[flags->width] = '\0';
            }
        }
    }
    len = s21_strlen(buffer);
    if(uppercase) { buffer[len] = 'E'; } 
    else { buffer[len] = 'e'; }
    buffer[len+1] = '+';
    if(counter>10) {
        buffer[len+2] = counter / 10 +48;
    } else {
        buffer[len+2] = '0';
    }
    buffer[len+3] = counter % 10 + 48;
    buffer[len+4] = '\0';
}

void format_hash(char* str, flags* flags) {
    if(flags->hash) {
        if(flags->specifier == 'p' || flags->specifier == 'x' || flags->specifier == 'X') {
            for(int i = s21_strlen(str)+1; i >= 0; i--) {
                str[i]=str[i-2];
            }
            str[0] = '0';
            if(flags->specifier == 'X') { str[1] = 'X'; } 
                else { str[1] = 'x';}
            str[s21_strlen(str)-1] = '\0';
        }
        // printf("%s\n",str);
        if(flags->specifier == 'o') {
            for(int i = s21_strlen(str)+1; i >= 0; i--) {
                str[i]=str[i-1];
            }
            str[0] = '0';
            str[s21_strlen(str)-1] = '\0';
        }
    }
}

char* s21_strcat(char* dest, char* src) {
    char* ptr = dest;
    while (*ptr != '\0') {ptr++;}

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

void flag_width_int(char* buffer, flags* flags) {
    int len = s21_strlen(buffer);
    char filler = ' ';
    if (flags->zero) { filler = '0'; }
    if (len < flags->width) {
        if (flags->zero) {
            for(int i = flags->width - len, j = 0; j < len; i++, j++) {
                buffer[i] = buffer[j];
            }
            s21_memset(buffer, filler, flags->width - len);
        } else {
            for (int i = len; i < flags->width; i++) {
                buffer[i] = filler;
            }
        }
        buffer[flags->width+1] = '\0';
    }
}

void flag_width_short(char* buffer, flags* flags) {
    int len = s21_strlen(buffer);
    char filler = ' ';
    if (flags->zero) { filler = '0'; }
    if (len < flags->width)
    for (int i = len+1; i < flags->width; i++) {
            buffer[i] = filler;
        }
    buffer[flags->width+1] = '\0';
}

void flag_width_float(char* buffer, flags* flags) {
    int len = s21_strlen(buffer);
    int dif = flags->width-len;
    // printf("%d dif", dif);
    for(int y = 0; y < dif; y++) {
        for(int i = len+y; i > 0; i--) {
            buffer[i] = buffer[i-1];
            
            }
        buffer[y] = ' ';
    }

    // printf("buffer = %s", buffer);
}

int flag_precision_for_g(char* temp, flags* flags, int int_len) {
    int result = 0;
    if (int_len > flags->precision) {
        for(int i = flags->precision; i > 1; i--) {
            temp[i] = temp[i-1];
        }
        temp[1] = '.';
        if(flags->specifier == 'G') { temp[flags->precision+1] = 'E';} else {
        temp[flags->precision+1] = 'e'; }
        temp[flags->precision+2] = '+';
        if(int_len > 10) { temp[flags->precision+3] = int_len/10+48; }
        else { temp[flags->precision+3] = '0';}
        temp[flags->precision+4] = (int_len-1) % 10 + 48;
        temp[flags->precision+5] = '\0';
        // printf("DONE 1");
        result = 1;
    }
    if(int_len == flags->precision) {
        temp[flags->precision] = '\0';
        result = 1;
    }
    return result;
}

void flag_precision_for_f(char* temp, flags* flags, double long frac_part) {
    int result = 0;
    char frac[flags->precision];
    int counter;
    for(int i = 1; i <= flags->precision; i++) {
        frac_part *= 10;
        counter = (int)frac_part % 10;
        frac[i] = '0' + counter;
        // result++;
    }
    frac[0]='.';
    frac[flags->precision+1] = '\0';
    frac_part *= 10;
    counter = (int)frac_part % 10;
    if(counter % 10 > 4) {
        for(int i = frac[flags->precision]; (i>=1) && (result == 0); i++) {
            if(frac[i]<57) {
                frac[i]++;
                result++;
            }
        }
    }
    temp = s21_strcat(temp, frac);
}

void flag_compare(flags* flags) {
    if (flags->minus && flags->zero) { flags->zero = 0; }
    if (flags->plus && flags->space) {flags->space = 0;}
}
