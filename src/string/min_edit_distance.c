// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math/common_math.h"

int min_edit_distance(char *str_a, char *str_b) {
  int m = strlen(str_a);
  int n = strlen(str_b);
  if (m == 0) return n;
  if (n == 0) return m;

  int dp[m + 1][n + 1];
  memset(dp, 0, (m + 1) * (n + 1) * sizeof(int));

  for (int i = 0; i <= m; ++i) {
    dp[i][0] = i;
  }

  for (int j = 0; j <= n; ++j) {
    dp[0][j] = j;
  }

  // For "strA" and "strB", dp[i][j - 1] means the edit distance of "strA" to "str"
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      // Insert operation: "strA"(i) -> "str"(j-1), then "str" + "B"
      int insertion = dp[i][j - 1] + 1;

      // Delete operation: "str"(i-1) -> "strB"(j), then first string changed to "strBA", this step to delete "A"
      int deletion = dp[i - 1][j] + 1;

      // Substitute operation: if A == B, do nothing; else replace
      int substitution = dp[i - 1][j - 1] + (str_a[i - 1] == str_b[j - 1] ? 0 : 1);

      dp[i][j] = min(insertion, min(deletion, substitution));
    }
  }

  return dp[m][n];
}

int main(void) {
  char str_a[] = "a";
  char str_b[] = "b";
  int min_distance = min_edit_distance(str_a, str_b);
  printf("The minimum edit distance for\n\"%s\"\nand\n\"%s\"\nis: %d\n", str_a, str_b, min_distance);
}
