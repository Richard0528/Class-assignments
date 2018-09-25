/*
 * LLDriver.c
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#include <stdio.h>

#include "LinkedList.h"
//#include "LLMergeSort1.h"
#include "LLBubbleSort.h"
int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  char name[13];
  int value;
  List *list = createList();
  FILE *in = fopen("LinkedListInput.txt", "r");
  printf("Rounding up the usual suspects and inserting them in a list...\n");
  while (fscanf(in, "%s%d", name, &value) != EOF) {
    if(strlen(name) > 9)
      name[9] = '\0';
    insert(&list, name, value);
  }
  fclose(in);
  printf("Let's see who they are. Hit Enter to continue...\n");
  getchar();
  printList(list);
  printf("*********************************\n");
  printf("Sort descending by value using a compare function.\
 Hit Enter to continue...\n");
  getchar();
//  merge_sort_list_recursive(&list, compare);
  bubble_sort_list(&list, compare);
  printList(list);

  printf("*********************************\n");
  printf("Now sort ascending by value descending by name using a compare2 function.\
 Hit Enter to continue...\n");
  getchar();
//  merge_sort_list_recursive(&list, compare2);
  bubble_sort_list(&list, compare2);
  printList(list);

  freeList(list);

  return 0;
}

