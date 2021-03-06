/* commandLineArgs2.c
   To set command line arguments in Eclipse, set up a c project,
   type your code, save all, build all, Run your program, open 
   the Run menu, click run configurations, Double click C/C++
   Applications..., click the Arguments tab, type in your arguments
   each separated by a space, click Apply, click Run.  From now on
   you should be able to just run your program and the arguments
   you entered will be saved and used.
*/

#include <stdio.h>
void displayParams(int, char **);
int main(int argc, char **argv) {
  displayParams(argc, argv);
  return 0;
}
void displayParams(int total, char **params) {
  int i = total;
   do { 
    printf("Argumment %d: %c\n", total - i, *params++);
    } while (--i);
} 