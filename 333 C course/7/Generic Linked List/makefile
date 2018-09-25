MyList: LLDriver.o LLMergeSort.o myData.o LinkedList.o
	gcc -o MyList LLDriver.o LLMergesort.o myData.o LinkedList.o

LLDriver.o: LLDriver.c LinkedList.h LLMergeSort.h myData.h
	gcc -c LLDriver.c

LLMergeSort.o: LLMergeSort.c LLMergeSort.h LinkedList.h
	gcc -c LLMergeSort.c

myData.o: myData.c myData.h LinkedList.h
	gcc -c myData.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c