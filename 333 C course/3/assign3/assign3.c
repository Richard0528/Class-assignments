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
void getRankYear(char *names, int nameCount, int nameLength, int year);
void quickStrSort(char *left, char *right, int length);
void createFile(char *names, char *allNames, int maxName);
void getAll();

int main(void) {

    getAll();
    
	return 0;
}

// This method did a lot of things
// 1 - read in all 10 input files,
// 2 - names, get all 366 names from 10 input files,
// 3 - allNames, get 1000 rows of data, in this format: (name, rank, year),
// 4 - calling quick sorting method,
// 5 - calling creatFile() to output as .csv file
void getAll() {

    int year = 1920;
    char *names = (char *)malloc(MAX_NAMES * NAME_LENGTH * sizeof(char));
    char *allNames[MAX][NAME_LENGTH];  // = {'\0'}

    // for 1920
    FILE *infile1 = fopen("yob1920.txt", "r");

    // get all 100 name from 1920 file
    getNames(infile1, (char *)names, NAME_LENGTH, MAX_NAMES);

    fclose(infile1); 
    // done with 1920 year

    char *allNam;
    allNam = (char *)allNames;
    int maxName = MAX_NAMES;
    int a;
    for (a = 1920; a < 2020; a += 10) {
        char fp[15];
        sprintf(fp, "yob%d.txt", a);
        FILE *infile2 = fopen(fp, "r");

        char nameTmp[MAX_NAMES][NAME_LENGTH] = {'\0'};

        getNames(infile2, (char *)nameTmp, NAME_LENGTH, MAX_NAMES);

        // check if there are any names not in the main name list.
        char *nam1;
        char *nam2;
        int i;
        int j;
        for (i = 0, nam1 = (char *)nameTmp; i < MAX_NAMES; i++, nam1 += NAME_LENGTH) {

            int flag = 0;
            for (j = 0, nam2 = (char *)names; j < maxName; j++, nam2 += NAME_LENGTH) {

                // if the name exits in the names, there is no need to add it
                if (!strcmp(nam1, nam2)) {
                    flag = 1;
                }
                
            }
            
            // if the name does not exists in the names, add it
            if (!flag) {
                maxName++;
                // realloc more memory to the 2d array
                names = realloc(names, maxName * NAME_LENGTH * sizeof(char));

                char *nam;
                nam = (char *)names;
                // set memory address to the last element, then write in
                nam = nam + (maxName - 1) * NAME_LENGTH;
                sprintf(nam, "%s", nam1);
                
            }

        }

        getRankYear((char *)nameTmp, MAX_NAMES, NAME_LENGTH, a);

        // write all 1000 name into allnames
        int k;
        char *temp;
        for (k = 0, temp = (char *)nameTmp; k < 100; 
            k++, allNam += NAME_LENGTH, temp += NAME_LENGTH) {
            strcpy(allNam, temp);
        }

        fclose(infile2);
        
    }

    // quick sort the names array
    quickStrSort((char *)names, (char *)names + NAME_LENGTH * (maxName - 1), NAME_LENGTH);

    // quick sort the 1000 array which contains everything
    quickStrSort((char *)allNames, (char *)allNames + NAME_LENGTH * (MAX - 1), NAME_LENGTH);

    // create .csv file to write out
    createFile((char *)names, (char *)allNames, maxName);

    free(names);
}

// create .csv and writing data
void createFile(char *names, char*allNames, int maxName) {

    FILE *outfile1 = fopen("summary.csv", "w");
    // write the first line
    fprintf(outfile1, "Name,1920,1930,1940,1950,1960,1970,1980,1990,2000,2010");

    int i;
    int j;
    int k;
    char *nam;
    char *allnam;
    int yearank[maxName][10];
    memset(yearank, 0, sizeof(yearank[0][0]) * maxName * 10);

    // looping throught 366 names first, 
    // then pick collect ranks and years from the 1000 names array
    for (i = 0, nam = (char *)names; i < maxName; i++, nam += NAME_LENGTH) {
        
        for (j = 0, allnam = (char *)allNames; j < MAX; j++, allnam += NAME_LENGTH) {

            // open two string to hold name in 366 names list and 1000 names list
            char temp[NAME_LENGTH], nameTemp[NAME_LENGTH];
            int rank, year;
            strcpy(temp, allnam);
            sscanf(temp, "%s %d %d", nameTemp, &rank, &year);

            if (!strcmp(nam, nameTemp)) {

                // if the names are the same, get rank and year,
                // then copy it into the integer 2d array
                yearank[i][(year-1920)/10] = rank;

            }

        }

        fprintf(outfile1, "\n%s", nam);
        int k;
        int l;
        // loop through the integer 2d array, then write into .csv file
        for (k = 0; k < 10; k++) {
            if (yearank[i][k] != 0) {
                fprintf(outfile1, ",%d ", yearank[i][k]);
            } else {
                fprintf(outfile1, ", ");
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
void getRankYear(char *names, int nameCount, int nameLength, int year) {
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
    char *swap[NAME_LENGTH]; //  = {'\0'}
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


