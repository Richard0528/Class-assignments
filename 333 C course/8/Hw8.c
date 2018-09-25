// TCSS 333 - assignment7
// Zhihao Yang

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void convert_result(float);
void processFile(FILE *);

int main(void) {
    FILE *infile = fopen("hw8in.txt", "r");
    processFile(infile);
    fclose(infile);
    return 1;
}

void processFile(FILE *infile) {
    // a is a whole number, b is a numerator, c is a denominator
    float a = 0, b = 0, c = 0;
    float result = 0;
    while (fscanf(infile, "%f %f %f", &a, &b, &c) != EOF) {
        if (a < 0) {
            result = a - b / c;
        } else {
            result = a + b / c;
        }
        printf("Floating point format of %20.15f:\n", result);
        convert_result(result);
    }
}

void convert_result(float result) {
    if (result < 0) {   // print out the sign bit
        printf("       1 ");
    } else {
        printf("       0 ");
    }
    char binary[30] = {0}, shift[8] = {0};
    int intpart = (int)fabs(result);
    int index = 0, exp = 0, i = 8, j = 0;
    float pow2 = 1, precision = 0.00001;

    while (intpart > (pow2 - precision)) {
        pow2 *= 2; 
        index++;
    }
    // get the exp from previous calculation
    exp = index - 1 + 127;
    while (i > 0) {
        if (exp % 2 == 0 || (fabs(result) - 0) < precision) {
            shift[i - 1] = '0';
        } else {
            shift[i - 1] = '1';
        }
        exp /= 2;
        i--;
    }
    // print out the 8 bits
    printf("%s ", shift);
    result = fabs(result);

    for (; j < index; j++) {
        pow2 /= 2;
        if (result >= pow2) {
            binary[j] = '1';
            result -= pow2;
        } else {
            binary[j] = '0';
        }
    }

    int count = 0;
    while (count < 25) {
        // keep dividing pow2 by 2
         pow2 /= 2;
        // if the difference is greater than or equal to zero add a '1'; otherwise, '0'
        if (result - pow2 >= 0.0) {
            binary[index] = '1';
            result -= pow2;
        } else {
            binary[index] = '0';
        }
        // when the array reach 23 bits, get out of the while loop
        if (index > 22) {
            count = 30;
        }
        
        count++;
        index++;
    }
    // omit the first char, increment the index by one
    memmove(binary, binary + 1, strlen(binary));  
    // print out the 23 bits
    printf("%s\n", binary);
}