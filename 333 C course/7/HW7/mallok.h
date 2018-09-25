// header file for mallok.c


#ifndef MALLOK_H
#define MALLOK_H
#include <stdio.h>
#include <stdlib.h>

// Data type definitions
typedef struct node {
    void *address;
    int size;
    int free;
    struct node *next;
} Node, List;

// global initialization
static void *heap = NULL;
static List *list = NULL;
static int currentSize = 0;
static int totalSize = 0;

// for heap declaration
void create_pool(int);
void *my_malloc(int);
void my_free(void *);
void free_pool();

// for linked list declaration
void freeList(List *);


#endif


