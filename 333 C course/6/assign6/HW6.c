// TCSS 333 - assignment6
// Zhihao Yang

/*
 * HW6.c
 * Driver
 * There exists four words start with \0, I tried to get rid of them at line 66
 * But it's not working
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "sort.h"

List * getFile(FILE *, List *);
List * getRank(List **, List **, List *);
void output(List **, List **, List **, int);
void getAll();

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);  // just in case if you use eclipse

    getAll();

    return 0;
}

// this method did 2 things
// 1. get all the data from two files.
// 2. create merged list and print out.
void getAll() {
    List *list1 = createList();
    FILE *in1 = fopen("LittleRegiment.txt", "r");
    list1 = getFile(in1, list1);
    fclose(in1);
    // printList(list1);
    
    List *list2 = createList();
    FILE *in2 = fopen("RedBadge.txt", "r");
    list2 = getFile(in2, list2);
    fclose(in2);
    // printList(list2);

    List *sumList = createList();
    sumList = getRank(&list1, &list2, sumList);
    output(&sumList, &list1, &list2, 0);
    bubble_sort_list(&sumList, compare);

    output(&sumList, &list1, &list2, 1);

    freeList(list1);
    freeList(list2);
    freeList(sumList);
}

// get data from file, put them into a list
List * getFile(FILE *in1, List *list) {

    char word[30] = {'\0'};
    // char result[30] = {'\0'};
    int i, j;
    while (fscanf(in1, "%s", word) != EOF) {
        char result[30] = {'\0'};
        
        if (word[0] != '\0') {
            // printf("%s\n", word);
            word[28] = '\0';
            i = 0;
            while (!(isalpha(word[i]) || word[i] == 39 || word[i] == 45)) {
                i++;
                // printf("%c\n", word[i]);
            }
            
            for (j = 0; i < 30 && word[i] != ' ' && word[i] != '\0'; j++, i++) {
                if (isalpha(word[i]) || word[i] == 39 || word[i] == 45 ) {
                    if (isupper(word[i])) {
                        result[j] = tolower(word[i]);
                    } else {
                        result[j] = word[i];
                    }
                    // printf("%c %d %c %d\n", word[i], i, result[j], j);
                }
            }

            result[j+1] = '\0';
            // printf("%s\n", result);
            
            insert(&list, result);
        } else {
            printf("WOW %s\n", word);
        }
          
    }

    return list;
        
}

// merged two list in decreasing order
List * getRank(List **list1, List **list2, List *sumList) {

    Node *scan1 = *list1;

    while (scan1 != NULL) {
        Node *scan2 = *list2;

        while (scan2 != NULL && strcmp(scan1->name, scan2->name) != 0) {
            // printf("%s compareTo %s\n", scan1->name, scan2->name);

            scan2 = scan2->next;
        }

        if (scan2 != NULL && !strcmp(scan1->name, scan2->name)) {
            insert2(&sumList, scan1->name, abs(scan1->count - scan2->count));
        } else if (scan2 == NULL) {
            insert2(&sumList, scan1->name, abs(scan1->count - 0));
        }

        scan1 = scan1->next;
    }

    Node *scan3 = *list2;
    while (scan3 != NULL) {
        Node *scan4 = sumList;

        while (scan4 != NULL && strcmp(scan3->name, scan4->name) != 0) {
            scan4 = scan4->next;
        }

        if (scan4 == NULL) {
            insert2(&sumList, scan3->name, abs(scan3->count - 0));
        }

        scan3 = scan3->next;
    }

    // printList(finalList);
    return sumList;

}

// creat console ouput
void output(List **list, List **list1, List **list2, int flag) {

    int i = 0;
    Node *temp = *list;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    printf("There are %d unique words!\n", i);
    printf("Sorted by difference:\n");
    Node *info = *list;
    int j = 1;

    while (j < i + 1) {

        if (j < 26 || (j > (i - 5) && flag)) {
        // if (j < 8435) {
            int count1 = 0;
            int count2 = 0;
            
            Node *scan1 = *list1;
            Node *scan2 = *list2;
            while (scan1 != NULL) {

                if (!strcmp(info->name, scan1->name)) {
                    count1 = scan1->count;
                    // printf("%s is %d\n", scan1->name, scan1->count);
                }
                scan1 = scan1->next;
            }

            while (scan2 != NULL) {

                if (!strcmp(info->name, scan2->name)) {
                    count2 = scan2->count;
                    // printf("%s is %d\n", scan2->name, scan2->count);
                }
                scan2 = scan2->next;
            }

            printf("      %d. %s, RedBadge.txt: %d, LittleRegiment.txt: %d, Difference: %d \n", 
                j, info->name, count2, count1, info->count);
            
        }
        j++;
        info = info->next;
    }

}


