// TCSS 333 - assignment3
// Zhihao Yang

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAMES 100
#define NAME_LENGTH 20
#define RANK_LENGTH 5
#define MAX 1000

void getNames(FILE *f, char *n, int nLength, int maxN);
void displayNames(char *names, int nameCount, int nameLength, int year);
void quickStrSort(char *left, char *right, int length);
void createFile(char *names, char *allNames, int maxName);

int main(void) {

    int year = 1920;
    // char names[MAX_NAMES][NAME_LENGTH] = {'\0'};
    // char rank[MAX_NAMES][RANK_LENGTH] = {'\0'};
    char *names = (char *)malloc(MAX_NAMES * NAME_LENGTH * sizeof(char));

    char *allNames[MAX][NAME_LENGTH] = {'\0'};

    // for 1920
    FILE *infile1 = fopen("yob1920.txt", "r");
	// FILE *outfile1 = fopen("summary.csv", "w");
    // fprintf(outfile1, "");

    getNames(infile1, (char *)names, NAME_LENGTH, MAX_NAMES);

    // printf("%d\n", (int) sizeof(names)/ (int) sizeof(names[0]));

    // displayNames((char *)names, MAX_NAMES, NAME_LENGTH, year);

    // quickStrSort((char *)names, (char *)names + NAME_LENGTH * (MAX_NAMES - 1), NAME_LENGTH);

    // displayNames((char *)names, MAX_NAMES, NAME_LENGTH);
    // char *dest1[100][20];
    // char *nam;
    // char *des;
    // int i;
    // for (i = 0, des = (char *)dest1, nam = (char *)names; i < 100; i++, des+= NAME_LENGTH, nam += NAME_LENGTH) {
    //     strcpy(des, nam);
    //     // printf("%-20s\n", nam);
    // }
    // printf("\n\n");


    // char *nam3;
    // int j;
    // for (j = 0, nam3 = (char *)dest1; j < 100; j++, nam3 += NAME_LENGTH) {
    //     printf("%-20s\n", nam3);
    // }
    // printf("\n\n");



    fclose(infile1); 
    // done with 1920 year

    char *allNam;
    allNam = (char *)allNames;
    int maxName = MAX_NAMES;
    int a;
    for (a = 1920; a < 2020; a += 10) {
        // allNam = allNam + ((a-1920) / 10) * MAX_NAMES * NAME_LENGTH;
        char fp[15];
        sprintf(fp, "yob%d.txt", a);
        FILE *infile2 = fopen(fp, "r");

        char nameTmp[MAX_NAMES][NAME_LENGTH] = {'\0'};
        // char rankTmp[MAX_NAMES][RANK_LENGTH] = {'\0'};

        getNames(infile2, (char *)nameTmp, NAME_LENGTH, MAX_NAMES);

        // check if there are any names not in the main name list.
        // int len = sizeof(names) / sizeof(names[0]);
        char *nam1;
        char *nam2;
        int i;
        int j;
        for (i = 0, nam1 = (char *)nameTmp; i < MAX_NAMES; i++, nam1 += NAME_LENGTH) {
            // char temp1[nameLength];
            // sscanf(nam1, "%s,%*d,%*d", temp1);
            int flag = 0;
            for (j = 0, nam2 = (char *)names; j < maxName; j++, nam2 += NAME_LENGTH) {
                // char temp[nameLength];
                // sscanf(nam2, "%s,%*d,%*d", temp);
                // printf("%s %s\n",nam1,nam2 );
                if (!strcmp(nam1, nam2)) {
                    flag = 1;
                }
                
            }

            if (!flag) {
                maxName++;
                // printf("%d\n", maxName);
                names = realloc(names, maxName * NAME_LENGTH * sizeof(char));

                char *nam;
                nam = (char *)names;
                nam = nam + (maxName - 1) * NAME_LENGTH;
                sprintf(nam, "%s", nam1);
                
            }

        }

        displayNames((char *)nameTmp, MAX_NAMES, NAME_LENGTH, a);

        int k;
        char *temp;
        for (k = 0, temp = (char *)nameTmp; k < 100; k++, allNam += NAME_LENGTH, temp += NAME_LENGTH) {
            strcpy(allNam, temp);
        }



        // quickStrSort((char *)nameTmp, (char *)nameTmp + NAME_LENGTH * (MAX_NAMES - 1), NAME_LENGTH);

        // char *nam;
        // int i;
        // for (i = 0, nam = (char *)nameTmp; i < 100; i++, nam += NAME_LENGTH) {
        //     printf("%-20s\n", nam);
        // }
        // printf("\n\n");

        fclose(infile2);
        
    }

    quickStrSort((char *)names, (char *)names + NAME_LENGTH * (maxName - 1), NAME_LENGTH);

    // char *nam;
    // int i;
    // for (i = 0, nam = (char *)names; i < maxName; i++, nam += NAME_LENGTH) {
    //     printf("%-20s %d\n", nam, i+1);
    // }
    // printf("\n\n");

    quickStrSort((char *)allNames, (char *)allNames + NAME_LENGTH * (MAX - 1), NAME_LENGTH);

    // char *nam3;
    // int i;
    // for (i = 0, nam3 = (char *)allNames; i < 1000; i++, nam3 += NAME_LENGTH) {
    //     printf("%-20s\n", nam3);
    // }
    // printf("\n\n");




    createFile((char *)names, (char *)allNames, maxName);


    
    free(names);
    
    // fclose(outfile1);

	return 0;
}

