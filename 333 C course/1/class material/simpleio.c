/*
 * simpleio.c
 *
 *  Created on: Sep 24, 2014
 *      Author: jhmayer
 */

#include <stdio.h>

int main(int argc, char* argv[]) {

	char ch;
	float fl;
	double db;
	int i;
	char string[50];

	// interactive programs run inside eclipse
	// seem to require this line
	setvbuf (stdout, NULL, _IONBF, 0);

	printf("Enter a char: ");
	scanf("%c", &ch);

	printf("Enter an int: ");
	scanf("%d", &i);

	printf("Enter a float: ");
	scanf("%f", &fl);

	printf("Enter a double: ");
	scanf("%lf", &db);

	printf("Enter a string: ");
	scanf("%s", string);

	printf("char = %c\n",ch);
	printf("int = %d\n",i);
	printf("float = %f\n",fl);
	printf("double = %lf\n",db);
	printf("string = %s\n",string);

	return 0;

}

