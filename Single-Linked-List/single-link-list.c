#include<stdio.h>
#include<stdlib.h>

// Node Struct
struct Node {
	int data; // holds data in this case an integer
    struct Node* next; // pointer to the next node
};


// Sets fields of a the first Node and sets the pointer to the next node
void setNodeFields(struct Node* node1, int data, struct Node* node2) {
	node1->data = data;
	node1->next = node2;
}


// Driver Code
int main(void) {
	printf("Single-Linked-List\n");
	// Creating Nodes and Allocating Space for each node
	struct Node* first = (struct Node*)malloc(sizeof(struct Node));
	struct Node* second = (struct Node*)malloc(sizeof(struct Node));
	struct Node* third = (struct Node*)malloc(sizeof(struct Node));

	// Setting Data
	setNodeFields(first, 1, second);
	setNodeFields(second, 2, third);
	setNodeFields(third, 3, NULL);
	
	// Freeing memory to prevent memory leak
	free(first);
	free(second);
	free(third);
	
	return 0;
}