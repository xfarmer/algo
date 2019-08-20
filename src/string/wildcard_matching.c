// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_match_back_tracking(const char *s, const char *p) {
  int m = (int) strlen(s);
  int n = (int) strlen(p);
  if (n == 0) return m == 0;

  int k = 0;
  int last_k = -1;
  int i = 0;
  int last_i = 0;
  while (i < m) {
    if (*(p + k) == *(s + i) || *(p + k) == '?') {
      ++k;
      ++i;
    } else if (*(p + k) == '*' && k < n) {
      last_k = k;
      last_i = i;
      ++k;  // Match nothing for first
    } else if (last_k != -1) {
        // If mismatch, and the last matching character is '*', then let it match one more character.
        k = last_k + 1;
        ++last_i;
        i = last_i;
    } else {
      return false;
    }
  }

  while (k < n && *(p + k) == '*') {
    ++k;
  }

  return k >= n;
}

bool is_match_recursively(const char *s, const char *p) {
  int m = (int) strlen(s);
  int n = (int) strlen(p);
  if (n == 0) return m == 0;

  bool match = m > 0 && (*s == *p || *p == '.' || *p == '*');
  if (*p == '*') {
    return is_match_recursively(s, p + 1) || (match && is_match_recursively(s + 1, p));
  } else {
    return match && is_match_recursively(s + 1, p + 1);
  }
}

bool is_match_dp(const char *s, const char *p) {
  int m = (int) strlen(s);
  int n = (int) strlen(p);
  int dp[m + 1][n + 1];
  dp[m][n] = true;
  for (int i = 0; i < m; ++i) {
    dp[i][n] = false;
  }

  for (int i = m; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      char cp = *(p + j);
      // When i == m, match is always False, because (s + i) is an empty string.
      // So we don't need to worry about the (i + 1) will be out of bounds.
      bool match = i < m && (cp == *(s + i) || cp == '?' || cp == '*');

      if (cp == '*') {
        dp[i][j] = dp[i][j + 1] || (match && dp[i + 1][j]);
      } else {
        dp[i][j] = (match && dp[i + 1][j + 1]);
      }
    }
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }

  return dp[0][0];
}

int main(void) {
  printf("Testing wildcard matching:\n");
  char *text = "ba";
  char *pattern = "*ba";
  bool match = is_match_back_tracking(text, pattern);
  printf("Pattern \"%s\" match the string: \"%s\" ?  %s\n", pattern, text, match ? "True" : "False");
}
