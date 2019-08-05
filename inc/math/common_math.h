// Author: Farmer Li (jxli.farmer@gmail.com)

#ifndef ALGO_MATH_COMMON_MATH_H_
#define ALGO_MATH_COMMON_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ARRAY_SIZEOF(a) (sizeof(a) / sizeof(a[0]))

static inline int max(int a, int b) {
  return a > b ? a : b;
}

static inline int min(int a, int b) {
  return a < b ? a : b;
}

#ifdef __cplusplus
}
#endif

#endif  // ALGO_MATH_COMMON_MATH_H_
