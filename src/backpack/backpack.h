// Author: Farmer Li (jxli.farmer@gmail.com)

#ifndef ALGO_BACKPACK_BACKPACK_H_
#define ALGO_BACKPACK_BACKPACK_H_

#ifdef __cplusplus
extern "C" {
#endif

int backpack_max_value(const int *weights, const int *values, int len, int load);

int backpack_max_value_v2(const int *weights, const int *values, int len, int load);

int backpack_max_value_v3(const int *weights, const int *values, int len, int load);

int backpack_2d_max_value(const int *weights, const int *volumes, const int *values, int len, int load, int capacity);

#ifdef __cplusplus
}
#endif

#endif  // ALGO_BACKPACK_BACKPACK_H_
