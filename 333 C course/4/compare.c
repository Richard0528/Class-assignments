/* compare.c tests our solution, or as close as I recall
   and also, the actual (or close to) solution.
*/
#include <stdio.h>
int scmp(char *, char *);
int scmp2(const char *s1, const char *s2);
void main() {
  printf("==  %d\n", scmp("ABC", "ABC"));
  printf("==  %d\n", scmp2("ABC", "ABC"));
  printf("<   %d\n", scmp("ABC", "ABCDAAAA"));
  printf("<   %d\n", scmp2("ABC", "ABCDAAAA"));
  printf("<   %d\n", scmp("ABCC", "ABCD"));
  printf("<   %d\n", scmp2("ABCC", "ABCD"));
  printf(">   %d\n", scmp("ABCE", "ABCD"));
  printf(">   %d\n", scmp2("ABCE", "ABCD"));
  printf(">   %d\n", scmp("ABCD", "ABC"));
  printf(">   %d\n", scmp2("ABCD", "ABC"));
  printf(">   %d\n", scmp("ABCD", "ABCC"));
  printf(">   %d\n", scmp2("ABCD", "ABCC"));
  printf("<   %d\n", scmp("ABCD", "ABCE"));
  printf("<  %d\n", scmp2("ABCD", "ABCE"));
  printf("==  %d\n", scmp("ABCD", "ABCD"));
  printf("==  %d\n", scmp2("ABCD", "ABCD"));
}
// similar to our solution:
int scmp(char *s1, char *s2) {
  while (*s1 == *s2 && *s1) {       /*or *s1 != '\0'*/
   s1++;
   s2++;
  }
  return *s1 - *s2;
}
// similar to actual strcmp (note: multiple return OK for equals/cmp):
int scmp2(const char *s1, const char *s2) {
  for ( ; *s1 == *s2; s1++, s2++) 
    if (*s1 == '\0')
      return 0;
  return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}