#include <stdio.h>
#include <stdlib.h>

void whatever(char *names);

int main() {

// char result[10][7] = {

//     {'1','X','2','X','2','1','1'},
//     {'X','1','1','2','2','1','1'},
//     {'X','1','1','2','2','1','1'},
//     {'1','X','2','X','2','2','2'},
//     {'1','X','1','X','1','X','2'},
//     {'1','X','2','X','2','1','1'},
//     {'1','X','2','2','1','X','1'},
//     {'1','X','2','X','2','1','X'},
//     {'1','1','1','X','2','2','1'},
//     {'1','X','2','X','2','1','1'}

// };

// // char dest[10][7] = {'\0'};
// // strcpy(dest, result);

// char *str = (char *) malloc(15);

// int row = sizeof(str) / sizeof(str[0]);

// printf("Number of rows: %d\n", row);
// printf("%s", dest);


    // int rank, year;
    // char temp[20]; 
    // char name[20] = "Willie 74 1920";
    // char namtmp[13];

    // strcpy(temp, name);
    // sscanf(temp, "%s %d %d", namtmp, &rank, &year);

    // printf("%s %d\n", namtmp, rank);

	char *names = (char *)malloc(20);
	whatever((char *)names);

	free(names);
}

void whatever(char *names) {
	names = realloc(names, 30);
	
}
