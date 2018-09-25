// TCSS 333 - assign1
// Zhihao Yang

#include <stdio.h>
#include <string.h>
#include <math.h>
double convertBinary(char []);
double calculate(double, double, char);
char* convertDouble(double);
int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  char bi1[50] = {'\0'};
  char bi2[50] = {'\0'};
  char op;
  char binary[50];
  do {
    printf("Enter an expression using binary numbers or Q to quit: ");
    scanf(" %s", bi1);


    if (bi1[0] != 'q' && bi1[0] != 'Q') {
      scanf(" %c %s", &op, bi2);
      double result1 = convertBinary(bi1);
      double result2 = convertBinary(bi2);

      double ans = calculate(result1, result2, op);

      // printf("%f\n%f\n%f\n", result1, result2, ans);
      printf("%f %c %f = %f\n", result1, op, result2, ans);

      char* output = convertDouble(ans);

      printf("%s %c %s = %s\n", bi1, op, bi2, output);
    }
  } while (bi1[0] != 'q' && bi1[0] != 'Q');

}
// convert Binary into double
void convertBinary(char bi1[], char binary[]) {
  int intpart = 0;
  int index = 0;
  for (int i = 0; bi1[i] != '.'; i++) {
    intpart = intpart * 2 + (bi1[i] - '0');
    index = i + 2;
  }
  
  double decpart = 0;
  double coef = 0.5;
  for (int j = index; j < strlen(bi1); j++) {
    decpart += coef * (bi1[j] - '0');
    coef *= 0.5;
  }

  double result = intpart + decpart;

}
// doing calculation
double calculate(double result1, double result2, char op) {
  double ans = 0;
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
  while (ans > pow2) {
    pow2 *= 2;
    index++;
  }
  // printf("%d\n", index);
  for (int i = 0; i < index; i++) {
    pow2 /= 2;
    if (ans - pow2 >= 0.0) {
      result[i] = '1';
      ans -= pow2;
    } else {
      result[i] = '0';
    }
    // printf("%c\n", result[i]);
  }
  // integer part completed
  result[index] = '.';
  // printf("%f\n", ans);
  int court = 0;
  while (court < 20) {
    court++;
    index++;
    pow2 /= 2;
    if (ans - pow2 >= 0.0) {
      result[index] = '1';
      ans -= pow2;
    } else {
      result[index] = '0';
    }
    // printf("%.10lf\n", ans);
    if (ans == 0.0) {
      court = 20;
    }
  }

  char* output = result;
  return output;
}
