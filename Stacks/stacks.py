class Stack:
    def __init__(self, capacity: int):
        '''
        createStack: Creates an empty stack
        Parameters: capacity(int) -> size of stack
        '''
        self.top = -1
        self.capacity = capacity
        self.stack = []
        print("Stack has been created")

    # adding object to stack
    def push(self, object: int):
        if self.top < self.capacity:
            self.stack.append(object)
            print(f"{object} has been added to stack at index {self.top}")
            self.top = self.top + 1
        else:
            print(f"Unable to add to stack!! Stack has reach capacity: {self.capacity}")
    
    def pop(self):
        if self.top != 0:
            self.top -= 1 # decrementing the number elements in stack by 1
            print(f"{self.stack[self.top]} has been removed from stack at index {self.top}")
            self.stack = self.stack[: self.top] # resizing the array
        else:
            print("There are no elements in stack")

    def preview(self):
        print("Top: %d" % self.top)
        print("Capacity: %d" % self.capacity)
        for i in range(self.top):
            print("%d, " % self.stack[i], end="")
        print()


def main():
    stack = Stack(10) # creating a new stack
    # add objects to stack
    for i in range(10):
        stack.push(i+1)
    
    stack.preview() # stack info

    # removing objects from stack
    for i in range(4):
        stack.pop()
        
    stack.preview() # stack info

    # deleting stack
    del stack 

if __name__ == "__main__":
    main()
