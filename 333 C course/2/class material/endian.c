/*
 * endian.c
 *
 *  Created on: April 3, 2017
 *  Author: David Schuessler
 */
#include <stdio.h>

int main ()
{
  unsigned int x = 0xEBCD4A10U;
  char *c = (char *) &x;
  int i= 0;
  unsigned int val;
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
printf("Walking along the 4 bytes of x from left to right (lower to higher memory):\n");
for (; i < 4; i++, c++) {
	val = (unsigned char)*c;
	printf("%X ", val);
}
  return 0;
}

