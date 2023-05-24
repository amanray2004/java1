
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
