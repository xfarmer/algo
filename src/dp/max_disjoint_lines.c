// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdio.h>
#include <string.h>

#include "math/common_math.h"

int max_disjoint_lines(const int *arr1, int size_1, const int *arr2, int size_2) {
  int dp[size_1 + 1][size_2 + 1];

  for (int i = 0; i <= size_1; ++i) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= size_2; ++j) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= size_1; ++i) {
    for (int j = 1; j <= size_2; ++j) {
      dp[i][j] = dp[i - 1][j - 1];
      if (arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] += 1;
      }

      dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
      dp[i][j] = MAX(dp[i][j], dp[i][j - 1]);
    }
  }

  return dp[size_1][size_2];
}

int main(void) {
  int arr1[] = {2, 5, 1, 2, 5};
  int arr2[] = {10, 5, 2, 1, 5, 2};

  int res = max_disjoint_lines(arr1, ARRAY_SIZEOF(arr1), arr2, ARRAY_SIZEOF(arr2));
  printf("The max number of disjoint lines is: %d\n", res);

  return 0;
}
