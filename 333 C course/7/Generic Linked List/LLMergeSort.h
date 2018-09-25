/*
 * LLMergeSort.h
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 */


#ifndef LLMERGESORT_H
#define LLMERGESORT_H
#include "LinkedList.h"

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
void merge_sort_list_recursive(List **, int (*compare)(const void *p1, const void *p2));
#endif
