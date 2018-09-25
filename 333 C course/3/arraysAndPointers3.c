/*  Shows another way to iterate the
    simulated 2D structure.
*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 12
#define COLS 8
void printAsArray(char a[][COLS], int, int);

int main(void) {
  int i, j;
  char *skipNoMore;
  unsigned char Ascii = 'A';
  int size = ROWS * COLS;  //  for a 12 X 8 array of char
  char *skippy, *p = (char *)malloc(size);
  skippy = p;

  //  Fill with ASCII's & Simply skip along each element linearly
  for (i = 0; i < size; i++, skippy++) {
    *skippy = Ascii;
    Ascii = 'A' + (Ascii + 1 - 'A') % 58;
  }
 
  // Curious??  What is the address of p + size?
  printf("Address of p = %p\nAddress of p + size = %p\n",
          p, p + size);

  // So...  we can do the previous loop this way:
  Ascii = 'A';
  skipNoMore = p + size;
  for (skippy = p; skippy < skipNoMore /*p + size*/; skippy++) {
    *skippy = Ascii;
    Ascii = 'A' + (Ascii + 1 - 'A') % 58;
  }

  printAsArray(p, ROWS, COLS);
  for (i = 0, skippy = p; i < size; i++, skippy++)
    if (i % 8)
      printf(", %c", *skippy);
    else
      printf("\n%c", *skippy);
  free(p);
  return 0;
}
void printAsArray(char a[][COLS], int Rows, int Cols) {
  int row, col;
  for (row = 0; row < Rows; row++) {
    printf("%c", a[row][0]);
    for (col = 1; col < Cols; col++)
      printf(", %c", a[row][col]);
    printf("\n");
  } 
}