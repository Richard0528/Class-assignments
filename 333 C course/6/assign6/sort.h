/*
 * LLBubbleSort.h
 *
 *  Created on: February 13, 2018
 *      Author: dschues1@uw.edu
 */

#ifndef SORT_H
#define SORT_H
#include "linkedlist.h"

void bubble_sort_list(List **list, int (*compare)(List *one, List *two));

#endif