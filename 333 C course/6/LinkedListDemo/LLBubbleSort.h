/*
 * LLBubbleSort.h
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#ifndef LLBUBBLESORT_H
#define LLBUBBLESORT_H
#include "LinkedList.h"

void bubble_sort_list(List **list, int (*compare)(List *one, List *two));

#endif