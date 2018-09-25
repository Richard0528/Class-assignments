#include <stdio.h>
#include <string.h>
void main() {
  char ch[] = "CH";
  char ints[] = "IN";
  int intSize[] = {3, 4};
  char floats[] = "FL";
  int floatSize[] = {4, 2};
  char message[] = "!yad yreve enitlavO ruoy knirD";
  int messageLength = strlen(message);
  int intData[3][4] = {{15, -5, 12, 13}, {10, 6, 20, 30}, {2, 4, 6, 8}};
  float floatData[4][2] = {{3.0, 4.25}, {3.50, 0.25}, {2.75, 1.50}, {4.25, 5.5}};
  FILE *f1 = fopen("SecretMessage.chr", "wb");
  FILE *f2 = fopen("Integers.num", "wb");
  FILE *f3 = fopen("FloatData.flt", "wb");
  printf("Message length is %d\n", messageLength);
  fwrite(ch, 2, 1, f1);
  fwrite(&messageLength, 1, sizeof(int), f1);
  fwrite(message, messageLength, sizeof(char), f1);
  fclose(f1);

  fwrite(ints, 2, 1, f2);
  fwrite(intSize, 2, sizeof(int), f2);
  fwrite(intData, 12, sizeof(int), f2);
  fclose(f2);
printf("Float Data Size: %d\n", sizeof(floatData));  
  fwrite(floats, 2, 1, f3);
  fwrite(floatSize, 2, sizeof(int), f3);
  fwrite(floatData, sizeof(floatData), 1, f3);
  fclose(f3);
}  