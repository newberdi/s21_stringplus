#include "s21_string.h"

// Appends the string pointed to, by src to the end of the string
// pointed to, by dest up to n characters long

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (src == S21_NULL) return dest;

  s21_size_t line1 = s21_strlen(dest);
  s21_size_t line2 = s21_strlen(src);

  s21_size_t line = 0;
  if (n < line2)
    line = line1 + n + 1;
  else
    line = line1 + line2 + 1;

  dest = realloc(dest, line);

  for (s21_size_t i = line1, j = 0; i < line - 1; i++, j++) dest[i] = src[j];

  dest[line - 1] = '\0';

  return dest;
}
