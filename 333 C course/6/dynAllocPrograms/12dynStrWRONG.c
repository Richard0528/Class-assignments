#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* infile = fopen("strings.txt","r");
    char line[100];
    int numStrings;
    fgets(line,100,infile);
    sscanf(line, "%d", &numStrings);
    
    char *strings[numStrings];

/***************************************/
/*     THIS   CODE   DOESN'T WORK      */
/***************************************/

    int i;
    for (i = 0; i < numStrings; i++) {
         fgets(line,100,infile);
         strings[i] = line;       // ALWAYS the address of line
         printf("%s", strings[i] );
    }

    // All pointers of strings reference the same address:
    for (i = 0; i < numStrings; i++) {
         printf("%s", strings[i] );
    }

    fclose(infile);
 
}
