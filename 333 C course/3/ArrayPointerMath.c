/* Pointer arithmetic with arrays:
 *    The result of adding or subtracting two pointers
 *    that point to two elements of an array MUST be
 *    a value within the range of the valid indices of
 *    the array, i.e. 0 - length of the array - 1.  If 
 *    not, the result is undefined!
 */
#include <stdio.h>
#include <stdlib.h>

void main(void) {
  char a[5] = {'a', 'b','c', 'd', 'e'};
  char *p, *q;
  p = &a[4];
  q = &a[1];
  printf("Addresses of a, p & q are: %p, %p, %p\n", a, p, q);
  printf("Addresses in Decimal  are: %U, %U, %U\n\n", a, p, q);
  printf("             Character at p: %c\n", *p);              
  printf("             Character at q: %c\n", *q);
  printf("      Character at a[p - q]: %c\n", a[p - q]);
  printf("      Character at a[4 - 1]: %c\n", a[4 - 1]);
  printf("  Character at *(a + 4 - 1): %c\n", *(a + 4 - 1));
  printf("     Address of a + (p - q): %U\n", a + (p - q));
  printf("Character at *(a + (p - q)): %c\n", *(a + (p - q)));
  printf("\nBTW, the address of p - q is NOT within the array:\n");
  printf("Addresses of a and last element are: %U, %U\n", a, &a[4]);
  printf("Addresses of p - q is: %U\n", p - q);
  a[p - q] = 'X';
  printf("\nJust assigned 'X' to a[p - q], see: %c\n\n", a[p - q]);
  printf("Assigning 'X' to *((char *)(p - q)). Watch OUT!!!!:\n");
  *((char *)(p - q)) = 'X';


}