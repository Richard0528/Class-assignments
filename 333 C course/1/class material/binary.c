#include <math.h>
#include <stdio.h>
void clearBinary(char [], int);
void getBinary(int, char[], int);
int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  int num = -1;
  char binary[33];
  int i;
  clearBinary(binary, 33);
  do {
    printf("Enter an integer, 0 to end: ");
    scanf(" %d", &num);
    if (num) {
      getBinary(num, binary, sizeof(binary) / sizeof(binary[0]) - 1);
      printf("%5d in binary = %s\n", num, binary);
      clearBinary(binary, 33);
    }
  } while (num);

  // What's the binary value of ASCII 'B'
  getBinary((int)'B', binary, (int)(log('B') / log(2)) + 1);
  printf("%5d in binary = %s\n", (int)'B', binary);
  printf("Enter a string: ");
  scanf(" %s", binary);
  printf("%s\n", binary);
}
void getBinary(int n, char binary[], int size) {
  int i = size - 1;
  while (n) {
    binary[i] = n % 2 ? '1' : '0';
    n /= 2;
    i--;
  }
}
void clearBinary(char s[], int size) {
  int i = 0;
  for (; i < size - 1; i++)
    s[i] = ' ';
  s[size - 1] = '\0';
}
