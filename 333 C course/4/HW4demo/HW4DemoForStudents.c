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
  
unsigned long get_file_size(char *s) {
  long result = -1;
  struct stat file_info;
  if (stat(s, &file_info) > -1)
  {
    result = (unsigned long)(file_info.st_size);
  }
  return (unsigned long)result; 
}    