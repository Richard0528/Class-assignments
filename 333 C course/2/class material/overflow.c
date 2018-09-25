/*
  Specifiers and Modifiers
  Specifier:
    d   = decimal int
    o   = octal
    x,X = hexadecimal
    c   = character
  Modifier:
    h   = short int
    l   = long int or unsigned long
*/
#include <stdio.h>
void main(void) {
  char ch;
  short int a = 077766;  // 32758 in Decimal
  short int b = 0x7176;  // 29046 in Decimal
  short int c = a + b;
  printf("Size of short int = %d\n", sizeof(short));
  printf("a(%hd) + a(%hd) = %hd\n", a, b, c);
  scanf("%c", &ch);
  printf("a(%ho) + a(%ho) = %ho\n", a, b, c);
  scanf("%c", &ch);
  printf("a(%hX) + a(%hX) = %hX\n", a, b, c);
  scanf("%c", &ch);
  printf("a(%hd) + a(%hd) = %hU\n", a, b, c);
  scanf("%c", &ch);

}