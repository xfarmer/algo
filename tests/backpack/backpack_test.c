// Author: Farmer Li (jxli.farmer@gmail.com)

#include "backpack/backpack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kLoad = 8;
int kSize = 5;
const int kWeights[5] = {6, 2, 2, /*6,*/ 5, 4};
const int kValues[5] = {5, 6, 3, /*5,*/ 4, 6};

int kLoad2d = 5;
int kCapacity2d = 3;
int kSize2d = 5;
const int kWeights2d[5] = {1, 3, 2, 0, 1};
const int kVolumes2d[5] = {1, 1, 4, 1, 0};
const int kValues2d[5] = {1, 1, 1, 1, 1};

int main(void) {
  printf("Testing backpack problem...\n");
  int max_value = backpack_max_value_v3(kWeights, kValues, kSize, kLoad);
  printf("The max value is: %d\n", max_value);

  printf("\nTesting 2d backpack problem...\n");
  max_value = backpack_2d_max_value(kWeights2d, kVolumes2d, kValues2d, kSize2d, kLoad2d, kCapacity2d);
  printf("The max value is: %d\n", max_value);

  return 0;
}
