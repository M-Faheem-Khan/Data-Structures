// Initial Code is from: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int top; // number of elements in stack
    int capacity; // size of stack
    int* array; // array contain all the elements
};


// createStack -> Creates a stack with given size
struct Stack* createStack(int capacity) {
    // Allocating Memory for stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    // Setting top -> -1 beacuse if it does not change we know there are 0 elements in array
    stack->top = -1;
    stack->capacity = capacity;
    // Allocating Memory for integer array
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}


// isFull -> Checks if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == (stack->capacity-1);
}

// isEmpty -> Checks if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// push ->  appends object to stack
void push(struct Stack* stack, int object) {
    if (isFull(stack)) {
        printf("Unable to add object to stack!! Stack has reached capacity\n");
        return;
    }
    stack->array[++stack->top] = object;
    printf("%d has been added to stack at index %4d\n", object, stack->top);
}


// pop -> "removes" element from stack
// Elements are not being removed just number of elements(Top) is being decremented
// each call. We can't resize the array in c that is why. See python implementation
// where the array is resizable.
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Unable to remove element!! Stack has no elements\n");
        return;
    }
    printf("%d is being removed from stack\n", stack->top--);
}


// preview -> displays all fields in the stack
void preview(struct Stack* stack) {
    printf("Top: %4d\n", stack->top);
    printf("Capacity: %4d\n", stack->capacity);
    for (int i=0; i < stack->top; i++) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");

}


int main(void) {
    int stack_capacity = 20; // stack capacity
    struct Stack* stack = createStack(stack_capacity); // creating stack

    // Adding objects to stack
    for (int i=1; i<=20; i++) {
        push(stack, i);
    } 
    
    preview(stack); // view elements in stack

    // Removing Objects from stack
    for (int i=1; i<=10; i++) {
        pop(stack);
    } 

    preview(stack); // view elements in stack

	free(stack); // freeing memory
    return 0;
}
