// Author: Farmer Li (jxli.farmer@gmail.com)
// LeetCode - 84

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG

void stack_push(int *stack, int *i, int v) {
  stack[*i] = v;
  *i += 1;
}

int stack_pop(const int *stack, int *i) {
  int v = stack[*i - 1];
  *i -= 1;

  return v;
}

int stack_peak(int *stack, const int *i) {
  return stack[(*i) - 1];
}

int largest_rectangle_area(const int* heights, int size) {
  int *stack = (int *)malloc(sizeof(int) * (size + 1));
  int k = 0;
  stack_push(stack, &k, -1);

  int max_area = 0;
  int i = 0;
  int h;
  int h_i;
  for (i = 0; i < size; ++i) {
    h = heights[i];
    h_i = stack_peak(stack, &k);
    if (k < 2 || heights[h_i] <= h) {
      // Push
      stack_push(stack, &k, i);
    } else {
      // 1. Pop to calculate current max area
      while (heights[h_i] > h) {
        h_i = stack_pop(stack, &k);
        int area = heights[h_i] * (i - stack_peak(stack, &k) - 1);
        max_area = MAX(max_area, area);
#ifdef DEBUG
        printf("Stack size: %d\n", k);
#endif
        h_i = stack_peak(stack, &k);
        if (k < 2) break;
      }
#ifdef DEBUG
      printf("Current max area: %d\n", max_area);
#endif
      // 2. Push to stack
      stack_push(stack, &k, i);
    }
  }

#ifdef DEBUG
  printf("\nPop all remaining elements...\n");
#endif
  while (k > 1) {
#ifdef DEBUG
    printf("Stack size: %d\n", k);
#endif
    h_i = stack_pop(stack, &k);
    int area = heights[h_i] * (i - stack_peak(stack, &k) - 1);
    max_area = MAX(max_area, area);
  }
  free(stack);

  return max_area;
}

int main(void) {
  printf("Testing largest_rectangle_area\n");
  int arr[] = {5, 4, 1, 2};
  int len = sizeof(arr) / sizeof(arr[0]);
  int area = 0;
  area = largest_rectangle_area(arr, len);
  printf("The largest rectangle's area in hist is: %d\n", area);
}
