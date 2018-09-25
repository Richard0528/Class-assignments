/*
 * LLMergeSort1.c
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 */

#include "LLMergeSort.h"

/****************************************************************************************
 * merge_sort_list_recursive                                                            *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     Address of the list pointer                                                      *
 *     pointer to a comparison function supplied by the client that receives two void   *
 *                  pointers each to a data struct defined by the client                *
 *                                                                                      *
 * Sorts a dynamically generated linked list using the mergesort algorithm.             *
 ****************************************************************************************/
void merge_sort_list_recursive(List **list, int (*compare)(const void *p1, const void *p2))
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
        // Take from empty lists, or compare:
        if (!right) {
            next = left;
            left = left->next;
        } else if (!left) {
            next = right;
            right = right->next;
        } else if (compare(left->data, right->data) < 0) {
            next = left;
            left = left->next;
        } else {
            next = right;
            right = right->next;
        }
        if (!result) {
            result = next;
        } else {
            tail->next = next;
        }
        tail = next;
      }
      *list = result;
    }
}
