/*
 *  Linked List definition file: LinkedList.c
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#include "LinkedList.h"


Node *createList(void) {
  return NULL;
}

// Inserts alphabetically on name
void insert(List **list, char *name, int value) {
  Node *scan, *back = NULL;
  Node *newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->value = value;
  newNode->next = NULL;

  if (*list == NULL) // Insert the very first node to the list:
    *list = newNode;
  else {
    scan = *list;
    while (scan != NULL && strcmp(scan->name, name) < 0) {
      back = scan;
      scan = scan->next;
    }
    if (scan == *list)
      insertAtBeginning(list, newNode);
    else if (scan == NULL) {       // insert at the end:
      newNode->next = back->next;  //yeah, I know, its already NULL
      back->next = newNode;
    } else {                       // insert in the middle:
      newNode->next = scan;
      back->next = newNode;
    }
/*
   The above "else if ... else" blocks should really just be:
    
    else {
      newNode->next = scan;
      back->next = newNode;
    }

   because there are only two types of insertion; at the beginning
   and anywhere else.
*/      
  }
}

// sorts descending
int compare(Node *a, Node *b) {
  return b->value - a->value;
}
// sorts ascending-if equal, sort descending by name
int compare2(Node *a, Node *b) {
  int result = a->value - b->value;
  if (!result)
    result = strcmp(b->name, a->name);
  return result;
}

void insertAtBeginning(List **list, Node *n) {
  n->next = *list;
  *list = n;
}

void printList(List *list) {
  if (list) {
    printf("%10s has %-5d\n", (*list).name, list->value);
    printList(list->next);
  }
}

void freeList(List *list) {
  if (list) {
    freeList(list->next);
    free(list);
  }
}

