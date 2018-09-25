/*
 *  myData.c
 *
 *  Function definitions declared in myData.h which includes the creation and manipulation of
 *  a Data struct used as a data field within Nodes used in a linked data structure, such as
 *  linked lists, trees, etc.
 *
 *  Created on: Nov 20, 2016
 *      Author: dschues1@uw.edu
 */

#include "myData.h"

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
void *createData(char *name, int value) {
  Data *data = (Data *) malloc(sizeof(Data));
  strcpy(data->name, name);
  data->value = value;
  return (void *) data;
}

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
void printList(FILE *output, List *itr, char *header) {
  Data *data;
  char name[NAME_SIZE + 1];
  fprintf(output, "*********************************\n");
  fprintf(output, header);
  while (hasNext(itr)) {
    data = (Data *)getNext(&itr);
    fprintf(output, "Name:%12s, Value:%4d\n", getName(name, data), getValue(data));
  }
}

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
void removeData(const char *name, List **list) {
  Node *scan = *list, *back = NULL;
  int done = 0;
  Data *data;
  while (hasNext(scan) && !done) {
    data = (Data *)getData(scan);
    if (!(done = !strcmp(data->name, name))) {
      back = scan;
      (Data *)getNext(&scan);
    }
  }
  if (done) 
    removeNode(&back, &scan, list);
}

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
void changeValue(const char *name, int value, List *itr) {
  int done = 0;
  Data *data;
  while (hasNext(itr) && !done) {
    data = (Data *)getData(itr);
    if (done = !strcmp(data->name, name))
      data->value = value;
    else
      (Data *)getNext(&itr);
  }
}
 
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
void changeName(const char *name, const char *newName, List *itr) {
  int done = 0;
  Data *data;
  while (hasNext(itr) && !done) {
    data = (Data *)getData(itr);
    if (done = !strcmp(data->name, name))
      strcpy(data->name, newName);
    else
      (Data *)getNext(&itr);
  }
}

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
char *getName(char *s, Data *data) {
  return strcpy(s, data->name);
}

/****************************************************************************************
 * getValue                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Returns a copy of the value field of the given Data struct                           *
 ****************************************************************************************/
int getValue(Data *data) {
  return data->value;
}

/****************************************************************************************
 * setName                                                                              *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     char pointer used to set the name field of the given Data struct                 *
 *     pointer to a Data struct. The length of *s should not exceed NAME_SIZE.          *
 *                                                                                      *
 * Assigns the given string to the given Data struct's name field                       *
 ****************************************************************************************/
void setName(char *s, Data *data) {
  int i = 0;
  char *ptr = data->name;
  if (data)   // make sure memory has been allocated to data
    while (i++ <= NAME_SIZE && (*ptr++ = *s++));
  }

/****************************************************************************************
 * setValue                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     integer used to set the value field of the given Data struct                     *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Assigns the given integer to the given struct's value field                          *
 ****************************************************************************************/
void setValue(int value, Data *data) {
  data->value = value;
}

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
int compareNameAsc(const void *p1, const void *p2) {
  return strcmp(((Data *)p1)->name, ((Data *)p2)->name);
}

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
int compareNameDesc(const void *p1, const void *p2) {
  return strcmp(((Data *)p2)->name, ((Data *)p1)->name);
}

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
int compareValueAsc(const void *p1, const void *p2) {
  return ((Data *)p1)->value - ((Data *)p2)->value;
}

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
int compareValueDesc(const void *p1, const void *p2) {
  return ((Data *)p2)->value - ((Data *)p1)->value;
}

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
int compareValueDescNameAsc(const void *p1, const void *p2){
  int result = ((Data *)p2)->value - ((Data *)p1)->value;
  if (!result)
    result = strcmp(((Data *)p1)->name, ((Data *)p2)->name);
  return result;
}

/****************************************************************************************
 *XXXXXXXXXXXXXXXXXXXXX Let the linked list free this by freeing the data pointer!!!!!! *
 * freeData                                                                             *
 *                                                                                      *
 * Parameter(s):                                                                        *
 *     pointer to a Data struct                                                         *
 *                                                                                      *
 * Deallocates (or frees) all allocated memory of the received Data struct.             *
 ****************************************************************************************/
void freeData(Data *data) {
  free(data);
}

/****************************************************************************************
 * aPrivateFunction                                                                     *
 *                                                                                      *
 * Simply demonstrate possible encapsulation techniques in c.                           *
 * Returns an integer representing nothing in particular.                               *
****************************************************************************************/
static int aPrivateFunction() {
  return 17;
}

/****************************************************************************************
 * clientAccessToPrivate                                                                *
 *                                                                                      *
 * Simply demonstrate possible encapsulation techniques in c.                           *
 * Returns an integer representing nothing in particular.                               *
****************************************************************************************/
int clientAccessToPrivate() {
  return aPrivateFunction();
}
