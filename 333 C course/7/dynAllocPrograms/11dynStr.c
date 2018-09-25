/* 11dynStr.c
 * Demonstrates an array of pointers (on the stack) each of which has memory
 * allocated (on the Heap- strlen(line) number of bytes) to stored a line of
 * input data.
 */
#include <stdio.h>

#include <stdlib.h>

#include <string.h>


int main() {

    FILE* infile = fopen("strings.txt", "r");

    char line[100];
    int numStrings;

    fgets(line, 100, infile);

    sscanf(line, "%d", &numStrings);

    char *strings[numStrings];
    char **scan, **endPoint;
    int i;


    // fill the array of strings with lines from the file:
    for (i = 0; i < numStrings; i++) {

        fgets(line, 100, infile);
        strings[i] = malloc(strlen(line) + 1);
        strcpy(strings[i], line);
    }


    // print out each element's value using indexing:
    for (i = 0; i < numStrings; i++) {

        printf("%s", strings[i] );

    } 

    printf("\n");
    // Alternatively, we could access each element and move
    // from one to the next with a pointer: **scan
    for (i = 0, scan = strings, endPoint = strings + numStrings;
         scan < endPoint; i++, scan++)
        printf("%s\tStack:  %p, %p  &  Heap:  %p, %p\n\n", 
               *scan, &strings[i], scan, strings[i], *scan);
        // &strings[i] is address of the pointer, scan is the same-On the Stack!
        // strings[i] is address of a string of char, *scan is same-On the Heap!

    // Simply show starting/ending addresses and the distance thereof:
    printf("strings = %p, endPoint = %p\nstrings = %d, endPoint = %d\n"
           "numStrings = %d\nTotal Pointers = %d\n"
           "Actual distance of endPoint - strings = %d\n", 
           strings, endPoint, strings, endPoint, 
           numStrings, endPoint - strings, 
           (long)((long)endPoint - (long)strings));

    // Best we clean up after ourselves:
    fclose(infile);
    for (i = 0, scan = strings; i < numStrings; i++, scan++) {
        free(strings[i]);
        strings[i] = NULL;
    }
}