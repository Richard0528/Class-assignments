/******************************************************************************
 * SortingStructs1.c
 * Reads and processes data in nested structures stored in an array of Student.
 * Because there are two unlike arrays of data to be sorted, we implement
 * two versions of bubble sort: One to sort an array of Student structures based
 * on how many assets a student owns and the other sorts an array of myStuff
 * structures based on the weight of a particular myStuff that a student owns.
 *
 * Here, ALL data within the struct has to be swapped during the sorting process.
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
  int totalAssets;
};
typedef struct student Student;

// Function prototypes:
void displayStudentsStuff(Student stu[], int size);
int getStudentStuff(Student stu[], char *fn);
void bubbleSort2AssetCount(Student stu[], int size);
void makeStudentsStable(Student [], int);
void bubbleSort2AssetsOnWeight(myStuff assets[], int size);

/******************************************************************************
 * main function to process students' assets data:
 */
main() {
  int total, i;
  Student students[10];
  makeStudentsStable(students, 10);
  total = getStudentStuff(students, "studentStuff.txt");
  displayStudentsStuff(students, total);
  bubbleSort2AssetCount(students, total);
  for (i = 0; i < total; i++)
    bubbleSort2AssetsOnWeight(students[i].assets, students[i].totalAssets);
  printf("************************************\n\n");
  displayStudentsStuff(students, total);
}

/******************************************************************************
 * Use Bubble Sort 2 AssetCount to sort the array of Student(sorts based on how
 * many assets a student owns):
 */
void bubbleSort2AssetCount(Student stu[], int size) {
  Student s;
  int topBubble, bubbles, notSorted = 1;
  for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
    for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
      if (stu[bubbles].totalAssets > stu[bubbles - 1].totalAssets) {
        s = stu[bubbles];
        stu[bubbles] = stu[bubbles - 1];
        stu[bubbles - 1] = s;
        notSorted = 1;
      }
    }
}

/******************************************************************************
 * Use Bubble Sort 2 AssetsOnWeight to sort arrays myStuff (sorts the array
 * of myStuff or assets owned by a student):
 */
void bubbleSort2AssetsOnWeight(myStuff assets[], int size) {
  myStuff s;
  int topBubble, bubbles, notSorted = 1;
  for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
    for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
      if ((int) (assets[bubbles].weight * 100) > (int) (assets[bubbles - 1].weight * 100)) {
        s = assets[bubbles];
        assets[bubbles] = assets[bubbles - 1];
        assets[bubbles - 1] = s;
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
void displayStudentsStuff(Student stu[], int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    printf("%s owns %d assets:\n", stu[i].name, stu[i].totalAssets);
    for (j = 0; j < stu[i].totalAssets; j++)
      printf("\tAsset: %12s, weight = %8.2f\n", stu[i].assets[j].name,
              stu[i].assets[j].weight);
  }
}

/******************************************************************************
 * Read in the students' data:
 */
int getStudentStuff(Student stu[], char *fn) {
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
    stu[i].totalAssets++;
  }
  fclose(in);
  printf("current count: %d \n" ,count);
  return count;
}      
 