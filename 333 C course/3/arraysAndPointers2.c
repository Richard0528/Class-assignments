/*  Simulate a 2D array by allocating the
    necessary bytes to a pointer.  Fill
    it with data simply in sequential order.
    Then pass this pointer to a function 
    that sees it as a 2D arrray.
*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 12
#define COLS 8
void printAsArray(char [][COLS], int, int);

int main(void) {
  int i, j;
  unsigned char Ascii = 'A';
  int size = ROWS * COLS;  //  for a 12 X 8 array of char
  char *skippy, *p = (char *)malloc(size);
  skippy = p;

  //  Fill with ASCII's & Simply skip along each element linearly
  for (i = 0; i < size; i++, skippy++) {
    *skippy = Ascii;
    Ascii = 'A' + (Ascii + 1 - 'A') % 58;
  }
  printAsArray((char (*)[COLS])p, ROWS, COLS);
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