
#include <stdio.h>
#include <stdlib.h>
//  NO COMPILE:  void otherFun(int arr[][]) {
//  NO COMPILE:  void otherFun(int arr[][10]) {

void otherFun(int arr[][5]) {
    printf("size of 2D array param: %d\n", sizeof(arr));
}

void oneDArrFun(int arr[]) {
    printf("First element %d\n", arr[0]);
}

int main(void) {

    int arr[4][5] ={ { 10,11,12,13,14 }, 
                     { 20,21,22,23,24 },
                     { 30,31,32,33,34 },
                     { 40,41,42,43,44 } };

    int arr1D[20] = { 50,60,70,80,90,100,110 };

int *p = (int *)malloc(sizeof(int) * 10);
printf("size of p = %d\nsize of what p points = %d\n", sizeof(p), sizeof(int));
free(p);
    otherFun(arr);
    // NO COMPILE:  otherFun(arr1D);
    oneDArrFun(arr1D);
    oneDArrFun(arr[0]);
    oneDArrFun(arr[1]);

    return 0;
}
