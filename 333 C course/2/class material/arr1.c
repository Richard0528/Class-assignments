#include <stdio.h>

#define MAX 10

int main(void) {

    int arr[MAX], i;

    // not what you really want...  or is it?  Know how many bytes something is...
    printf("sizeof: %d\n", sizeof(arr));
    
    // more likely...
    printf("sizeof(array)/sizeof(element type): %d\n", sizeof(arr)/sizeof(int));

    // where are the array elements located?
    for (i = 0; i < MAX; i++) {
        printf("addr of arr[%d]: %p\n", i, &arr[i]);
    }

    // if we skip the array index and ask for the location?
    // The name of an array is like a pointer to its first element.
    printf("arr = %p\n",arr);

    return 0;
}
