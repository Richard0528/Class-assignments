/*
 *  Linked List declaration or Header file: LinkedList.h
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data type definitions
typedef struct node {
  char name[30];
  int count;
  struct node *next;
} Node, List;

// LinkedList prototypes

Node *createList(void);
void insertAtBeginning(List **, Node *);
void insert(List **, char *);
void insert2(List **, char *, int);
void printList(List *);
void freeList(List *);
int compare(Node *, Node *);
#endif