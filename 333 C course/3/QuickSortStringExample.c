/* Demonstrates scanf for reading csv files.
   Leading space in the format string skips any
   whitespace in the input stream, including 
   carriage returns, line feeds, form feeds, etc.

   Assignment supression %* followed by a conversion
   character (e.g. %*d or %*c) simply skips the input
   field. E.g. input of: Hey 10 You!  Could read just
   the 2 strings (Hey & You!) with:
   scanf("%s%*d%s", s1, s2);  assuming s1 & s2 are 
   pointers to character arrays of at least 5 elements
   (needing to reserve one character for '\0').

   To ignore characters in the input stream, add that
   character between the specifiers...  However, if the
   character to be ignored happens to immediately follow
   a string (as in the commas separating fields of csv
   input), you will then need to use the super string
   specifier to stop scanning at the excluded specific 
   characters:  %[^,] and immediately follow this by the
   excluded character in order to skip past it:
   scanf("%[^,],%*d", s1);  This reads a string up to a
   comma, skips over the comma, and consumes and tosses
   away an integer.

   If the above is a repeated process, line feeds, carriage
   returns, and the like still remain in the input.  Keeping
   in mind these special characters are considered whitespace,
   they can be skipped over in subsequent reads by using a
   space at the start of the format string:  " %[^,],%*d"
   The following demonstrates these issues by reading a file
   containing a <string>,<integer> format on each line
   (or:  Harry,78334):
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_NAMES 35
#define NAME_LENGTH 13

// Prototypes:
void quickStrSort(char *left, char *right, int length);
void displayNames(char *names, int nameCount, int nameLength);
int getNames(FILE *f, char *n, int nLength, int maxN);

void main(void) {
  volatile int i;
  int nameCount = 0, readOK = 1;
  char names[MAX_NAMES][NAME_LENGTH] = {'\0'};

  FILE *f = fopen("someNames.csv", "r");
  nameCount = getNames(f, (char *)names, NAME_LENGTH, MAX_NAMES);
  fclose(f); 

  // Traverse & print the list of names using a char pointer:
  displayNames((char *)names, nameCount, NAME_LENGTH);

  quickStrSort((char *)names, (char *)names + NAME_LENGTH * (nameCount - 1),
               NAME_LENGTH);

  // Traverse & print the sorted list:
  displayNames((char *)names, nameCount, NAME_LENGTH);
 }

/***************************************************************************************
  getNames

  Reads from the given input file, names stored in a csv format:
  (name,####).

  Receives:
    -Open FILE reference
    -Pointer to the names array
    -Maximum length of all names
    -Maximum number of names

  Returns:
    -the number of names read
****************************************************************************************/
int getNames(FILE *f, char *n, int nLength, int maxN) {
  int i;
  // Read in the names from a csv file:
  for (i = 0; i < maxN && fscanf(f, " %[^,],%*d", n + i * nLength) != EOF; i++);
  return i;
}
 
/***************************************************************************************
  displayName

  Displays a list of names/words/strings pointed to by names.
  Receives:
    -pointer to the list
    -the number of names in the list
    -the length of each name
****************************************************************************************/
void displayNames(char *names, int nameCount, int nameLength) {
  char *nam;
  int i;
  for (i = 0, nam = (char *)names; 
       i < nameCount; i++, nam += nameLength) {
    printf("%2d %-13s%d\n", i + 1, nam, strlen(nam));
  }
  printf("\n\n"); 
} 

/***************************************************************************************
  quicksort

  Sorts (in this case) a list of strings, length of 13 each, which
  begin at the memory location that left points to.
  receives:
    -a pointer to the left most element to be sorted
    -a pointer to the right most element to be sorted
    -the size of each element being sorted
****************************************************************************************/
  void quickStrSort(char *left, char *right, int length){
    int k;
    char *i = left;
    char *j = right;
    char *swap[NAME_LENGTH] = {'\0'};
    char test[NAME_LENGTH];
    char *s1 = i, *s2 = j;
    while (s1 < s2) {   // find midpoint for the test value
      s1 = s1 + length;
      s2 = s2 - length;
    }
    strncpy(test, s2, length - 1);
    do {
      // move i to the right until we find a value > the midpoint value
      // or i == right
      while (strcmp(i, test) < 0) i += length;
      // move j to the left until we find a value < the midpoint value
      // or j == left
      while (strcmp(j, test) > 0) j -= length;

      // Swap the two values (here we are demonstrating the full
      // details of swaping two strings. Normally, use of the
      // string.h function strcpy or strncpy would be preferred
      // to eliminate the complexity we see here):
      if (i <= j){
        for (s1 = (char *)swap, s2 = i; *s2 != '\0'; s1++, s2++)
          *s1 = *s2;
        *s1 = *s2;  // Also copy the '\0'
        for (s1 = i, s2 = j; *s2 != '\0'; s1++, s2++)
          *s1 = *s2;
        *s1 = *s2;
        for (s1 = j, s2 = (char *)swap; *s2 != '\0'; s1++, s2++)
          *s1 = *s2;
        *s1 = *s2;
        i += length;
        j -= length;
      }
    } while (i <= j);
    if (left < j) {
      quickStrSort(left, j, length);
    }
    if (i < right) {
      quickStrSort(i, right, length);
    }
  }
