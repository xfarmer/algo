// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_match_recursively(const char *text, const char *pattern) {
  int m = (int) strlen(text);
  int n = (int) strlen(pattern);
  if (n == 0) return m == 0;

  bool match = m > 0 && (*text == *pattern || *pattern == '.');
  if (n > 1 && *(pattern + 1) == '*') {
    return is_match_recursively(text, pattern + 2) || (match && is_match_recursively(text + 1, pattern));
  } else {
    return match && is_match_recursively(text + 1, pattern + 1);
  }
}

bool is_match_dp(const char *text, const char *pattern) {
  int t = (int) strlen(text);
  int p = (int) strlen(pattern);
  int dp[t + 1][p + 1];
  dp[t][p] = true;
  for (int i = 0; i < t; ++i) {
    dp[i][p] = false;
  }

  for (int i = t; i >= 0; --i) {
    for (int j = p - 1; j >= 0; --j) {
      // When i == t, match is always False, because (text + i) is an empty string.
      // So we don't need to worry about the (i + 1) will be out of bounds.
      bool match = i < t && (*(text + i) == *(pattern + j) || *(pattern + j) == '.');

      if ((j + 1) < p && *(pattern + j + 1) == '*') {
        dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
      } else {
        dp[i][j] = (match && dp[i + 1][j + 1]);
      }
    }
  }

//  for (int i = 0; i <= t; ++i) {
//    for (int j = 0; j <= p; ++j) {
//      printf("%d ", dp[i][j]);
//    }
//    printf("\n");
//  }

  return dp[0][0];
}

int main(void) {
  printf("Testing simple regular expression matching:\n");
  char *text = "ab";
  char *pattern = ".*c";
  bool match = is_match_dp(text, pattern);
  printf("Pattern \"%s\" match the string: \"%s\" ?  %s\n", pattern, text, match ? "True" : "False");
}
