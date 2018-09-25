/*
   Dynamically allocate "pointers" to strings.
   BTW: fgets(stream, size, arrayOfChar)  reads from the stream at most
   size - 1 (or up to newline char) bytes into arrayOfChar and adds '\0'
   to the end.  If newline is encountered, it is added to the array followed
   by '\0'.

   Also, sscanf works just like scanf but, parses its tokens from a given
   string as its first argument (the given string, of course, is terminated
   with '\0').

   Here we dynamically allocate a given number (read from the start of the
   input file) of pointers to strings and access each of these pointers
   using indexing as if these pointers were declared as char *strings[12] or,
   using c99 variable arrays, as char *string[numStrings];
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* infile = fopen("strings.txt", "r");
    char line[100];
    char **strings;
    int numStrings, i;
    fgets(line, 100, infile);
    sscanf(line, "%d", &numStrings);

    // Allocate enough memory to hold numStrings pointers to char
    strings = (char **) malloc(numStrings * sizeof(char *)); //cast doesn't matter.

// C99 can use the statement below (char *strings[numStrings];) but,
// it should replace the line above and remove "char **strings;" above.
//    char *strings[numStrings];

    for (i = 0; i < numStrings; i++) {
         fgets(line, 100, infile);
         strings[i] = malloc(strlen(line) + 1); // Works C99 or earlier!
         strcpy(strings[i], line);
         printf("%s", strings[i] );
    }
    printf("\n");

    for (i = 0; i < numStrings; i++) {
         printf("%s", strings[i] );
    }
    fclose(infile);

    // free all allocated memory:
    for (i = 0; i < numStrings; i++) {
         free(strings[i]);
         strings[i] = NULL;
    }
    free(strings);
    strings = NULL;
}
