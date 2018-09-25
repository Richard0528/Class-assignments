/*
 *  Linked List declaration or Header file: LinkedList.h
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

// Data type definitions
typedef struct node {
    void *address;
    int size
    Boolean free;
    struct node *next;
} Node, List;


Node *createList(List **list);
void insert(List **list, int address, int size, Boolean free);
void insertAtBeginning(List **, Node *);
void removeNode(Node **back, Node **current, List **list);
void freeList(List **);

#endif