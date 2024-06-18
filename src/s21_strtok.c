
#include "s21_string.h"

// Breaks string str into a series of tokens separated by delim

char *s21_strtok(char *str, const char *delim) {
  static char *tok = S21_NULL;
  char *start;

  if (str) {
    tok = str;
  }

  if (tok == S21_NULL) {
    return S21_NULL;
  }

  start = tok + s21_strspn(tok, delim);
  if (*start == '\0') {
    tok = S21_NULL;
    return S21_NULL;
  }

  tok = start + s21_strcspn(start, delim);
  if (*tok != '\0') {
    *tok = '\0';
    tok++;
  } else {
    tok = S21_NULL;
  }

  return start;
}

// int main () {
//    char str[80] = "hello there awweww";
//    const char s[2] = " ";
//    char *token;

//    token = s21_strtok(str, s);

//    while( token != S21_NULL) {
//       printf(" %s\n", token);

//       token = s21_strtok(S21_NULL, s);
//    }

//    return(0);
// }