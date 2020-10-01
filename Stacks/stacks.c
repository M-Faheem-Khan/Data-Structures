// Initial Code is from: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
#include <stdio.h> // standard io

// Struct representing Stack
struct Stack {
    int top; // last element of the stack
    int capacity; // max stack size
    int* array; // array contain all elements of the stack
};


/*
 * creatStack: Returns a new stack of a given size
 * Parameters: 
 *      int capacity: Max capacity of the Stack
 * Returns:
 *      pointer to the stack
 */
struct Stack* createStack(int capacity) {
    // Creating Stack with appropriate stack size
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    // Setting basic fields
    stack->capacity = capacity; // max capacity of stack
    stack->top = -1; // setting to -1; because if it remains unchanged the stack is empty
    // Creating an integer array of max capacity
    stack->array = (int*)malloc(stack->capacity*sizeof(int)); 
    return stack; // returning stack pointer
 }


/*
 * isFull: Checks if a given stack reached capacity
 * Parameters:
 *      (struct Stack*) stack: stack to check for fullness
 * Returns
 */
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  

/*
 * isEmpty: returns integer (0 or 1) if the stack is empty by checking if the top field has been updated
 * Parameters:
 *      (struct Stack*) stack: stack to check for emptiness
 * Returns
 *      int n: 0 or 1 depending on if the stack is empty
 */
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1;  // checking if top field is -1
} 


// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    // Checking if stack if full 
    if (isFull(stack)) {return;}

    // If stack has space
    // appending item to stack array & increment top feild
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); // prompt - element has been pushed successfully 
} 


// MAIN
int main(void) {
    printf("Hello World\n");
    return 0;
}
