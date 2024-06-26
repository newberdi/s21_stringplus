#include "s21_string.h"

// Finds the first occurrence of the entire string needle (not including the
// null) which appears in the string haystack

// haystack - входная строка в которой будет поиск подстроки
// needle - указатель на подстроку

char *s21_strstr(const char *haystack, const char *needle) {
  if (s21_strlen(needle) == 0) return (char *)haystack;

  char *s21_haystack = (char *)haystack;
  char *s21_needle = (char *)needle;

  char *first_entry = S21_NULL;

  for (; *s21_haystack != '\0' && *s21_needle != '\0'; s21_haystack++) {
    if (*s21_haystack == *s21_needle) {
      if (first_entry == S21_NULL) first_entry = s21_haystack;
      s21_needle++;
    } else {
      first_entry = S21_NULL;
      s21_needle = (char *)needle;
    }
  }

  return first_entry;
}