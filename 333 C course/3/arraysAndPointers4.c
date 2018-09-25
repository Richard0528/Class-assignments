/*  Using indexing with a pointer to access elements
    stored in a 2D array.
*/
#include <stdio.h>
#define ROWS 12
#define COLS 8
void printAsArray(char a[][COLS], int, int);
int main(void) {
  int i, j;
  unsigned char Ascii = 'A';
  char a2dArray[ROWS][COLS]; // a 12 X 8 array of char
  char (*skippy)[COLS];      // points to array of char
  
  // fill a2dArray with ASCII's in range 'A' to 'z':
  for (skippy = &a2dArray[0]; skippy < &a2dArray[ROWS]; skippy++)
    for (j = 0; j < COLS; j++) {
      (*skippy)[j] = Ascii;
       Ascii = 'A' + (Ascii + 1 - 'A') % 58;
    }
  printAsArray(a2dArray, ROWS, COLS);

  // fill column 3 with 'X's
  for (skippy = a2dArray; skippy < a2dArray + ROWS; skippy++)
    (*skippy)[3] = 'X';
  printAsArray(a2dArray, ROWS, COLS);
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
  printf("\n"); 
}
