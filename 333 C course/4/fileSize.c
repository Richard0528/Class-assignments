/* fileSize.c
   Useful when you need to read the entire contents of a file
   with a single fread.  You can check how much memory is 
   needed, allocated memory of that amount to a pointer to char,
   and send it to fread.
   
   Obtains the size in bytes of a file via a struct containing
   information about the file and in particular, the file size.
   The field of struct stat that contains the file size is
   actually an unsigned long.  Keep this in mind when you are
   testing for errors.  You my need to manipulate this data
   with casts in order to get the desired result.
*/
#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>  // On some systems you may need this.
#include <sys/stat.h>     // Contains definition of struct & 
                          // function stat
unsigned long get_file_size(char *);
int main(int argc, char **argv) {
  unsigned long size;
  char *name = "in1.bmp";
  int goForIt = 0;
  argv++;
  if ((goForIt = (long)(size = get_file_size(*argv)) >= 0)) {
    printf("%d\n", goForIt);
    printf("%s is %ld bytes in length!\n", *argv, size);
  }
  else {
    printf("%d\n", goForIt);
    printf("ERROR! %s cannot be accessed!\n", name);
  }

  return 0;
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