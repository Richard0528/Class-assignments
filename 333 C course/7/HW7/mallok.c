// TCSS 333 - assignment6
// Zhihao Yang

#include "mallok.h"

void create_pool(int size) {
	if (totalSize == 0) {
		heap = (void *)malloc(size);
		if (heap != NULL) {
			// initial the linkedlist for the heap
			Node *newNode = malloc(sizeof(Node));
		    newNode->address = heap;
		    newNode->size = size;
		    newNode->free = 1;
		    newNode->next = NULL;
		    list = newNode;
			totalSize = size;
		} else {
			printf("Unable to malloc heap!\n");
		}
	} else {
		printf("Please free the existing heap!\n");
	}
}

void *my_malloc(int size) {
	if (currentSize + size <= totalSize && heap != NULL) {
		void *temp = heap;
		Node *scan = list;
		Node *back = NULL;
	
		// search for the node that is freed and has enough size
		while (scan->next != NULL && ((scan->free == 0) || (scan->size < size))) {
			// printf("Success\n");
			back = scan;
			scan = scan->next;
		}
		// double check the scan is available or not
		if (scan->free == 1 && scan->size >= size) {
			// printf("\n");
			temp = scan->address;
			// insert a new node
		    Node *newNode = malloc(sizeof(Node));
		    newNode->address = temp;
		    newNode->size = size;
		    newNode->free = 0;
		    newNode->next = NULL;

		    // printf("scanSize: %d, Size: %d\n", scan->size, size);
		    if (scan == list) {
		    	// insert for the very first time
		    	scan->address = temp + size;
		    	scan->size = scan->size - size;
		    	newNode->next = list;
		    	list = newNode;

		    } else if (scan->size == size) {

		    	scan->free = 0;
		    	free(newNode);
		    } else {

		    	// insert the node
		    	newNode->next = scan;
			    back->next = newNode;
			    // adjust the memory address and size for scan
		    	scan->address = temp + size;
			    scan->size = scan->size - size;
			    
		    }
			currentSize += size;
			// printf("%d\n", currentSize);

			return temp;
		} else {
			printf("No space available!\n");
			return NULL;
		}
	} else {
		if (heap == NULL) {
			printf("Heap does not exist!\n");
			return NULL;
		} else {
			printf("Memory exceeded!\n");
			return NULL;
		}
	}

}

void my_free(void *block) {
	if (block != NULL) {
		Node *temp = list;
		Node *back = NULL;

		while (temp->address != block) {
			back = temp;
			temp = temp->next;
		}
		temp->free = 1;
		currentSize -= temp->size;
		Node *prior = temp->next;

		if (prior != NULL && prior->free == 1) {
			temp->size = temp->size + prior->size;
			// back = temp->next;
			temp->next = prior->next;
			free(prior);
			// printf("EOEO\n");
		}


		if (back != NULL && back->free == 1) {
			back->size = back->size + temp->size;
			back->next = temp->next;
			free(temp);
			// printf("WOWO\n");
		}
		

	}

}

void free_pool() {
	freeList(list);
	free(heap);
	heap = NULL;
	list = NULL;
	totalSize = 0;
	currentSize = 0;
}

/////////////////////////////////////////////////////
// linked list

void freeList(List *list) {
    if (list) {
        freeList(list->next);
        if (list != NULL)
            free(list);
  	    list = NULL;
    }
    // printf("Freed\n");
}



