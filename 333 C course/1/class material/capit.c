#include <stdio.h>

int main(void) {
    char c;

    while (1) {
        scanf("%c", &c);
        if (  c <= 'z' && c >= 'a' ) {
             c = 'A' + (c -'a');
        }
        printf("%c", c);
    }    


    return 0;
}

