/*
   MergeSortStringExample.c

   Course:  TCSS 333 C for System Programming
   Author:  David Schuessler

   Demonstrates Mergesort of strings and using
   scanf for reading csv files.
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
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAMES 35
#define NAME_LENGTH 13

// Prototypes:
void mergeStrSort(char *, int, int);
void merge(char *, char *, char *, int , int , int );
void mergeStrSort2(char a[][NAME_LENGTH], int nameCount, int nameLen);
void merge2(char a[][NAME_LENGTH], char left[][NAME_LENGTH], char right[][NAME_LENGTH], 
           int aLen, int leftLen, int rightLen, int nameLen);
void displayNames(char *, int, int);
int getNames(FILE *, char *, int, int);

void main(void) {
  volatile int i;
  int nameCount = 0, readOK = 1;
  char names[MAX_NAMES][NAME_LENGTH] = {'\0'};

  FILE *f = fopen("someNames.csv", "r");
  nameCount = getNames(f, (char *)names, NAME_LENGTH, MAX_NAMES);
  fclose(f); 

  // Traverse & print the list of names using a char pointer:
  displayNames((char *)names, nameCount, NAME_LENGTH);

  mergeStrSort((char *)names, nameCount, NAME_LENGTH);

  // Traverse & print the sorted list:
  displayNames((char *)names, nameCount, NAME_LENGTH);

  // Now do this with all arrays:
  printf("Now do Mergesort with only arrays:\n");
  scanf("%*c");
  f = fopen("someNames.csv", "r");
  nameCount = getNames(f, (char *)names, NAME_LENGTH, MAX_NAMES);
  fclose(f); 

  // Traverse & print the list of names using a char pointer:
  displayNames((char *)names, nameCount, NAME_LENGTH);

  mergeStrSort2(names, nameCount, NAME_LENGTH);

  // Traverse & print the sorted list:
  displayNames((char *)names, nameCount, NAME_LENGTH);
 }


/***************************************************************************************
  mergeStrSort

  Sorts (in this case) a list of strings, length of 13 each, which
  begin at the memory location to which left points.
  receives:
    -a pointer to the left most element to be sorted
    -the number of strings to sort
    -the size of each element being sorted
****************************************************************************************/
void mergeStrSort(char *a, int nameCount, int nameLen) {
    char *left, *right, *scan, *s;
    int leftCount = nameCount / 2;
    int rightCount =  nameCount - leftCount;
    int i, leftBytes = leftCount * nameLen;
    if (nameCount >= 2) {
        // split array into two halves and set aside memory
        // to move strings into it from the first half of a
        left  = (char *)malloc(leftCount * nameLen);
        for (i = 0, s = left, scan = a; i < leftBytes; i++)
          *s++ = *scan++;

        //  Simply move right to the lower half of a
        right = a + leftCount * nameLen;

        // sort the two halves
        mergeStrSort(left, leftCount, nameLen);
        mergeStrSort(right, rightCount, nameLen);

        // merge the sorted halves into a sorted whole
        merge(a, left, right, leftCount, rightCount, nameLen);
        free(left);
    }
}

/***************************************************************************************
  merge

  Merges two sorted lists or arrays (second and third parameters (left and right) as 
  pointers to strings) into the list to which the first parameter (a) points. The right
  pointer actually points to the lower end of the original list to which pointer a points
  to conserve execution time
  and space.  The parameters:
    -a pointer to the resulting list after merging
    -a pointer to left list (already sorted)
    -a pointer to the right list (already sorted) and the lower end of the resulting list
    -the number of strings in the left list
    -the number of strings in the right list
    -the size of each element being sorted
****************************************************************************************/
void merge(char *a, char *left, char *right, 
           int leftLen, int rightLen, int nameLen) {

    char *aEnd = right + nameLen * rightLen;
    char *leftEnd = left + nameLen * leftLen;
    while (/*a < aEnd && */right < aEnd && left < leftEnd) {
        if (strcmp(left, right) <= 0) {
            strcpy(a, left);    // take from left
            left += nameLen;
        } else {
            strcpy(a, right);   // take from right
            right += nameLen;
        }
        a += nameLen;
    }
    while (left < leftEnd /*&& a < aEnd*/) {
      strcpy(a, left);
      left += nameLen;
      a += nameLen;
    }
}

/***************************************************************************************
  mergeStrSort2

  Sorts an array of strings, length of 13 each.
  receives:
    -an array to be sorted
    -the number of strings to sort
    -the size of each element being sorted
****************************************************************************************/
void mergeStrSort2(char a[][NAME_LENGTH], int nameCount, int nameLen) {
  int i, i1, i2;
  // create 2 arrays to contain the data in a
  char left[nameCount / 2][nameLen];
  char right[nameCount / 2 + 1][nameLen];
  int leftCount = nameCount / 2;
  int rightCount =  nameCount - leftCount;
  if (nameCount >= 2) {
    // Put first half of a into left:
    for (i1 = 0; i1 < leftCount; i1++)
      strcpy(left[i1], a[i1]);
    // Put the later half of a into right:
    for (i2 = 0; i2 < rightCount; i2++, i1++)
      strcpy(right[i2], a[i1]);
    // sort the two halves
    mergeStrSort2(left, leftCount, nameLen);
    mergeStrSort2(right, rightCount, nameLen);

    // merge the sorted halves into a sorted whole
    merge2(a, left, right, nameCount, leftCount, rightCount, nameLen);
  }
}

/***************************************************************************************
  merge2

  Merges two sorted arrays (second and third parameters (left and right)) into the array
  to which is the first parameter. 
  The parameters:
    -an array that will contain the results of the merging
    -the left array to merge (already sorted)
    -the right array to merge (already sorted)
    -the number of strings in the left array
    -the number of strings in the right array
    -the size of each element being sorted
****************************************************************************************/
void merge2(char a[][NAME_LENGTH], char left[][NAME_LENGTH], char right[][NAME_LENGTH], 
           int aLen, int leftLen, int rightLen, int nameLen) {
  int i;
  int i1 = 0;
  int i2 = 0;
  for (i = 0; i < aLen; i++) {
    if (i2 >= rightLen || 
      (i1 < leftLen && strcmp(left[i1], right[i2]) <= 0)) {
        strcpy(a[i], left[i1]);    // take from left
        i1++;
    } else {
        strcpy(a[i], right[i2]);   // take from right
        i2++;
    }
  }
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
