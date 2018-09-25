/*
 *  Linked List declaration or Header file: LinkedList.h
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 *
 *  Note: To maintain generic capability (i.e. any client data can be used) the data field is 
 *  a void pointer.  The client can declare the data type and pass a void pointer to the
 *  insert function of this Linked List data structure.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

// Data type definitions
typedef struct node {
  void *data;
  struct node *next;
} Node, List;

/*                            LinkedList function prototypes                            */

/****************************************************************************************
 * createList                                                                           *
 *                                                                                      *
 * Simply sets the list pointer to NULL, i.e. representing an empty list.               *
 *                                                                                      *
 * Returns the list pointer set to NULL.                                                *
 ****************************************************************************************/
Node *createList(List **list);

/****************************************************************************************
 * insert                                                                               *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list pointer                                                      *
 *     void pointer to a data struct as defined by the client (note: this data field    *
 *                  must be allocated on the heap and filled with data by the client)   *
 *     pointer to a comparison function supplied by the client that receives two void   *
 *                  pointers each to a data struct defined by the client                *
 *                                                                                      *
 * Inserts list nodes into a single linked list in order based on the received compare  *
 * function.  Also, updates the list pointer if need be.                                *
 ****************************************************************************************/
void insert(List **list, void *data, int (*compare)(const void *p1, const void *p2));

/****************************************************************************************
 * insertAtBeginning                                                                    *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list pointer                                                      *
 *     Node pointer to a list Node                                                      *
 *                                                                                      *
 * Inserts the received Node at the beginning of the list and updates the list pointer. *
 ****************************************************************************************/
void insertAtBeginning(List **, Node *);

/****************************************************************************************
 * removeNode                                                                           *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Node pointer to a list Node (previous of node to be deleted)                     *
 *     Node pointer to a list Node (node to be deleted)                                 *
 *     List pointer to the start of the list                                            *
 *                                                                                      *
 * Simply removes the node pointed to by current and updates the list pointer if needed.*
 ****************************************************************************************/
void removeNode(Node **back, Node **current, List **list);

/****************************************************************************************
 * hasNext                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Node pointer to a list Node                                                      *
 *                                                                                      *
 * Returns true if the received pointer points to a Node, false otherwise.              *
 ****************************************************************************************/
 int hasNext(Node *);

/****************************************************************************************
 * getNext                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of a Node pointer to a list Node                                         *
 *                                                                                      *
 * Returns a void pointer to the data field of a given Node pointer and advances the    *
 * received pointer to the next Node in the list.                                       *
 ****************************************************************************************/
void *getNext(Node **); 

/****************************************************************************************
 * getData                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of a Node pointer to a list Node                                         *
 *                                                                                      *
 * Returns a void pointer to the data field of a given Node pointer.                    *
 ****************************************************************************************/
void *getData(Node *node);
 
/****************************************************************************************
 * freeList                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list Node, i.e. first node in the list                            *
 *                                                                                      *
 * Frees each data field and the node that contains it for all nodes in the list.       *
 ****************************************************************************************/
void freeList(List **);

#endif 