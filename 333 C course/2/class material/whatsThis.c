#include <stdio.h>
void main(void) {
  int x = -1, y = 3;
  printf("x = %d, y = %d\n", x, y);
  x ^= y;
  y ^= x;
  x ^= y;
  printf("x = %d, y = %d\n", x, y);
}
  