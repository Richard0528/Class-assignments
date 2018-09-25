/*
 *  Linked List definition file: LinkedList.c
 */

#include "linkedlist.h"

Node *createList(void *heap, int size) {
    Node *newNode = malloc(sizeof(Node));
    newNode->address = heap;
    newNode->size = size;
    newNode->free = true;
    newNode->next = NULL;
    *list = newNode;
    return *list;
}


void insert(List **list, void *temp, int size, Boolean free) {
    Node *scan, *back = NULL;
    Node *newNode = malloc(sizeof(Node));
    newNode->address = temp;
    newNode->size = size;
    newNode->free = false;
    newNode->next = NULL;

    scan = *list;
    while (scan.next != NULL) {
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


void insertAtBeginning(List **list, Node *n) {
    n->next = *list;
    *list = n;
}


void removeNode(Node **back, Node **current, List **list) {
    free((*current)->data);           // free the allocated data field
    if (*back == NULL)                // remove from the front
        *list = (*current)->next;
    else
        (*back)->next = (*current)->next;
    free(*current);
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
