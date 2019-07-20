// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: Farmer Li (jxli@mobvoi.com)

#ifndef ALGO_MATH_COMMON_MATH_H_
#define ALGO_MATH_COMMON_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

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
