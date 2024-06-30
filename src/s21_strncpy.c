#include "s21_string.h"

// Copies up to n characters from the string pointed to, by src to dest

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t count_dest = 0;
  s21_size_t count_src = 0;

  while (count_dest != n) {
    if (src[count_src] != '\0') {
      dest[count_dest] = src[count_src];
      count_src++;
      count_dest++;
    } else {
      dest[count_dest] = 0;
      count_dest++;
    }
  }

  // s21_size_t c;
  // while (c < n && src[c]) {
  //   dest[c] = src[c];
  //   c++;
  // }
  // dest[c] = '\0';
  return dest;
}
