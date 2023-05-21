#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int item = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return item;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    int n;
    printf("Enter the number of stacks to create: ");
    scanf("%d", &n);
    
    struct Stack** stacks = (struct Stack**)malloc(n * sizeof(struct Stack*));
    for (int i = 0; i < n; i++) {
        stacks[i] = createStack();
    }
    
    // Example usage
    push(stacks[0], 1);
    push(stacks[0], 2);
    push(stacks[1], 3);
    push(stacks[2], 4);
    
    printf("Top element of stack 1: %d\n", peek(stacks[0]));
    printf("Top element of stack 2: %d\n", peek(stacks[1]));
    printf("Top element of stack 3: %d\n", peek(stacks[2]));
    
    printf("Popped element from stack 1: %d\n", pop(stacks[0]));
    printf("Popped element from stack 2: %d\n", pop(stacks[1]));
    printf("Popped element from stack 3: %d\n", pop(stacks[2]));
    
    free(stacks); // Free memory
    
    return 0;
}





//struct node * * st=(struct node ** )malloc(n*sizeof(struct node *));     means that we are creating an array of pointera(of struct node type);


// what does this line mean?
// struct Stack** stacks = (struct Stack**)malloc(n * sizeof(struct Stack*));

// The line struct Stack** stacks = (struct Stack**)malloc(n * sizeof(struct Stack*)); is dynamically allocating memory for an array of pointers to struct Stack objects.

// Let's break down the line:

// struct Stack** stacks: This declares a variable stacks as a pointer to a pointer of type struct Stack. It will be used to store the memory address of the dynamically allocated array.

// malloc(n * sizeof(struct Stack*)): The malloc function is used to allocate memory dynamically. Here, it allocates memory for n elements, each of size sizeof(struct Stack*). sizeof(struct Stack*) calculates the size of a pointer to struct Stack object.

// (struct Stack**): The result of malloc is casted to (struct Stack**), which is the type of stacks. It's done to match the type of the pointer stacks.

// By using n * sizeof(struct Stack*), we allocate enough memory to store n pointers to struct Stack objects. The size of each pointer is determined by sizeof(struct Stack*). The memory allocated by malloc is contiguous, forming an array of n pointers.

// After this line, you can use the stacks variable to access and manipulate the array of pointers to struct Stack objects.