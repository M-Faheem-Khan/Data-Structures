// Queues: Implementation of Queues in C
#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size; // number of elements in queue
    int capacity; // max capacity of queue
    int* array; // containing the elements
};


/*
 * createQueue(int capacity): creates an queue
 * Parameters: int capacity -> capacity of the queue 
 * Returns: pointer to queue struct
 */
struct Queue* createQueue(int capacity){
    // Creating Queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = -1; // there are no elements in queue upon init.
    // setting capacity
    queue->capacity = capacity;
    // Allocating memory for queue(array)
    queue->array = (int*)malloc(capacity * sizeof(int)); 
    return queue; // returning queue
}


/*
 * isFull(struct Queue*): returns if the queue is full
 * Parameters: struct Queue* -> queue to check for capacity
 * Returns: the number of elements in queue
 */
int isFull(struct Queue* queue) {
    return queue->size == queue->capacity-1;
}


/*
 * IsEmpty(struct Queue*): returns if the queue is empty
 * Parameters: struct Queue* -> queue to check for emptyness
 * Returns: if the queue is empty
 */
int isEmpty(struct Queue* queue) {
    return queue->size == -1;
}


/*
 * enqueue(struct Queue*): adds elements to the queue
 * Parameters: struct Queue* -> queue to add the element to
 * Returns: NONE
 */
void enqueue(struct Queue* queue, int object) {
    if (isFull(queue)) {
        printf("Unable to append to queue!! Queue has reached capacity!\n");
        return;
    }
    // Insert at the end of the array
    queue->array[++queue->size] = object;
}

/*
 * dequeue(struct Queue*): removes the first element from the queue
 * Parameters: struct Queue* -> queue to remove the first element from
 * Returns: first element in queue
 */
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Unable to dequeue elements. There are no elements in queue!\n ");
    }

    // temporarily storing the element at index 0 - we have to return this value
    int elem = queue->array[0]; 
    // removing the element at the end of the queue
    // Shift all the elements by one order one by one
    for (int i=1; i < queue->size; i++) {
        queue->array[i-1] = queue->array[i];
    }
    queue->size--; // decrement the size
    return elem;
}


/*
 * front(struct Queue*): returns the first element in the queue
 * Parameters: struct Queue* -> queue to get the first element from
 * Returns: first element in queue
 */
int front(struct Queue* queue) {
    return queue->array[0];
}


/*
 * preview(struct Queue*): prints the all the fields in the queue
 * Parameters: struct Queue* -> queue to preview
 * Returns: NONE 
 */
void preview(struct Queue* queue) {
    printf("Size: %4d\n", queue->size);
    printf("Capacity: %4d\n", queue->capacity);
    for (int j=0; j < queue->size; j++){
        printf("%d, ", queue->array[j]);
    }
    printf("\n");
}


// Driver Code
int main(void) {
    int queue_size = 20;
    struct Queue* queue = createQueue(20); // creating queue
    
    // enqueuing: Adding elements to queue
    for (int i=2; i < queue_size; i++) {
        enqueue(queue, i*8);
    }

    preview(queue); // previewing queue


    // dequeuing: Removing elements from queue
    for (int i=0; i<3; i++) {
        dequeue(queue);
    } 

    preview(queue); // previewing queue

    return 0;
}


// EOF
