#include <stdio.h>
int main() {
  short int i = 0xFFF7;
  unsigned short int j = (unsigned short int)i;
  printf("Hex = %X\nOct = %o\nDec = %d\n\n", i, i, i);
  printf("Hex = %X\nOct = %o\nDec = %d\n\n", j, j, j);

  return 0;
}
