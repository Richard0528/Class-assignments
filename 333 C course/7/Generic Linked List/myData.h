/*
 *  myData.h
 *
 *  Data struct declaration or Header file to be used as the data field in a Node used
 *  in lists, trees, etc.
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 */
 
#ifndef MYDATA_H
#define MYDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following include is only necessary if the client wishes to access the name and/or
// value when stored in a linked data structure such as lists, trees, etc., i.e. myData
// and the client do not, and should not, know exactly how the linked data structure is
// implemented and possibly, where within a linked Node, the data resides.  On the other
// hand, the linked structure stores some type of field for the data without a need for
// specifics along with various pointers that link to other Nodes.  As such, the
// linked data structure needs to provide mechanisms for traversals while returning the
// data stored in each Node.  Obviously, the client needs this capability.  However, the
// linked structure should not be confined to any particular organization of the data
// portion of each Node. In this case, the linked structure can store various types of
// data without any changes made to the source code.  For our purposes, the process of
// printing the data in each Node while traversing the list is included here (see 
// printList).
#include "LinkedList.h"

#define NAME_SIZE 12

typedef struct data {
  char name[NAME_SIZE];
  int value;
} Data;

// Creates a data type "compare_functions" that can store a pointer to a function.
// Could be convenient for storing an array of functions: compare_functions funcs[10];
// See LLDriver for this use.
typedef int (*compare_functions)(const void *, const void *);


/*                              myData function prototypes                              */

/****************************************************************************************
 * createData                                                                           *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     char pointer (or array) that contains a name to be inserted into the Data struct.*
 *                  This string must contain the null-terminating character and cannot  *
 *                  exceed NAME_SIZE in length. Behavior is undetermined otherwise.     *
 *     integer to be inserted into a Data struct                                        *
 *                                                                                      *
 * Allocates memory for a Data struct, allocates memory for the name field, copies the  *
 * received name string to the name field and assigns the received integer to the value *
 * field.                                                                               *
 *                                                                                      *
 * Returns a pointer (cast as void *) to a Data struct filled with the received         *
 * parameters.                                                                          *
 ****************************************************************************************/
void *createData(char *name, int value);

/****************************************************************************************
 * printList                                                                            *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     FILE object for where to send the output steam                                   *
 *     pointer to a List                                                                *
 *     string containing a header message                                               *
 *                                                                                      *
 * Displays the information contained within the data field for each Node in the given  *
 * linked structure.  Here we use a simple single linked list. This function is the     *
 * reason for including the linked structure in the pre-processor directives. Because   *
 * myData does not know how the linked structure is implemented, it uses various        *
 * functions of the linked structure to access the actual data stored in each Node. The *
 * linkedList functions used are hasNext and getNext for traversal. Also, there is a    *
 * reference to a list Node (or List - same as Node) in the parameter list.             *
 ****************************************************************************************/
void printList(FILE *output, List *itr, char *header);

/****************************************************************************************
 * removeData                                                                           *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     a string representing the name to be removed from the list                       *
 *     pointer to a List                                                                *
 *                                                                                      *
 * Removes the node that contains the received name from the linked list. NOTE: this    * 
 * is one of the things that breaks encapsulation of the linked list but of course, so  *
 * is giving the client access to the list via the list pointer.                        *
 ****************************************************************************************/
void removeData(const char *name, List **itr);

/****************************************************************************************
 * changeValue                                                                          *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     a string representing the name of who's value is to be changed                   *
 *     an integer value used to update name's current value                             *
 *     pointer to a List                                                                *
 *                                                                                      *
 * Changes a person's value stored in a linked list.                                    * 
 ****************************************************************************************/
void changeValue(const char *name, int value, List *itr);

/****************************************************************************************
 * changeName                                                                           *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     a string representing the name to be changed                                     *
 *     a string used to update name's current name                                      *
 *     pointer to a List                                                                *
 *                                                                                      *
 * Changes a person's name stored in a linked list.                                     * 
 ****************************************************************************************/
void changeName(const char *name, const char *newName, List *itr);

/****************************************************************************************
 * getName                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     char pointer (or array)                                                          *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Copies the name field of the given Data struct to the first argument.                *
 * The client must provide enough storage (see getNameSize)as the first argument to     *
 * store all characters in the name field plus one byte for the null terminating        *
 * character otherwise the use of the first argument (and return value) is              *
 * undetermined.                                                                        *
 *                                                                                      *
 * Returns the address of the first argument containing a copy of the name field        *
 ****************************************************************************************/
char *getName(char *s, Data *data);

/****************************************************************************************
 * getValue                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Returns a copy of the value field of the given Data struct                           *
 ****************************************************************************************/
int getValue(Data *data);

/****************************************************************************************
 * setName                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     char pointer used to set the name field of the given Data struct                 *
 *     pointer to a Data struct. The length of *s should not exceed NAME_SIZE.          *
 *                                                                                      *
 * Assigns the given string to the given Data struct's name field                       *
 ****************************************************************************************/
void setName(char *s, Data *data);

