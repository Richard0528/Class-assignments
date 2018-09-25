#include <stdio.h>

/* This program simply copies the original image 
   to a new identical file */

int main(void) {

    FILE *infile = fopen("test1.bmp", "rb"); 
    FILE *outfile = fopen("copytest1.bmp", "wb");
   
    char arr[115254];


    fread( arr, 1 , 115254 , infile);
    fwrite( arr, sizeof(char)  , 115254  ,  outfile);

    fclose(infile);
    fclose(outfile);

    return 0;

}

