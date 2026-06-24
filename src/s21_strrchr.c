#include "s21_string.h"

// Searches for the last occurrence of the character c (an unsigned char)
// in the string pointed to by the argument str

char *s21_strrchr(const char *str, int c) {
  char *tmp = (char *)str;

  s21_size_t len = s21_strlen(str);

  while (*tmp != '\0') tmp++;

  for (; len > 0 && *tmp != (char)c; len--) {
    tmp--;
  }

  if (len == 0 && *tmp != (char)c) tmp = S21_NULL;

  return tmp;
}
