#include "s21_string.h"

// Finds the first occurrence of the entire string needle (not including the
// null) which appears in the string haystack

char *s21_strstr(const char *haystack, const char *needle) {
  char *first_entry = S21_NULL;
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);
  if (haystack_len >= needle_len) {
    for (s21_size_t i = 0; i <= haystack_len; i++) {
      int match = 1;
      for (s21_size_t j = 0; j < needle_len; j++) {
        if (haystack[i + j] != needle[j]) {
          match = 0;
          break;
        }
      }
      if (match == 1) {
        first_entry = (char *)haystack + i;
        break;
      }
    }
  }
  return first_entry;
}