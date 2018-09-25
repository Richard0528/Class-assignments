/*  Using an array passed to a function like a pointer.
    Using indexing with a pointer to access elements
    stored in a 2D array. Though the pointer received
    by the function is "Pass by Reference" (the address
    of the effected data), a copy of the actual pointer
    that contains the data address is what is actually
    passed, i.e. the actual address of the pointer is
    "Pass by Value" and the address to which it points
    is "Pass by Reference."  Thus, changing the address
    of the pointer inside the function does not effect
    the address of the pointer that is passed from the
    calling function. 
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

  // Evidence that the address of a2dArray has not been
  // corrupted by the printAsArray function:
  printf("First two elements: %c and %c\n",
         a2dArray[0][0], a2dArray[0][1]);
  return 0;
}
/* Note: The address of the array is received as a pointer
         and is used to move through the data instead of
         using a temporary pointer.  The address that is
         passed from the calling function is not effected.
*/
void printAsArray(char *a, int Rows, int Cols) {
  int i;
  char *N = a + Rows * Cols;
  for (i = 0;a < N; i++, a++)
    printf(i % 8 ? ", %c" : "\n%c", *a);
  printf("\n"); 
}
