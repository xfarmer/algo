// Author: Farmer Li (jxli.farmer@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
  int len = strlen(s);
  if (len < 2 || numRows == 1) {
    return s;
  }
  char *res = (char *) malloc(sizeof(char) * (len + 1));
  res[len] = '\0';

  int rows_offset[numRows];
  int offset = 0;
  int step = numRows + numRows - 2;
  int a = len / step;
  int b = len % step;
  for (int i = 0; i < numRows; ++i) {
//    printf("Current offset: %d\n", offset);
    rows_offset[i] = offset;
    if (i == 0) {
      offset += a;
    } else {
      offset += 2 * a;
    }

    if (b > i) {
      offset += 1;
    }
    if ((b - numRows) > (numRows - 2 - i)) {
      offset += 1;
    }
  }

  for (int j = 0; j < len; ++j) {
    int r = j % step;
    if (r >= numRows) r = numRows - (r - numRows) - 2;
    *(res + rows_offset[r]) = s[j];
    ++rows_offset[r];
  }

  strncpy(s, res, len);
  free(res);

  return s;
}

int main(void) {
  char tes[] = "12345678901";
  printf("Before convert is : %s\n", tes);
  char *res = convert(tes, 4);
  printf("Convert result is : %s\n", res);
  return 0;
}
