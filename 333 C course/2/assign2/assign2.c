// TCSS 333 - assignment2
// Zhihao Yang

#include <stdio.h>

int main(void) {
    // read files
    FILE *infile1 = fopen("in1.bmp", "rb");
    FILE *infile2 = fopen("in2.bmp", "rb");

    FILE *outfile1 = fopen("blend.bmp", "wb");
    FILE *outfile2 = fopen("checker.bmp", "wb");

    // two char arrays to store header data
    char header1[54];
    char header2[54];

    char pixels1[408][408*3];
    char pixels2[408][408*3];

    fread(header1, 1, 54, infile1);
    fread(pixels1, 1, 499392, infile1); // read in1 image data
    fread(header2, 1, 54, infile2);
    fread(pixels2, 1, 499392, infile2); // read in2 image data

    // calculate the new image data for blend.bmp
    unsigned char blendpixels[408][408*3];
    int i, j;
    for (i = 0; i < 408; i++) {
        for (j = 0; j < 408*3; j++) {
            blendpixels[i][j] = ((unsigned char) pixels1[i][j] + (unsigned char) pixels2[i][j]) / 2;
        }
    }
    // write everthing into outfile1
    fwrite(header2, 1, 54, outfile1); // write in header
    fwrite(blendpixels, 1, 499392, outfile1); // write in image data
    

    // create image data for chekcer.bmp
    unsigned char checkerpixels[408][408*3];
    for (i = 0; i < 408; i++) {
        for (j = 0; j < 408*3; j++) {
            // decide whether current row is odd or even
            if (i / 51 % 2 == 0) {
                // fill in the pixels
                if (j / 153 % 2 == 0) {
                    checkerpixels[i][j] = pixels1[i][j];
                } else {
                    checkerpixels[i][j] = pixels2[i][j];
                }

            } else {

                if (j / 153 % 2 == 1) {
                    checkerpixels[i][j] = pixels1[i][j];
                } else {
                    checkerpixels[i][j] = pixels2[i][j];
                }

            }

        }
    }
    // write everything into outfile2
    fwrite(header1, 1, 54, outfile2);
    fwrite(checkerpixels, 1, 499392, outfile2);

    // close files
    fclose(infile1);
    fclose(infile2);
    fclose(outfile1);
    fclose(outfile2);

    return 0;

}