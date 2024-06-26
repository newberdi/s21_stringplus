#include "s21_string.h"

// Copies up to n characters from the string pointed to, by src to dest

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t c = 0;
  while (c < n && src[c]) {
    dest[c] = src[c];
    c++;
  }
  dest[c] = '\0';
  return dest;
}
