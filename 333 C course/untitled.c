
#include <stdio.h>

void swap(int**, int**);

int main(void) {
	int i = 5, j = 13;
	int* p1 = &i;
	int* p2 = &j;

	printf("p1: %p\n", p1);
	// printf("&p1: %p\n", &p1);
	// printf("*p1: %d\n", *p1);

	printf("p2: %p\n", p2);
	// printf("&p2: %p\n", &p2);
	// printf("*p2: %d\n", *p2);	

	swap(&p1, &p2);

	printf("%d\n", *p1);
	printf("p1: %p\n", p1);
	printf("%d\n", *p2);
	printf("p2: %p\n", p2);

	// int a = 5;
	// int *b = &a;
	// int **c = &b;

	// printf("%p %p %p", &a, b, *c);

	return 0;
}

void swap(int **a, int **b) {

	printf("a :%p\n", a);
	int *i = *a;
	printf("i :%p\n", i);
	*a = *b;
	printf("a :%p\n", a);
	*b = i;

	// int g = 8;
	// int *h = &g;
	// a = h;
}

