/******************************************************************************
 * SortingStructs3.c
 * Reads and processes data in nested structures while implementing parallel
 * arrays of pointers to the structures to be used in the sorting process.
 * Only a single version of Bubble Sort 2 is used by sending a pointer to
 * a comparison function that distinguishes the type of data being compared.
 *
 * Here, only pointer addresses are swapped instead of all the data.
 */
#include <stdio.h>
#include <string.h>

// Named constants
#define NAM_LEN 10
#define STUFF_NAM_LEN 13
#define MAX_STU 10
#define MAX_ASSETS 5

// Data structures defined:
struct stuff {
  char name[STUFF_NAM_LEN];
  float weight;
};
typedef struct stuff myStuff;
struct student {
  char name[NAM_LEN];
  myStuff assets[MAX_ASSETS];
  myStuff *assetPtrs[MAX_ASSETS];
  int totalAssets;
};
typedef struct student Student;

// Function prototypes:
void displayStudentsStuff(Student *[], int);

int getStudentStuff(Student [], Student *[], char *);

void bubbleSort2(void *[], int, int(*compare)(const void *, const void *));

int assetCompare(const void *, const void *);
int weightCompare(const void *, const void *);
void makeStudentsStable(Student [], int);

/******************************************************************************
 * main function to process students' assets data:
 */
main() {
  int total, i;
  Student students[10];
  Student *studentPtrs[10];
  makeStudentsStable(students, 10);
  total = getStudentStuff(students, studentPtrs, "studentStuff.txt");
  displayStudentsStuff(studentPtrs, total);
  bubbleSort2((void *) studentPtrs, total, assetCompare);
  for (i = 0; i < total; i++)
    bubbleSort2((void *) (studentPtrs[i]->assetPtrs), 
                studentPtrs[i]->totalAssets, 
                weightCompare);
  printf("************************************\n\n");
  displayStudentsStuff(studentPtrs, total);
}

/******************************************************************************
 * Use Bubble Sort 2 to sort arrays of pointers (is passed a pointer to the
 * appropriate comparison function):
 */
void bubbleSort2(void *ptrs[], int size,
                           int (*compare)(const void *, const void *)) {
  void *s;
  int topBubble, bubbles, notSorted = 1;
  for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
    for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
      if (compare(ptrs[bubbles], ptrs[bubbles - 1]) > 0) {
        s = ptrs[bubbles];
        ptrs[bubbles] = ptrs[bubbles - 1];
        ptrs[bubbles - 1] = s;
        notSorted = 1;
      }
    }
}

/******************************************************************************
 * Two comparison functions using pointers to the data:
 */
int assetCompare(const void *a1, const void *a2) {
  return ((Student *)a1)->totalAssets - ((Student *)a2)->totalAssets;
}
int weightCompare(const void *w1, const void *w2) {
  return (int)(((myStuff *)w1)->weight * 100 - ((myStuff *)w2)->weight * 100);
}

/*****************************************************************************
 * makeStudentsStable assue the asset count filed starts at 0.
 */
void makeStudentsStable(Student stu[], int size) {
  int i, j;
  for (i = 0; i < size; i++) 
    stu[i].totalAssets = 0;
}
      
/******************************************************************************
 * Display the students' data:
 */
void displayStudentsStuff(Student *ptrs[], int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    printf("%s owns %d assets:\n", ptrs[i]->name, ptrs[i]->totalAssets);
    for (j = 0; j < ptrs[i]->totalAssets; j++)
      printf("\tAsset: %12s, weight = %8.2f\n", ptrs[i]->assetPtrs[j]->name,
              ptrs[i]->assetPtrs[j]->weight);
  }
}

/******************************************************************************
 * Read in the students' data while assigning pointers in parallel arrays to 
 * the data being stored:
 */
int getStudentStuff(Student stu[], Student *p[], char *fn) {
  FILE *in = fopen(fn, "r");
  char stuName[NAM_LEN], stuffName[STUFF_NAM_LEN];
  int i, count = 0;
  float w;
  while (count < 10 && fscanf(in, "%s%s%f", stuName, stuffName, &w) != EOF) {
    for (i = 0; i < count && strcmp(stuName, stu[i].name); i++);
    if (i == count) 
      count++;
    strcpy(stu[i].name, stuName);
    strcpy(stu[i].assets[stu[i].totalAssets].name, stuffName);
    stu[i].assets[stu[i].totalAssets].weight = w;
    p[i] = &stu[i];
    p[i]->assetPtrs[p[i]->totalAssets] = &(stu[i].assets[stu[i].totalAssets]);
    stu[i].totalAssets++;
  }
  fclose(in);
  return count;
}      
 