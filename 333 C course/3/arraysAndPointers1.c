/*  Simulate a 2D array by allocating the
    necessary bytes to a pointer.  Fill
    it with data (rows/cols) like a
    2D array.  Then pass this pointer to
    a function that sees it as a 2D arrray.
*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 12
#define COLS 8
void printAsArray(char a[][COLS], int, int);
int main(void) {
  int i, j;
  unsigned char Ascii = 'A';
  int size = 96;  //  for a 12 X 8 array of char
  char *p = (char *)malloc(size);  // treat as a memory place holder
  char *skippy;
  skippy = p;

  // Fill using ASCII range 'A' - 'z' like a 2D array:
  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++) {
      *skippy = Ascii;
      printf("skippy address currently is %p\n", skippy);
      skippy++;
      printf("Ascii currently is %d\n", Ascii);
      Ascii = 'A' + (Ascii + 1 - 'A') % 58;

    }
  printAsArray((char (*)[])p, ROWS, COLS);
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
