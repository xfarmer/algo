// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_match(const char *text, const char *pattern) {
  int t = (int) strlen(text);
  int p = (int) strlen(pattern);
  int dp[t + 1][p + 1];
  dp[t][p] = true;
  for (int i = 0; i < t; ++i) {
    dp[i][p] = false;
  }

  for (int i = t; i >= 0; --i) {
    for (int j = p - 1; j >= 0; --j) {
      bool match = *(text + i) == *(pattern + j) || (i < t && *(pattern + j) == '.');

      if ((j + 1) < p && *(pattern + j + 1) == '*') {
        if (i < t) {
          dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
        } else {
          dp[i][j] = dp[i][j + 2] || match;
        }
      } else {
        if (i < t) {
          dp[i][j] = (match && dp[i + 1][j + 1]);
        } else {
          dp[i][j] = match;
        }
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
  bool match = is_match(text, pattern);
  printf("Pattern \"%s\" match the string: \"%s\" ?  %s\n", pattern, text, match ? "True" : "False");
}
