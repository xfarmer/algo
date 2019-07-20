// Author: Farmer Li (jxli.farmer@gmail.com)

#include "string/longest_palindrome.h"

#include <stdio.h>
#include <string.h>

static int expandFromCenter(const char *s, int l, int r) {
  int len = 0;
  while (*(s + l) == *(s + r) && (s <= (s + l)) && *(s + r) != '\0') {
    len = r - l;
    --l;
    ++r;
  }

  return len + 1;
}

char * longestPalindrome(char * s) {
  if (s == NULL || *s == '\0') return "";

  int max_len = 1;
  char *ps = s;
  int l = 0;
  int r = 1;
  int str_len = strlen(s);

  while (r < str_len) {
    int len = expandFromCenter(s, l, r);
    if (len > max_len) {
      max_len = len;
      ps = s + (l - (len + l - r - 1) / 2);
    }

    if (l < r) {
      ++l;
    } else {
      ++r;
    }
  }

  *(ps + max_len) = '\0';

  return ps;
}

int main(void) {
  char test[] = "abcdefggfedg";
  printf("Longest palindrome of \n\"%s\"\nis:\n", test);
  char *res = longestPalindrome(test);
  printf("\"%s\"\n",res);

  return 0;
}
