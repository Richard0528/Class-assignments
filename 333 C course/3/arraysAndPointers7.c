/*  Using an array passed to a function like a pointer.
    Using indexing with a pointer to access elements
    stored in a 2D array.
*/
#include <stdio.h>
#define ROWS 12
#define COLS 8
void printAsArray(char *, int, int);
int main(void) {
  int j;
  unsigned char Ascii = 'A';
  char a2dArray[ROWS][COLS]; // a 12 X 8 array of char
  char (*skippy)[COLS];      // points to array of char
  
  // fill a2dArray with ASCII's in range 'A' to 'z':
  for (skippy = &a2dArray[0]; skippy < &a2dArray[ROWS]; skippy++)
    for (j = 0; j < COLS; j++) {
      (*skippy)[j] = Ascii;
       Ascii = 'A' + (Ascii + 1 - 'A') % 58;
    }
  printAsArray((char *)a2dArray, ROWS, COLS);

  return 0;
}
// Use received pointer to the array to traverse
// the data using indexing:
void printAsArray(char *a, int Rows, int Cols) {
  int i;
  int size = Rows * Cols;
  for (i = 0;i < size; i++)
    printf(i % 8 ? ", %c" : "\n%c", a[i]);
  printf("\n"); 
}
