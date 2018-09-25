
#include "mallok.h"


void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void printHeap();

int main() {
    
    // create_pool(1000);
    printf("TEST1: \n");
    test1();
    printf("TEST2: \n");
    test2();
    printf("TEST3: \n");
    test3();
    // printf("TEST4: \n");
    // test4();
    printf("TEST5: \n");
    test5();
    printf("TEST6: \n");
    test6();
    printf("TEST7: \n");
    test7();

    // create_pool(1000);
    // test2();
    // test3();
    // // void *p1 = my_malloc(200);
    // // my_free(p1);

    // test4();   
    
    return 0;
}

void printHeap() {
    Node *scan = list;

    while(scan) {
        printf("Address: %p\n", scan->address);
        printf("Size: %d\n", scan->size);
        printf("Free: %d\n", scan->free);
        printf("-------------++++++++++\n");
        scan = scan->next;
    }
}

void test7() {
    create_pool(1000);
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(50);
    void *p3 = my_malloc(150);
    void *p4 = my_malloc(50);
    void *p5 = my_malloc(150);
    void *p6 = my_malloc(200);
    void *p7 = my_malloc(151);
    void *p8 = my_malloc(49);

    my_free(p3);
    my_free(p5);
    my_free(p8);

    void *p9 = my_malloc(325);
    free_pool();

}

void test6() {
    create_pool(1000);
    void *p1 = my_malloc(1000);

    my_free(p1);

    void *p2 = my_malloc(250);
    void *p3 = my_malloc(250);
    void *p4 = my_malloc(250);
    void *p5 = my_malloc(250);

    my_free(p2);
    my_free(p3);
    my_free(p4);
    my_free(p5);


    void *p6 = my_malloc(100);
    void *p7 = my_malloc(100);
    void *p8 = my_malloc(100);
    void *p9 = my_malloc(100);
    void *p10 = my_malloc(100);
    void *p11 = my_malloc(100);
    void *p12 = my_malloc(100);
    void *p13 = my_malloc(100);
    void *p14 = my_malloc(100);
    void *p15 = my_malloc(100);
    void *p16 = my_malloc(100);

    printf("%d\n", currentSize);
    printf("%p\n", p16);

    free_pool();
    create_pool(1000);
    printf("Second try:\n");
    p6 = my_malloc(100);
    p7 = my_malloc(100);
    p8 = my_malloc(100);
    p9 = my_malloc(100);
    p10 = my_malloc(100);
    p11 = my_malloc(100);
    p12 = my_malloc(100);
    p13 = my_malloc(100);
    p14 = my_malloc(100);
    p15 = my_malloc(100);
    p16 = my_malloc(100);

    printf("%d\n", currentSize);
    printf("%p\n", p16);

    printHeap();

    my_free(p6);
    my_free(p7);
    my_free(p8);
    my_free(p9);
    my_free(p10);
    my_free(p11);
    my_free(p12);
    my_free(p13);
    my_free(p14);
    my_free(p15);

    free_pool();

}

void test5() {
    create_pool(1000);
    int count = 0;
    while (my_malloc(10)) {
        count++;
    }
    printf("count: %d\n", count);
    free_pool();
}

void test4() {
    create_pool(1000);
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);

    char *pnt = list->address;
    char *pnt2 = list->next->address;
    char *pnt3 = list->next->next->address;
    char *pnt4 = list->next->next->next->address;
    char *pnt5 = list->next->next->next->next->address;
    char *pnt6 = list->address;
    char *pnt7 = list->next->address;
    char *pnt8 = list->next->next->address;
    char *pnt9 = list->next->next->next->address;
    char *pnt10 = list->next->next->next->next->address;

    for (int i = 0; i < list->size; i++, pnt++) {
        *pnt = 'A';
    }

    for (int i = 0; i < list->next->size; i++, pnt2++) {
        *pnt2 = 'B';
    }

    for (int i = 0; i < list->next->next->size; i++, pnt3++) {
        *pnt3 = 'C';
    }

    for (int i = 0; i < list->next->next->next->size; i++, pnt4++) {
        *pnt4 = 'D';
    }

    for (int i = 0; i < list->next->next->next->next->size; i++, pnt5++) {
        *pnt5 = 'E';
    }

    printf("First Block:\n");
    for (int i = 1; i <= list->size; i++, pnt6++) {
        printf("%c", *pnt6);
        if (i % 20 == 0)
            printf("\n");
    }

    printf("\n");
    printf("Second Block:\n");
    for (int i = 1; i <= list->next->size; i++, pnt7++) {
        printf("%c", *pnt7);
        if (i % 20 == 0)
            printf("\n");   
    }

    printf("\n");
    printf("Third Block:\n");
    for (int i = 1; i <= list->next->next->size; i++, pnt8++) {
        printf("%c", *pnt8);
        if (i % 20 == 0)
            printf("\n");   
    }

    printf("\n");
    printf("Forth Block:\n");
    for (int i = 1; i <= list->next->next->next->size; i++, pnt9++) {
        printf("%c", *pnt9);
        if (i % 20 == 0)
            printf("\n");   
    }

    printf("\n");
    printf("Fifth Block:\n");
    for (int i = 1; i <= list->next->next->next->next->size; i++, pnt10++) {
        printf("%c", *pnt10);
        if (i % 20 == 0)
            printf("\n");   
    }

    printHeap();
    free_pool();
}

void test3() {
    create_pool(1000);
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);

    my_free(p3);

    my_malloc(210);
    
    my_malloc(150);
    printHeap();
    my_malloc(60);
    my_malloc(50);

    free_pool();

    // printHeap();
}

void test2() {
    create_pool(1000);
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(50);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(300);
    void *p5 = my_malloc(250);
    
    my_free(p2);
    my_free(p4);
    
    void *p6 = my_malloc(50);
    void *p7 = my_malloc(200);
    void *p8 = my_malloc(100);

    printf("%p\n", p1);
    printf("p2: %p\n", p2);
    printf("%p\n", p3);
    printf("p4: %p\n", p4);
    printf("%p\n", p5);
    printf("p6: %p\n", p6);
    printf("p7: %p\n", p7);
    printf("p8: %p\n", p8);
    // printf("list: %p\n", list->address);
    printf("%d\n", currentSize);

    printHeap();
    free_pool();
}

void test1() {
    create_pool(1000);
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);

    printf("used heap: %d\n", currentSize);

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", p4);
    printf("%p\n", p5);
    
    my_free(p1);
    my_free(p2);
    my_free(p3);
    my_free(p4);
    my_free(p5);
    
    void *p6 = my_malloc(200);
    void *p7 = my_malloc(200);
    void *p8 = my_malloc(200);
    void *p9 = my_malloc(200);
    void *p0 = my_malloc(200);
    
    printf("-----------\n");
    printf("%p\n", p6);
    printf("%p\n", p7);
    printf("%p\n", p8);
    printf("%p\n", p9);
    printf("%p\n", p0);

    my_free(p6);
    my_free(p7);
    my_free(p8);
    my_free(p9);
    my_free(p0);
    
    void *p11 = my_malloc(200);
    void *p12 = my_malloc(200);
    void *p13 = my_malloc(200);
    void *p14 = my_malloc(200);
    void *p15 = my_malloc(200);
    
    printf("-----------\n");
    printf("%p\n", p11);
    printf("%p\n", p12);
    printf("%p\n", p13);
    printf("%p\n", p14);
    printf("%p\n", p15);

    free_pool();

}