void createFile(char *names, char*allNames, int maxName) {

    FILE *outfile1 = fopen("summary.csv", "w");
    fprintf(outfile1, "Name,1920,1930,1940,1950,1960,1970,1980,1990,2000,2010");

    int i;
    int j;
    int k;
    char *nam;
    char *allnam;
    int yearank[maxName][10];
    memset(yearank, 0, sizeof(yearank[0][0]) * maxName * 10);

    // for (i = 0, nam = (char *)names; i < maxName; i++, nam += NAME_LENGTH) {
    //     printf("%d %s\n", i, nam);
    // }
    for (i = 0, nam = (char *)names; i < maxName; i++, nam += NAME_LENGTH) {
        // printf("%d %s\n",i, nam);
        
        for (j = 0, allnam = (char *)allNames; j < MAX; j++, allnam += NAME_LENGTH) {

            // printf("%d", j);

            char temp[NAME_LENGTH], nameTemp[NAME_LENGTH];
            int rank, year;
            strcpy(temp, allnam);
            sscanf(temp, "%s %d %d", nameTemp, &rank, &year);
            // printf("nam:%s temp:%s rank:%d year:%d\n", nam, nameTemp, rank, year);

            if (!strcmp(nam, nameTemp)) {
                printf("row:%d nam:%s temp:%s rank:%d year:%d\n", i, nam, nameTemp, rank, year);
                
                yearank[i][(year-1920)/10] = rank;

            }

        }

        fprintf(outfile1, "\n%s", nam);
        int k;
        int l;
        for (k = 0; k < 10; k++) {
            if (yearank[i][k] != 0) {
                fprintf(outfile1, ",%d ", yearank[i][k]);
            } else {
                fprintf(outfile1, ", ", yearank[i][k]);
            }
        }

    }

    fclose(outfile1);

}

// Reads from the given input file, names stored in a csv format: (name,F,####).
void getNames(FILE *f, char *n, int nLength, int maxN) {
    
    int i;
    // Read in the names from a csv file:
    for (i = 0; i < maxN && fscanf(f, " %[^,],F,%*s ", n + i * nLength) != EOF; i++);
    
    // return i;
}

// Displays a list of names/words/strings pointed to by names.
void displayNames(char *names, int nameCount, int nameLength, int year) {
    char *nam;
    int i;
    for (i = 0, nam = (char *)names; i < nameCount; i++, nam += nameLength) {
        char dest[NAME_LENGTH];
        sprintf(dest, "%s %d %d", nam,i + 1,year);
        strcpy(nam, dest);
        // printf("%-20s\n", nam);
    }
    // printf("\n\n"); 
} 

// quicksort method 
// Sorts (in this case) a list of strings, length of 13 each, 
// which begin at the memory location that left points to.
void quickStrSort(char *left, char *right, int length){
    int k;
    char *i = left;
    char *j = right;
    char *swap[NAME_LENGTH] = {'\0'};
    char test[NAME_LENGTH];
    char *s1 = i, *s2 = j;
    while (s1 < s2) {   // find midpoint for the test value
        s1 = s1 + length;
        s2 = s2 - length;
    }
    strncpy(test, s2, length - 1);
    do {
        // move i to the right until we find a value > the midpoint value
        // or i == right
        while (strcmp(i, test) < 0) i += length;
        // move j to the left until we find a value < the midpoint value
        // or j == left
        while (strcmp(j, test) > 0) j -= length;

        // Swap the two values (here we are demonstrating the full
        // details of swaping two strings. Normally, use of the
        // string.h function strcpy or strncpy would be preferred
        // to eliminate the complexity we see here):
        if (i <= j){
            for (s1 = (char *)swap, s2 = i; *s2 != '\0'; s1++, s2++)
                *s1 = *s2;
            *s1 = *s2;  // Also copy the '\0'
            for (s1 = i, s2 = j; *s2 != '\0'; s1++, s2++)
                *s1 = *s2;
            *s1 = *s2;
            for (s1 = j, s2 = (char *)swap; *s2 != '\0'; s1++, s2++)
                *s1 = *s2;
            *s1 = *s2;
            i += length;
            j -= length;
        }
    } while (i <= j);
    if (left < j) {
        quickStrSort(left, j, length);
    }
    if (i < right) {
        quickStrSort(i, right, length);
    }
}


