//  Filling an array of struct by passing its address to a function.

#include <stdio.h>
struct weather_tag {
	char city[20];
	int temp;
};

typedef struct weather_tag Weather;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    FILE *infile;
    int i;

    Weather arr[10];
    int arrCount = 0;
    infile = fopen("cities.txt", "r");

    // How do you know if the file open was successful?
    // Here's how you can check.
    if (infile == NULL) {
    	printf("File did not open.");
    	return 1;
    }

    // It's easy to read a file to the end.
    // fscanf returns a value that indicates whether
    // it ran off the end of the file.
    arrCount = getCityData(infile, arr);
    // print out all the data from the array
    for (i = 0; i < arrCount; i++) {
        printf("%s %d\n", arr[i].city, arr[i].temp);
    }

    return 0;
}
int getCityData(FILE *in, Weather *p) {
    int count = 0;
    while (fscanf(in, "%s %d", p->city, &p->temp) != EOF) {
        p++;
        count++;
    }
    return count;
}