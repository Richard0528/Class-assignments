/*
 * LLMergeSort1.c
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#include "LLMergeSort1.h"
#include "LinkedList.h"

void merge_sort_list_recursive(List **list, int (*compare)(Node *one, Node *two))
{
	List *left = *list;
    // Trivial case.
    if (left && left->next) {

      List *right = *list,
           *temp  = *list,
           *last  = *list,
           *result = NULL,
           *next   = NULL,
           *tail   = NULL;

    // Find halfway through the list (by running two pointers, 
    // one at twice the speed of the other).
      while (temp && temp->next)
      {
        last = right;
        right = right->next;
        temp = temp->next->next;
      }

    // Break the list in two. (link between left & right broken here, but we fix later)
      last->next = NULL;

    // Recurse on the two smaller lists:
      merge_sort_list_recursive(&left, compare);
      merge_sort_list_recursive(&right, compare);

    // Merge:
      while (left || right)
      {
        // Take from empty lists or compare for smallest node (next
        // will mark the current smallest node):
        if (!right) {
            next = left;
            left = left->next;
        } else if (!left) {
            next = right;
            right = right->next;
        } else if (compare(left, right) < 0) {
            next = left;
            left = left->next;
        } else {
            next = right;
            right = right->next;
        }
        if (!result) {          // First time only. Keeps track
            result = next;      // of where list should start.
        } else {
            tail->next = next;  // Connect previous smallest node
        }                       // to current smallest node
        tail = next;            // Keep track of current smallest
      }                         // node for next iteration.
      *list = result;           // Merge complete, now update the
    }                           // list pointer to the smallest node.
}
