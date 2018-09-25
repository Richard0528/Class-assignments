/* Traversing an Array with a pointer and
   passing a pointer to an array to a function.
*/
#include <stdio.h>
#define ROWS 12
#define COLS 8
void printAsArray(char a[][COLS], int, int);
int main(void) {
  int i, j;
  unsigned char Ascii = 'A';
  char a2dArray[ROWS][COLS];  //  a 12 X 8 array of char
  char *skippy;
  skippy = a2dArray;  // or &(a2dArray[0][0]);  to make the
                      // compiler happy :-)

  // fill with ASCII's range 'A' to 'z' ONLY
  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++) {
      *skippy = Ascii;
       skippy++;
       Ascii = 'A' + (Ascii + 1 - 'A') % 58;
    }

  // reset little skippy to the start of a2dArray
  skippy = &(a2dArray[0][0]);

  // can pass a2dArray or just skippy (with warnings) or 
  // by casting skippy as below:
  printAsArray((char (*)[COLS])skippy /*a2dArray*/, ROWS, COLS);
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
