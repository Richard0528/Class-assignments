// TCSS 333 - assignment5
// Zhihao Yang

#include <stdio.h>
#include <string.h>

#define STUFF_NAM_LEN 15
#define NAM_LEN 15
#define MAX_ITEM 10


// data structure defined
struct stuff {
	char name[STUFF_NAM_LEN];
	int number;
	float price;
};
typedef struct stuff myStuff;

struct customer {
	char name[NAM_LEN];
	myStuff item[MAX_ITEM];
	int total;
	float totalcost;
};
typedef struct customer Customer;

// Function prototypes
void createCustomersStuff(Customer [], int);
void createCustomersStuff2(Customer [], int);
void makeCustomersStable(Customer [], int);
int getCustomerStuff(FILE *, Customer []);
void bubbleSort2Customer(Customer [], int);
void bubbleSort2ItemsOnValue(myStuff [], int);

int main(void) {
	int total, i;
	Customer customer[10];
	makeCustomersStable(customer, 10);

	FILE *infile = fopen("hw5input.txt", "r");
	total = getCustomerStuff(infile, customer);
	fclose(infile);
	createCustomersStuff(customer, total);
	bubbleSort2Customer(customer, total);
	for (i = 0; i < total; i++) {
		bubbleSort2ItemsOnValue(customer[i].item, customer[i].total);
	}
	createCustomersStuff2(customer, total);
	return 0;
}

/******************************************************************************
 * Use Bubble Sort 2 AssetCount to sort the array of Customer(sorts based on 
 * total value a customer owns):
 */
void bubbleSort2Customer(Customer cust[], int size) {
	Customer s;
	int topBubble, bubbles, notSorted = 1;
	for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
		for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
			if (cust[bubbles].totalcost > cust[bubbles - 1].totalcost) {
        		s = cust[bubbles];
        		cust[bubbles] = cust[bubbles - 1];
        		cust[bubbles - 1] = s;
        		notSorted = 1;
      		}
    	}
}

/******************************************************************************
 * Use Bubble Sort 2 AssetsOnWeight to sort arrays myStuff (sorts the array
 * of myStuff or items owned by a student):
 */
void bubbleSort2ItemsOnValue(myStuff itm[], int size) {
	myStuff s;
	int topBubble, bubbles, notSorted = 1;
	for (topBubble = 0; topBubble < size - 1 && notSorted; topBubble++)
		for (bubbles = size - 1, notSorted = 0; bubbles > topBubble; bubbles--) {
			float totalvalue1 = (float)itm[bubbles].price * (float)itm[bubbles].number;
			float totalvalue2 = (float)itm[bubbles - 1].price * (float)itm[bubbles - 1].number;
      		if ((int) (totalvalue1 * 100) > (int) (totalvalue2 * 100)) {
        		s = itm[bubbles];
        		itm[bubbles] = itm[bubbles - 1];
        		itm[bubbles - 1] = s;
        		notSorted = 1;
      		}
    	}
}

/******************************************************************************
 * Display the Customers' data: version 1
 */
void createCustomersStuff(Customer cust[], int size) {
	FILE *outfile = fopen("hw5time.txt", "w");
	int i, j;
	for (i = 0; i < size; i++) {
	    fprintf(outfile, "Customer: %s \r\n", cust[i].name);
	    fprintf(outfile, "        Orders:\r\n");
	    for (j = 0; j < cust[i].total; j++) {
	        fprintf(outfile, "                %-9s %9d %10.2f %10.2f\r\n", cust[i].item[j].name, 
	        	cust[i].item[j].number, cust[i].item[j].price, 
	        	(float)cust[i].item[j].number * (float)cust[i].item[j].price);

	    }
	    fprintf(outfile, "                                          Total:%9.2f\r\n", cust[i].totalcost);
    }
    fclose(outfile);
}

/******************************************************************************
 * Display the Customers' data: version 2
 */
void createCustomersStuff2(Customer cust[], int size) {
	FILE *outfile = fopen("hw5money.txt", "w");
	int i, j;
	for (i = 0; i < size; i++) {
	    fprintf(outfile, "%s, Total Order = $%.2f \r\n", cust[i].name, cust[i].totalcost);
	    float overall = 0;
	    for (j = 0; j < cust[i].total; j++) {
	    	overall += (float)cust[i].item[j].number * (float)cust[i].item[j].price;
			// printf("total value =%f\n", overall);
	        fprintf(outfile, "%s %d $%.2f, Item Value =  $%.2f\r\n", cust[i].item[j].name,
	        	cust[i].item[j].number, cust[i].item[j].price, 
	        	(float)cust[i].item[j].number * (float)cust[i].item[j].price);
	    }
    }
    fclose(outfile);
}

/******************************************************************************
 * Read in the customers' data:
 */
int getCustomerStuff(FILE *fn, Customer cust[]) {
	char custName[NAM_LEN], stuffName[STUFF_NAM_LEN];
	int i, count = 0, num = 0;
	float price;

	while (count < 10 && fscanf(fn, "%s %d %s %*c%f", custName, &num, stuffName, &price) != EOF) {
		for (i = 0; i < count && strcmp(custName, cust[i].name); i++);
		if (i == count)
			count++;
		strcpy(cust[i].name, custName);
		cust[i].item[cust[i].total].number = num;
		strcpy(cust[i].item[cust[i].total].name, stuffName);
		cust[i].item[cust[i].total].price = price;
		cust[i].totalcost += num * price;
		cust[i].total++;
		// printf("%d\n", cust[i].total);
	}

	return count;
}

/******************************************************************************
 * Assures that the total field of each customer struct is set to 0.
 */
void makeCustomersStable(Customer cust[], int size) {
	int i, j;
	for (i = 0; i < size; i++) 
		cust[i].total = 0;
}



