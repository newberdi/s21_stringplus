#include "s21_string.h"

// Searches for the first occurrence of the character c (an unsigned char)
// in the string pointed to, by the argument str

char *s21_strchr(const char *str, int c) {
  char *tmp = (char *)str;

  while (*tmp != c && *tmp != '\0') {
    tmp++;
  }

  if (*tmp == '\0' && c != '\0') tmp = S21_NULL;

  return tmp;
}
