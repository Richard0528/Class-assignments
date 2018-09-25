#include <stdio.h>
void demoFun(int [], int *);
int main(void) {
    int arrA[10] = {10,20,30,40,50};
    int arrB[20] = {100,200,300,400,500};

    printf("sizeof array arrA: %d\n", sizeof(arrA));
    printf("sizeof array arrB: %d\n", sizeof(arrB));
    
    printf("in main, addr of arrA[0]: %p\n", &arrA[0]);
    printf("in main, addr of arrB[0]: %p\n", &arrB[0]);

// OR...
    printf("in main, addr of arrA[0]: %p\n", arrA);
    printf("in main, addr of arrB[0]: %p\n", arrB);

    demoFun(arrA, arrA);
    demoFun(arrB, arrB);

    return 0;
}
void demoFun(int arr[], int *ptr) {
    printf("first element = %d\n", arr[0]);
    printf("in fun, addr of arr[0]: %p\n", &arr[0]);
    printf("sizeof array param: %d\n", sizeof(arr));

    printf("first element = %d\n", *ptr);
    printf("in fun, addr of *ptr: %p\n", ptr);
    printf("sizeof array param: %d\n", sizeof(ptr));
}



