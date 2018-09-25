#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/types.h>  // On some systems you may need this.
#include <sys/stat.h>     // Contains definition of struct & 
                          // function stat
unsigned long get_file_size(char *);
void processFileData(FILE *, unsigned long);
void processString(void *);
void processIntegers(void *);
void sumAndPrintIntArray(int *, int, int, int *);
void sumRowInt(int **, int, int *);
void processFloats(void *);
void sumAndPrintFloatArray(float *, int, int, float *);
void sumRowFloat(float **, int, float *);

int main(int argc, char *argv[]) {
    FILE *f;
    int goForIt = 0;
    unsigned long filesize;
    printf("argc = %d\n", argc);
    if (argc == 2)
        if (goForIt = (long)(filesize = get_file_size(argv[1])) >= 0) {
            f = fopen(argv[1], "rb");
            printf("File name: %s, size: %d\n", argv[1], filesize);
        } else
            printf("ERROR! %s cannot be accessed!\n", argv[1]);
        if (goForIt) {
            processFileData(f, filesize);
            fclose(f);
        }
    return 0;
}

// We will write our functions (see prototypes above) here:
void processFileData(FILE *f, unsigned long filesize) {
    void *fileData;
    char *fileType;
    int *size1, *size2;
    fileData = (void *)malloc(filesize);  // malloc will return void pointer as default
    fread(fileData, filesize, 1, f);
    fileType = (char *)fileData;
    if (*fileType == 'C' && *(fileType + 1) == 'H') {  // test whether this first 2 bytes are CH as 'char'
        processString(fileData + 2);
    } else if (*fileType == 'I' && *(fileType + 1) == 'N') {  // test whether it's integer
        processIntegers(fileData + 2);
    // } 
    // else if (*fileType == 'F' && *(fileType + 1) == 'L') {  // test whether it's float
        // processFloats(fileData + 2);
    } else {
        printf("Unknown File Format!\n");
    }

    free(fileData);
}

void processString(void *data) {  // might be a int
    int i;
    int *length = (int *)data;
    char *message = (char *)malloc(*length + 1);  // pass int to string, need a null terminator
    char *c1, *c2 = message;
    for (i = 0, c1 = (char *)(data + 4 + *length - 1); i < *length; i++) { // 4 is skipping the rows and column data 
        *c2++ = *c1--;
    }
    *c2 = '\0';  // terminate the string
    printf("The secret message is: %s\n", message);

    free(message);
}

void processIntegers(void *data) {
    int *size1, *size2, sum;
    size1 = (int *)data;
    size2 = (int *)(data + sizeof(int));
    sumAndPrintIntArray((int *)(data + 2 * sizeof(int)), *size1, *size2, &sum);
    printf("Sum of elements = %d\n", sum);
}

void sumAndPrintIntArray(int *numArray, int rows, int columns, int *sum) {
    int row;
    *sum = 0;
    for (row = 0; row < rows; row++) {
        sumRowInt(&numArray, cols, sum);
    }
}

void sumRowInt(int **num, int cols, int *sum) {
    int col = 0;
    for (; col < cols; col++) {
        printf("%5d", **num);
        *sum += *(*num)++;
    }
    printf("\n");
}

void processFileData(void *data) {

}
  
unsigned long get_file_size(char *s) {
    long result = -1;
    struct stat file_info;
    if (stat(s, &file_info) > -1)
    {
        result = (unsigned long)(file_info.st_size);
    }
    return (unsigned long)result; 
}    