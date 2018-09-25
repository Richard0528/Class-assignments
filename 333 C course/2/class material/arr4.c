#include <stdio.h>



int main(void) {


    int rows, cols;

    printf("How many rows? ");

    scanf("%d", &rows);

    printf("How many cols? ");

    scanf("%d", &cols);


    int arr2D[rows][cols];

    int r, c;

    for (r = 0; r < rows; r++) {

       for (c = 0; c < cols; c++) {

           arr2D[r][c] = r * 100 + c;

       }

    }


    for (r = 0; r < rows; r++) {

       for (c = 0; c < cols; c++) {

           printf("%d ", arr2D[r][c]);

       }

       printf("\n");

    }

    return 0;


}
