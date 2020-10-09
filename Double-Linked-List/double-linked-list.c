#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data; // holds data in this case integer
    struct Node* prev; // pointer to previous node
    struct Node* next; // pointer to next node
};


// Sets fields of a the first Node and sets the pointer to the previous and next node
// setNodeFields(NODE_TO_SET_FEILDS_OF, DATA, POINTER_TO_PREVIOUS_NODE, POINTER_TO_NEXT_NODE);
void setNodeFields(struct Node* node, int data, struct Node* prev, struct Node* next) {
	node->data = data;
    node->prev = prev; // setting pointer to the previous node
	node->next = next; // setting pointer to the next node
}


// Driver Code
int main(void) {
	printf("Double-Linked-List\n");
	// Creating Nodes and Allocating Space for each node
	struct Node* first = (struct Node*)malloc(sizeof(struct Node));
	struct Node* second = (struct Node*)malloc(sizeof(struct Node));
	struct Node* third = (struct Node*)malloc(sizeof(struct Node));

	// Setting Data
	setNodeFields(first, 1, NULL, second);
	setNodeFields(second, 2, first, third);
	setNodeFields(third, 3, second, NULL);

    // Freeing memory to prevent memory leak
	free(first);
	free(second);
	free(third);

    return 0;
}