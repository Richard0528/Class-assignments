// TCSS 333 - assignment1
// Zhihao Yang

#include <stdio.h>
#include <string.h>
#include <math.h>
double convertBinary(char []);
double calculate(double, double, char);
char* convertDouble(double);
int main() {
  setvbuf(stdout, NULL, _IONBF, 0); // just in case you use eclipse
  char bi1[50] = {'\0'};
  char bi2[50] = {'\0'};
  char op;
  do {
    printf("Enter an expression using binary numbers or Q to quit: ");
    scanf(" %s", bi1);

    if (bi1[0] != 'q' && bi1[0] != 'Q') {
      scanf(" %c %s", &op, bi2);
      double result1 = convertBinary(bi1);
      double result2 = convertBinary(bi2);

      double ans = calculate(result1, result2, op);

      // extra credit part
      printf("%.10lf %c %.10lf = %.10lf\n", result1, op, result2, ans);

      char* output = convertDouble(ans);

      printf("%s %c %s = %s\n", bi1, op, bi2, output);
    }
  } while (bi1[0] != 'q' && bi1[0] != 'Q');

}
// convert Binary into double
double convertBinary(char bi1[]) {
  int intpart = 0;
  int index = 0;
  // loop throught the array up to the binary point
  for (int i = 0; bi1[i] != '.'; i++) {
    // follow the algorithm from the pdf,
    // start with 0, double the value, add the next bit
    intpart = intpart * 2 + (bi1[i] - '0');
    // update index for decimal part
    index = i + 2;
  }
  
  double decpart = 0;
  double coef = 0.5;
  // start from the bit right after the binary point, loop to the end
  for (int j = index; j < strlen(bi1); j++) {
    // start with 0.5, if the next bit is a 1, add in the current pow2; 
    // divide the current pow2 by 2
    decpart += coef * (bi1[j] - '0');
    coef *= 0.5;
  }

  // add them up
  double result = intpart + decpart;

  return result;
}

// doing calculation
double calculate(double result1, double result2, char op) {
  double ans = 0;
  // different operator represent different calculation
  if (op == '+') {
    ans = result1 + result2;
  } else if (op == '-') {
    ans = result1 - result2;
  } else if (op == '*') {
    ans = result1 * result2;
  } else if (op == '/') {
    ans = result1 / result2;
  } 

  return ans;
}

// convert double into Binary
char* convertDouble(double ans) {
  double pow2 = 1;
  char result[100] = {'\0'};
  int index = 0;

  // get a pow2 that is slightly greater than the number
  while (ans > pow2) {
    pow2 *= 2;
    index++;
  }

  // keep subtracting differnt pow2 from the number;
  // if the difference is greater than or equal to zero add a '1'
  // for (int i = 0; i < index; i++) {
  //   pow2 /= 2;
  //   if (ans - pow2 >= 0.0) {
  //     result[i] = '1';
  //     ans -= pow2;
  //   } else {
  //     result[i] = '0';
  //   }
    
  // }
  // // integer part completed
  // // add binary point
  // result[index] = '.';
  
  // we need to fill up to 20 fractional digits,
  // int court = 0;
  // while (court < 20) {
  //   court++;
  //   index++;
  //   // keep dividing pow2 by 2
  //   pow2 /= 2;

  //   // if there is no fraction part, terminate the while loop immediately
  //   if (ans == 0.0) {
  //     court = 20;
  //   }

  //   // if the difference is greater than or equal to zero add a '1'; otherwise, '0'
  //   if (ans - pow2 >= 0.0) {
  //     result[index] = '1';
  //     ans -= pow2;
  //   } else {
  //     result[index] = '0';
  //   }
    
  // }

  char* output = result;
  return output;
}







