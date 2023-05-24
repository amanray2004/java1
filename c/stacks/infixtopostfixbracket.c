
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char data;
  struct Node *next;
};

struct Node *createNode(char data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void push(struct Node **top, char data) {
  struct Node *newNode = createNode(data);
  newNode->next = *top;
  *top = newNode;
}

char pop(struct Node **top) {
  if (*top == NULL) {
    // Handle stack underflow error
    return '\0';
  }
  struct Node *temp = *top;
  char data = temp->data;
  *top = (*top)->next;
  free(temp);
  return data;
}

char peek(struct Node *top) {
  if (top == NULL) {
    // Handle empty stack error
    return '\0';
  }
  return top->data;
}

int isOperand(char x) {
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' ||
      x == ')') {
    return 0;
  }
  return 1;
}

int outPrecedence(char x) {
  if (x == '+' || x == '-') {
    return 1;
  } else if (x == '*' || x == '/') {
    return 3;
  } else if (x == '^') {
    return 6;
  } else if (x == '(') {
    return 7;
  } else if (x == ')') {
    return 0;
  }
  return -1;
}

int inPrecedence(char x) {
  if (x == '+' || x == '-') {
    return 2;
  } else if (x == '*' || x == '/') {
    return 4;
  } else if (x == '^') {
    return 5;
  } else if (x == '(') {
    return 0;
  }
  return -1;
}

char *convert(char *infix) {
  char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
  int i = 0, j = 0;
  struct Node *stack = NULL;

  while (infix[i] != '\0') {
    if (isOperand(infix[i])) {
      postfix[j++] = infix[i++];
    } else {
      if (stack == NULL ||
          outPrecedence(infix[i]) > inPrecedence(peek(stack))) {
        push(&stack, infix[i++]);
      } else if (outPrecedence(infix[i]) == inPrecedence(peek(stack))) {
        pop(&stack);
        i++;
      } else {
        postfix[j++] = pop(&stack);
      }
    }
  }

  while (stack != NULL) {
    postfix[j++] = pop(&stack);
  }

  postfix[j] = '\0';

  return postfix;
}

int main() {
  char infix[] = "((a+b)*c)-d^e^f";
  char *postfix = convert(infix);
  printf("Postfix Expression: %s\n", postfix);
  free(postfix);
  return 0;
}



// in the push function why are we creating double pointer why?

// In the push function, a double pointer is used because we need to update the top pointer of the stack.

// The top parameter of the push function is a pointer to a pointer to a Node struct (struct Node**). By using a double pointer, we can modify the value of the top pointer itself, not just the value of the top node.

// When a new node is pushed onto the stack, we create the node using the createNode function and assign its address to the newNode pointer. Then, newNode->next is set to the current top of the stack, and finally, *top (dereferencing the double pointer) is assigned the value of newNode, updating the top of the stack to point to the new node.

// Using a double pointer allows us to modify the top pointer in the push function and reflect the changes in the calling function, ensuring that the changes are preserved even after the push function returns.




// can we do the same using single pointer because if we are passing an address to a function then changes to the address is shown to parent address

// Yes, it is possible to achieve the same functionality using a single pointer instead of a double pointer.

// In that case, you would need to pass the address of the top pointer to the push function. The push function would take a single pointer to a Node struct (struct Node*) as a parameter.