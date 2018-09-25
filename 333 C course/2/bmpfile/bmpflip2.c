#include <stdio.h>

/* This program flips the image upside down and creates
   two bmp files, one with the full image upside down and
   a second version with the top half of the upside down
   image blanked out with white to demonstrate that the
   pixel data is stored from the lower left first. */

int main(void) {

    FILE *infile = fopen("test1.bmp", "rb");      // open for binary input
    FILE *outfile = fopen("test1flip.bmp", "wb"); // open for binary output
    FILE *o2 = fopen("test1flip2.bmp", "wb");     // open for binary output
 
     
    
    char header1[34];
    int sizeOfImage; 
    char header2[16];

    char pixels[160][240*3];
    char p2[80][240 * 3];
    int i, j;
    // fill p2 with white pixel values
    for (i = 0; i < 80; i++)
        for (j = 0; j < 240 * 3; j++)
            p2[i][j] = 0xFF;


    fread( header1, 1 , 34 , infile);
    fread( &sizeOfImage, sizeof(int) , 1,  infile);
    fread( header2, 1 , 16 , infile);

    printf("Size of image = %d\n", sizeOfImage);

    fread( pixels, 1 , 115200 , infile);

    int r,c;

    for( r = 0; r < 160/2; r++) {   // only loop across 1/2 the rows
         for ( c = 0; c < 240*3; c++) {
              char temp = pixels[r][c];
              pixels[r][c] = pixels[159-r][c];
              pixels[159-r][c] = temp;
         }
    }


    fwrite( header1, 1 , 34 , outfile);
    fwrite( &sizeOfImage, sizeof(int) , 1,  outfile);
    fwrite( header2, 1 , 16 , outfile);

    fwrite( pixels, 1 , 115200 , outfile);
// output to 2nd file:
    fwrite( header1, 1 , 34 , o2);
    fwrite( &sizeOfImage, sizeof(int) , 1,  o2);
    fwrite( header2, 1 , 16 , o2);
// flip the lower half of the image
    fwrite( pixels, 1 , 57600 , o2);
// fill the upper half with white pixels
    fwrite( p2, 1 , 57600 , o2);


    fclose(infile);
    fclose(outfile);
    fclose(o2);
    return 0;

}

