/******************************************************************************
 * SortingStructs2.c
 * Reads and processes data in nested structures while implementing parallel
 * arrays of pointers to the structures to be used in the sorting process.
 * Because there are two unlike arrays of pointers to be sorted, we implement
 * two versions of bubble sort: One to sort pointers to Student structures based
 * on how many assets a student owns and the other are pointers to myStuff
 * structures based on the weight of a particular myStuff.
 *
 * Here, ONLY pointer addresses to the struct are swapped during the sorting process.
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
void displayStudentsStuff(Student *[], int size);
int getStudentStuff(Student [], Student *[], char *fn);
void bubbleSort2AssetCount(Student *[], int);
void makeStudentsStable(Student [], int);
void bubbleSort2AssetsOnWeight(myStuff *[], int size);

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
  bubbleSort2AssetCount(studentPtrs, total);
  for (i = 0; i < total; i++)
    bubbleSort2AssetsOnWeight(studentPtrs[i]->assetPtrs, studentPtrs[i]->totalAssets);
  printf("************************************\n\n");
  displayStudentsStuff(studentPtrs, total);
}

/******************************************************************************
 * Use Bubble Sort 2 AssetCount to sort arrays of pointers (sorts based on how
 * many assets a student owns):
 */
void bubbleSort2AssetCount(Student *ptrs[], int size) {
  Student *s;
  int topBubble, bubbles, notSorted = 1;
  for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
    for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
      if (ptrs[bubbles]->totalAssets > ptrs[bubbles - 1]->totalAssets) {
        s = ptrs[bubbles];
        ptrs[bubbles] = ptrs[bubbles - 1];
        ptrs[bubbles - 1] = s;
        notSorted = 1;
      }
    }
}

/******************************************************************************
 * Use Bubble Sort 2 AssetsOnWeight to sort arrays of pointers (sorts the array
 * of pointers to myStuff or assets owned by a student):
 */
void bubbleSort2AssetsOnWeight(myStuff *ptrs[], int size) {
  myStuff *s;
  int topBubble, bubbles, notSorted = 1;
  for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
    for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
      if ((int) (ptrs[bubbles]->weight * 100) > (int) (ptrs[bubbles - 1]->weight * 100)) {
        s = ptrs[bubbles];
        ptrs[bubbles] = ptrs[bubbles - 1];
        ptrs[bubbles - 1] = s;
        notSorted = 1;
      }
    }
}


/******************************************************************************
 * Assures that the totalAssets field of each Student struct is set to 0.
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
 * Read in the students' data:
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
 