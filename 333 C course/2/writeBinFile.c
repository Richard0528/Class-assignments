/*
 Use XVI32 Hex editor to view binary values stored in a file "numbers.bin"

 IEEE floating point standard for:
     2.0    = 0^100 0000 0^000 0000 0000 0000 0000 0000  or 
              0100 0000 0000 0000 0000 0000 0000 0000
               4    0    0    0    0    0    0    0   in HEX
     6.625  = 0^100 0000 1^101 0100 0000 0000 0000 0000  or
              0100 0000 1101 0100 0000 0000 0000 0000
               4    0    D    4    0    0    0    0   in HEX
    -6.625  = 1^100 0000 1^101 0100 0000 0000 0000 0000  or
              1100 0000 1101 0100 0000 0000 0000 0000
               C    0    D    4    0    0    0    0   in HEX
    -0.0625 = 1^011 1101 1^000 0000 0000 0000 0000 0000
              1011 1101 1000 0000 0000 0000 0000 0000
               B    D    8    0    0    0    0    0   in HEX

*/
#include <stdio.h>
int main(void) {

  FILE* outfile;
  int i;
  long int integers[] = {18, -3, 26, 11, -1, 3}; 
                      // 6 5/8  -6 5/8                         -1/16
  float nums[10] = {2.0, 6.625, -6.625, 20.2987, 13.5,  30.25, -0.0625};
  outfile = fopen("numbers.bin","wb");
 
  // write values to file 1 at a time:
  for (i = 0; i < 6; i++)
     fwrite(&(integers[i]), sizeof(long int), 1, outfile);

  // Or... calculate # of bytes of all values and send all at once:
  fwrite(nums, sizeof(float), 10, outfile);
 
  fclose(outfile);

  return 0;
}

