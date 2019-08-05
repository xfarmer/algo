// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <zconf.h>

static inline bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

static inline int digit_to_int(char c) {
  if (!is_digit(c)) {
    return -1;
  } else {
    return c - '0';
  }
}

int my_atoi(const char *str) {
  int length = strlen(str);
  int state = 0;
  long value = 0;
  bool is_positive = true;

  for (int i = 0; i < length; ++i) {
    if (state == 0) {
      if (str[i] == ' ') {
        continue;
      } else if (str[i] == '-') {
        is_positive = false;
        state = 1;
        continue;
      } else if (str[i] == '+') {
        state = 1;
        continue;
      } else if (is_digit(str[i])) {
        state = 1;
        value = value * 10 + digit_to_int(str[i]);
      } else {
        return 0;
      }
    } else if (state == 1) {
      if (is_digit(str[i])) {
        value = value * 10 + digit_to_int(str[i]);
        if (value > INT_MAX) break;
      } else {
        break;
      }
    }
  }

  if (!is_positive) value = -value;

  if (value > INT_MAX) {
    value = INT_MAX;
  } else if (value < INT_MIN) {
    value = INT_MIN;
  }

  return (int)value;
}

int main(void) {
  char *str = "91283472332a   -123 asdfa";
  int result = my_atoi(str);
  printf("Value of my_atoi for string:\n\"%s\"\nis:\n%d\n", str, result);
}
