#include <stdio.h>


/*   This code, developed in class,
     will run forever.  Control-c to stop it.
     The user should enter integers separated by
     one or more blanks.   The program will print out
     the sum of the numbers on each line.

     At the end of class, the program still had one
     little bug.  It ignored the last number in the line
     unless a blank followed it.   That has been fixed
     as shown below.
*/

int main(void) {
    char c;
    int linesum = 0;
    int colsum = 0;
    while (1) {
        scanf("%c", &c);
        if( '0' <= c && c <= '9' ) {
            colsum *= 10;
            colsum += c - '0';
        } else if (c == '\n') {
            linesum += colsum; // fix from after class 
            printf("%d\n", linesum);
            linesum = 0;
            colsum = 0;
        } else if (c == ' ') {
            linesum += colsum;
            colsum = 0;
        }
    }    


    return 0;
}

