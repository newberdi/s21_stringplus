#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *olds;
  char *token;

  if (str == S21_NULL) {
    str = olds;
  }
  str += s21_strspn(str, delim);
  if (*str == '\0') {
    olds = str;
    return (S21_NULL);
  }
  token = str;
  str = s21_strpbrk(token, delim);
  if (str == S21_NULL) {
    olds = s21_strchr(token, '\0');
  } else {
    *str = '\0';
    olds = str + 1;
  }
  return token;
}