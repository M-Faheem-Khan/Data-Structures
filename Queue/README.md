# Queues

## What are Queues?
Queues are array like data strucure but with follows a different set of rules. Stacks Insertion happens end and Deletion occur at the back end and follows the First In & First Out (`FIFO`) scheme.

## Queue Operations
### Common Stack Operations
- enqueue(object): inserts an element at the end of the queue
- dequeue(object): removes and returns the element at the front of the queue.

### Auxiliary Stack Operations  
- object front(): returns the element at the front without removing it
- integer size(): returns the number elements stored
- boolean isEmpty(): indicates wether no elements are stored

### Applications of Stacks
- Waiting lists
- Access to shared resources (e.g. printer)
- Multiprogramming (multithreading)

## Time Complexities
- Push: `O(1)`
- Pop: `O(1)`
- Front: `O(1)`
