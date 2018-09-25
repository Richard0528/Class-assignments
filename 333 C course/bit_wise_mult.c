#include <stdio.h>
#define NEGATIVE 0x80000000

int multiply(register int, register int);
void main(void) {
  printf("%d \n", multiply(5, 7));
}
int multiply(register int num1, register int num2) {
  int negate = 0x00000000;  
  register int result = 0;

  // perform two's complement on num1 if num1 is negative:
  if (num1 & NEGATIVE) {  
    num1 = ~num1;
    num1++;
    negate ^= NEGATIVE;  
  }

  // perform two's complement on num2 if num2 is negative:
  if (num2 & NEGATIVE) {  
    num2 = ~num2;
    num2++;
    negate ^= NEGATIVE;  
  }

  
  // 
  if (num2 > num1) {
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;
  }

  while (num2) {  // 
    if (num2 & 1) {
      result += num1;
      num2--;
    } else {
      num1 <<= 1;
      num2 >>= 1;
    }
  }

  if (negate & NEGATIVE) {  
    result  = ~result;                 
    result++;
  }
  return result;
}