/****************************************************************************************
 * setValue                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     integer used to set the value field of the given Data struct                     *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Assigns the given integer to the given struct's value field                          *
 ****************************************************************************************/
void setValue(int value, Data *data);

/****************************************************************************************
 * compareNameAsc                                                                       *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     void pointer (will be cast to a Data struct)                                     *
 *     void pointer (will be cast to a Data struct)                                     *
 *                                                                                      *
 * void pointers are used here to be in line with expected data types of a compare      *
 * function passed to the c library function qsort.                                     *
 *                                                                                      *
 * Using a cast to a Data struct on the received parameters, this compares the name     *
 * fields returning a negative integer if the first parameter is less than the second,  *
 * zero if equal, and a positive integer if the first is greater than the second.       *
 *                                                                                      *
 * The result is for ascending order of given strings.                                  *
 *                                                                                      *
 * Returns an integer representing the first parameter compared with the second         *
 ****************************************************************************************/
int compareNameAsc(const void *p1, const void *p2);

/****************************************************************************************
 * compareNameDesc                                                                      *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     void pointer (will be cast to a Data struct)                                     *
 *     void pointer (will be cast to a Data struct)                                     *
 *                                                                                      *
 * void pointers are used here to be in line with expected data types of a compare      *
 * function passed to the c library function qsort.                                     *
 *                                                                                      *
 * Using a cast to a Data struct on the received parameters, this compares the name     *
 * fields returning a positive integer if the first parameter is less than the second,  *
 * zero if equal, and a negative integer if the first is greater than the second.       *
 *                                                                                      *
 * The result is for descending order of given strings.                                 *
 *                                                                                      *
 * Returns an integer representing the first parameter compared with the second         *
 ****************************************************************************************/
int compareNameDesc(const void *p1, const void *p2);

/****************************************************************************************
 * compareValueAsc                                                                      *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     void pointer (will be cast to a Data struct)                                     *
 *     void pointer (will be cast to a Data struct)                                     *
 *                                                                                      *
 * void pointers are used here to be in line with expected data types of a compare      *
 * function passed to the c library function qsort.                                     *
 *                                                                                      *
 * Using a cast to a Data struct on the received parameters, this compares the value    *
 * fields returning a negative integer if the first parameter is less than the second,  *
 * zero if equal, and a positive integer if the first is greater than the second.       *
 *                                                                                      *
 * The result is for ascending order of given values.                                   *
 *                                                                                      *
 * Returns an integer representing the first parameter compared with the second         *
 ****************************************************************************************/
int compareValueAsc(const void *p1, const void *p2);

/****************************************************************************************
 * compareValueDesc                                                                     *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     void pointer (will be cast to a Data struct)                                     *
 *     void pointer (will be cast to a Data struct)                                     *
 *                                                                                      *
 * void pointers are used here to be in line with expected data types of a compare      *
 * function passed to the c library function qsort.                                     *
 *                                                                                      *
 * Using a cast to a Data struct on the received parameters, this compares the value    *
 * fields returning a positive integer if the first parameter is less than the second,  *
 * zero if equal, and a negative integer if the first is greater than the second.       *
 *                                                                                      *
 * The result is for descending order of given values.                                  *
 *                                                                                      *
 * Returns an integer representing the first parameter compared with the second         *
 ****************************************************************************************/
int compareValueDesc(const void *p1, const void *p2);

/****************************************************************************************
 * compareValueDescNameAsc                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     void pointer (will be cast to a Data struct)                                     *
 *     void pointer (will be cast to a Data struct)                                     *
 *                                                                                      *
 * void pointers are used here to be in line with expected data types of a compare      *
 * function passed to the c library function qsort.                                     *
 *                                                                                      *
 * Using a cast to a Data struct on the received parameters, this compares the value    *
 * fields returning a positive integer if the first parameter is less than the second,  *
 * zero if equal, and a negative integer if the first is greater than the second. A     *
 * comparison of names in ascending order is made if the two values are equal.          *
 *                                                                                      *
 * The result is for descending order of given values.                                  *
 *                                                                                      *
 * Returns an integer representing the first parameter compared with the second         *
 ****************************************************************************************/
int compareValueDescNameAsc(const void *p1, const void *p2);

/****************************************************************************************
 *XXXXXXXXXXXXXXXXXXXXX Let the linked list free this by freeing the data pointer!!!!!! *
 * freeData                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Deallocates (or frees) all allocated memory of the received Data struct.             *
 ****************************************************************************************/
void freeData(Data *data);

/****************************************************************************************
 * aPrivateFunction                                                                     *
 *                                                                                      *
 * Simply demonstrate possible encapsulation techniques in c.                           *
 * Returns an integer representing nothing in particular.                               *
****************************************************************************************/
static int aPrivateFunction();

/****************************************************************************************
 * clientAccessToPrivate                                                                *
 *                                                                                      *
 * Simply demonstrate possible encapsulation techniques in c.                           *
 * Returns an integer representing nothing in particular.                               *
****************************************************************************************/
int clientAccessToPrivate();

#endif