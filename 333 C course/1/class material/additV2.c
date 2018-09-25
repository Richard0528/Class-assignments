#include <stdio.h>

/* This is a different version of the 
   "add all numbers in each line" program.
   It may be more readable.
*/

int main(void) {
    char c;
    int linesum = 0;
    int colsum;

    scanf("%c", &c);

    while (1) {
 
        // any blanks?
        while (c == ' ') {
            scanf("%c", &c);
        }

        // any digits?
        colsum = 0; 
        while ('0' <= c && c <= '9') {
            colsum *= 10;
            colsum += c-'0';
            scanf("%c", &c);
        }
        linesum += colsum; 

        // end of line?
        if (c == '\n') {
            printf("%d\n", linesum);
            linesum = 0;
            scanf("%c", &c);
        }
    }    

    return 0;
}

