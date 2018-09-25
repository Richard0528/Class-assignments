/*
 *  Linked List definition file: LinkedList.c
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#include "linkedlist.h"


Node *createList(void) {
  return NULL;
}

// Inserts alphabetically on name
void insert(List **list, char *name) {
  int temp = 1;
  Node *scan, *back= NULL;
  Node *newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->count = 1;
  newNode->next = NULL;

  if (*list == NULL) // Insert the very first node to the list:
    *list = newNode;
  else {
    scan = *list;
    while (scan != NULL && strcmp(scan->name, name) <= 0) {
      back = scan;
      if (strcmp(scan->name, name) == 0) {
        temp++;
        scan->count++;
        // scan->count = temp;
      }
      scan = scan->next;
    }
    
    if (scan == *list)
      insertAtBeginning(list, newNode);
    else if (temp == 1) {
      newNode->count = temp;
      newNode->next = scan;
      back->next = newNode;
    }

   // because there are only two types of insertion; at the beginning
   // and anywhere else.
      
  }
}

void insert2(List **list, char *name, int count) {
  Node *scan, *back = NULL;
  Node *newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->count = count;
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
    else {
      newNode->next = scan;
      back->next = newNode;
    } 
  }

}

// sorts descending
// if equal, sort descending by length of each word
// if length is equal, sort ascending alphabetically
int compare(Node *a, Node *b) {
  int result = b->count - a->count;
  if (!result) {
    int len1 = strlen(a->name);
    int len2 = strlen(b->name);
    result = len2 - len1;
    if (!result)
      result = strcmp(a->name, b->name);
  }
  return result;
}

void insertAtBeginning(List **list, Node *n) {
  n->next = *list;
  *list = n;
}

void printList(List *list) {
  if (list) {
    printf("%15s is %-5d\n", (*list).name, list->count);
    printList(list->next);
  }
}

void freeList(List *list) {
  if (list) {
    freeList(list->next);
    free(list);
  }
}

