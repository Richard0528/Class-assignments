/*
 * LLDriver.c
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 *
 *  Demonstrates the use of a "generic" linked list that can be used for various
 *  data without changes to the linked list.
 */

#include <stdio.h>

#include "LinkedList.h"
#include "LLMergeSort.h"
#include "myData.h"

int main() {
  setvbuf(stdout, NULL, _IONBF, 0);

  char *messages[] = {"Initial List:\n", "Descending by Name:\n",
                      "Ascending by Values:\n", "Descending by Values:\n",
                      "Descending by Values & Ascending by Name:\n",
                      "Ascending by Name:\n", "Changes to Maryia and Bob\n",
                      "After Names Removed:\n"};
  char *deleteNames[] = {"Maryia", "Aaron", "Fasil", "Marshall"};

  // see typedef for compare_functions in myData.h:
  compare_functions funcsArray[] = {compareNameDesc, compareValueAsc, 
                                    compareValueDesc, compareValueDescNameAsc, 
                                    compareNameAsc};
  char name[NAME_SIZE];
  int value, i;
  List *list;
  FILE *in = fopen("LinkedListInput.txt", "r");
  list = createList(&list);
  while (fscanf(in, "%s%d", name, &value) != EOF)
    insert(&list, createData(name, value), compareNameAsc);
  fclose(in);

  printList(stdout, list, messages[0]);
  for (i = 0; i < 5; i++) {
    merge_sort_list_recursive(&list, funcsArray[i]);
    printList(stdout, list, messages[i + 1]);
    getchar();
  }

  changeValue("Maryia", 500, list);
  changeName("Bob", "Robert", list);
  merge_sort_list_recursive(&list, funcsArray[4]);
  printList(stdout, list, messages[6]);
  getchar();
  for (i = 0; i < 4; i++) {
    fprintf(stdout, "Removing %s...\n", deleteNames[i]);
    removeData(deleteNames[i], &list);
  }
  printList(stdout, list, messages[7]);
  getchar();
  printf("Address of list: %p\n", list);
  freeList(&list);
  printf("Address of list: %p\n", list);

  printf("Trying to access a private (static) function in myData.c:\n");
  // printf("Returned from private function: %d\n", aPrivateFunction());
  printf("Ooops!  Better use clientAccessToPrivate() to get to it: %d\n",
         clientAccessToPrivate()); 
  return 0;
}

   
    