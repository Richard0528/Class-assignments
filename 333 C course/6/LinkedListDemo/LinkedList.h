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
  char name[10];
  int value;
  struct node *next;
} Node, List;

// LinkedList prototypes

Node *createList(void);
void insert(List **, char *, int);
void insertAtBeginning(List **, Node *);
void printList(List *);
void freeList(List *);
int compare(Node *, Node *);
int compare2(Node *, Node *);
#endif 