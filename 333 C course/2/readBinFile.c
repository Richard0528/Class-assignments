#include <stdio.h>

int main(void) {

    setvbuf( stdout, NULL, _IONBF, 0 );

    FILE* infile;
    long int integers[6];
    float num;
    int i = 0;
//    float a[10];   // undocument if doing the 2nd example below
    infile = fopen("numbers.bin","rb");

    // read all the long ints (there are 6 in the file):
    fread(integers, sizeof(long int), 6, infile);
    printf("Display the 6 long integers read:\n");
    for (i = 0; i < 6; i++)
       printf("%-4d", integers[i]);
    printf("\n");

    // when you call fread, it returns the number of bytes
    // it reads.   As long as it returns some bytes, you're
    // not at end of file
    i = 0;
    while (fread(&num, sizeof(float), 1, infile) != 0) {
        if (i++ % 5) {
            printf("%10.4f", num);
        } else {
            printf("\n%10.4f", num);
        }
    } 
    // if you knew there were 10 doubles in the file, you
    // could make one read into an array:
    // given:  double a[10];
    // read entire file:
    // fread(a, sizeof(float), 10, infile);
    // for (i = 0; i < 10; i++) {
    //    (i % 5) ? printf("%10.4f", a[i]) : printf("\n%10.4f", a[i]);
    // }

    fclose(infile);

    return 0;

}



