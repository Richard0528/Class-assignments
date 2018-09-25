#include <stdio.h>

/*  char and unsigned char are very different.
    char values range from -128 to 127
    unsigned char values range from 0 to 255 */

int main(void) {

    char arr[] = { 100, 213, 50, -56 };

    int i;

    for (i = 0; i < 4; i++) {
        printf("%d\n", (int)arr[i]);
    }

    printf("\n");

    unsigned char uarr[] = { 100, 213, 50, -56 };

    for (i = 0; i < 4; i++) {
        printf("%d\n", (int)uarr[i]);
    }

} 

