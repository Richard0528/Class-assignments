/*************************************************** 
   SumLines.c

   Author:  David Schuessler

   Demonstration of reading one character (byte) at
   a time from the input stream and converting all
   contiguous digits into integers.

   The following program allows the user to input
   multiple integers on a line (each separated by
   space(s)), sums the results, and repeats until
   CTRL+C is entered to terminate the program.
*/

/*************************************************** 
   Preprocessor #include directives go here.
   This program requires I/O:
*/
#include <stdio.h>

/***************************************************
   Preprocessor #define directives go here.
   None in this example.
*/

/***************************************************
   Type definitions go here.
   None in this example.
*/

/***************************************************
   Declarations of external variables go here.
   None in this example.
*/

/***************************************************
   Prototypes for functions (other than main) go here.
*/

void letsSumIt(void);

int main(void) {
    letsSumIt();
    return 0;
}

/***************************************************
   letsSumIt

   Sums multiple integers entered through stdin one
   character at a time.
   
*/
void letsSumIt(void) {
    char c;
    int totalSum = 0;
    int digitSum;

    printf("Enter integers separated by spaces on each line and hit enter for the total\n");
    printf("CTRL+c will terminate the process\n");
    scanf("%c", &c);

    while (1) {
 
        // consume all blanks before each number:
        while (c == ' ') {
            scanf("%c", &c);
        }

        // consume contiguous digits and 
        // generate the integer:
        digitSum = 0; 
        while ('0' <= c && c <= '9') {
            digitSum *= 10;
            digitSum += c-'0';
            scanf("%c", &c);
        }
        totalSum += digitSum; 

        // end of line?
        if (c == '\n') {
            printf("%d\n", totalSum);
            totalSum = 0;
            scanf("%c", &c);
        }

    }   // end of while (1)
   
}  // end of letsDoIt

