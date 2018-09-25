/*
 *  Linked List definition file: LinkedList.c
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 *
 *  Note: To maintain generic capability (i.e. any client data can be used) the data field is 
 *  a void pointer.  The client can declare any data type and pass a void pointer to the
 *  insert function of this Linked List data structure.
 */

#include "LinkedList.h"

/****************************************************************************************
 * createList                                                                           *
 *                                                                                      *
 * Simply sets the list pointer to NULL, i.e. representing an empty list.               *
 *                                                                                      *
 * Returns the list pointer set to NULL.                                                *
 ****************************************************************************************/
Node *createList(List **list) {
  *list = NULL;
  return *list;
}

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
void insert(List **list, void *data, int (*compare)(const void *p1, const void *p2)) {
  Node *scan, *back = NULL;
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*list == NULL) // Insert the very first node to the list:
    *list = newNode;
  else {
    scan = *list;
    while (scan != NULL && compare(scan->data, data) < 0) {
      back = scan;
      scan = scan->next;
    }
    if (scan == *list)
      insertAtBeginning(list, newNode);
    else {                               // insert anywhere else:
      newNode->next = scan;
      back->next = newNode;
    }
  }
}

/****************************************************************************************
 * insertAtBeginning                                                                    *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list pointer                                                      *
 *     Node pointer to a list Node                                                      *
 *                                                                                      *
 * Inserts the received Node at the beginning of the list and updates the list pointer. *
 ****************************************************************************************/
void insertAtBeginning(List **list, Node *n) {
  n->next = *list;
  *list = n;
}

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
void removeNode(Node **back, Node **current, List **list) {
  free((*current)->data);           // free the allocated data field
  if (*back == NULL)                // remove from the front
    *list = (*current)->next;
  else
    (*back)->next = (*current)->next;
  free(*current);
}

/****************************************************************************************
 * hasNext                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Node pointer to a list Node                                                      *
 *                                                                                      *
 * Returns true if the received pointer points to a Node, false otherwise.              *
 ****************************************************************************************/
 int hasNext(Node *node) {
  return !(node == NULL);
}

/****************************************************************************************
 * getNext                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of a Node pointer to a list Node                                         *
 *                                                                                      *
 * Returns a void pointer to the data field of a given Node pointer and advances the    *
 * received pointer to the next Node in the list.                                       *
 ****************************************************************************************/
void *getNext(Node **node) {
  void *ptr = (*node)->data;
  *node = (*node)->next;
  return ptr;
} 
/****************************************************************************************
 * getData                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of a Node pointer to a list Node                                         *
 *                                                                                      *
 * Returns a void pointer to the data field of a given Node pointer.                    *
 ****************************************************************************************/
void *getData(Node *node) {
  return node->data;
} 

/****************************************************************************************
 * freeList                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list Node, i.e. first node in the list                            *
 *                                                                                      *
 * Frees each data field and the node that contains it for all nodes in the list.       *
 ****************************************************************************************/
/*void freeList(List *list) {
  if (list) {
    freeList(list->next);
    if (list->data)
*/
                         /***************************************
                          *  This version does not completely   *
                          *  free the list. The pointer to the  *
                          *  list (client's pointer) is never   *
                          *  freed. See version below:          *
                          ***************************************/
/*
      free(list->data);
    list->data = NULL;
    free(list);
    list = NULL;
  }
}*/

void freeList(List **list) {
  printf("IN: %p\n", *list);
  if (*list) {
    freeList(&(*list)->next);
    if ((*list)->data)
      free((*list)->data);
    (*list)->data = NULL;
    printf("OUT: %p\n", *list);
    free(*list);
    *list = NULL;
  }
}

