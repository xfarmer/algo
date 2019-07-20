// Author: Farmer Li (jxli.farmer@gmail.com)

#include "backpack/backpack.h"

#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int backpack_max_value(const int *weights, const int *values, int len, int load) {
  int table[len][load];

  for (int j = 1; j <= load; ++j) {
    int j_index = j - 1;

    // 对于第一种物品，只需要考虑能不能装下
    if (j >= weights[0]) {
      // 如果能装下，则为此物品的价值
      table[0][j_index] = values[0];
    } else {
      // 装不下则价值为0
      table[0][j_index] = 0;
    }

    // 对于接下来的要加入的物品，先看能不能放下
    for (int i = 1; i < len; ++i) {
      if (j > weights[i]) {
        // #1# 如果能放下，并且有剩余空间，则考虑下面两种情况的最大值：
        //     a. 不装当前物品，剩下的物品能最多装多少
        //     b. 装当前物品，加上剩下的空间装剩下的物品最多能装多少
        // 这里的最多能装多少就是一个动态规划的过程
        table[i][j_index] = MAX(table[i - 1][j_index], table[i - 1][j - weights[i] - 1] + values[i]);
      } else if (j == weights[i]) {
        // #2# 如果刚好能放下，则考虑下面两种情况的最大值：
        //     a. 不装当前物品，剩下的物品能最多装多少
        //     b. 只装当前物品
        table[i][j_index] = MAX(table[i - 1][j_index], values[i]);
      } else {
        // #3# 如果装不下，那么就等于能装剩余物品的最大值
        table[i][j_index] = table[i - 1][j_index];
      }
    }
  }

  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < load; ++j) {
      printf("%3d ", table[i][j]);
    }
    printf("\n");
  }

  return table[len - 1][load - 1];
}

int backpack_max_value_v2(const int *weights, const int *values, int len, int load) {
  int dp[len + 1][load + 1];
  memset(dp, 0, sizeof(int) * (len + 1) * (load + 1));

  for (int i = 1; i <= len; ++i) {
    for (int j = weights[i - 1]; j <= load; ++j) {
      dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
    }
  }

  for (int i = 0; i < len + 1; ++i) {
    for (int j = 0; j < load + 1; ++j) {
      printf("%3d ", dp[i][j]);
    }
    printf("\n");
  }

  return dp[len][load];
}

int backpack_max_value_v3(const int *weights, const int *values, int len, int load) {
  int dp[load + 1];
  memset(dp, 0, sizeof(int) * (load + 1));

  for (int i = 1; i <= len; ++i) {
    for (int j = load; j >= weights[i - 1]; --j) {
      dp[j] = MAX(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
    }
  }

  for (int j = 0; j < load + 1; ++j) {
    printf("%3d ", dp[j]);
  }
  printf("\n");

  return dp[load];
}

int backpack_2d_max_value(const int *weights, const int *volumes, const int *values, int len, int load, int capacity) {
  int dp[load + 1][capacity + 1];
  memset(dp, 0, sizeof(int) * (load + 1) * (capacity + 1));
  for (int i = 0; i < len; ++i) {
    int w = weights[i];
    int v = volumes[i];
    for (int j = load; j >= w; --j) {
      for (int k = capacity; k >= v; --k) {
        dp[j][k] = MAX(dp[j][k], values[i] + dp[j - w][k - v]);
      }
    }

    for (int ii = 0; ii < load + 1; ++ii) {
      for (int jj = 0; jj < capacity + 1; ++jj) {
        printf("%3d ", dp[ii][jj]);
      }
      printf("\n");
    }
    printf("\n######################\n");
  }

  for (int i = 0; i < load + 1; ++i) {
    for (int j = 0; j < capacity + 1; ++j) {
      printf("%3d ", dp[i][j]);
    }
    printf("\n");
  }

  return dp[load][capacity];
}
