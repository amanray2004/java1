#include <stdio.h>
#include <stdlib.h>
struct node {
  char data;
  struct node *next;
} *top = NULL;

void push(char x) {
  struct node *t;
  t = (struct node *)malloc(sizeof(struct node));

  if (t == NULL)
    printf("stack is full\n");
  else {
    t->data = x;
    t->next = top;
    top = t;
  }
}

char pop() {
  struct node *t;
  char x = 'n';
  int a;
  if (top == NULL)
    // printf("Stack is Empty\n");
    x = 'n';
  else {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}

int findingparenthesis(char arr[]) {
  int i = 0;
  char a;
  while (arr[i] != '\0') {
    if (arr[i] == '(') {
      push(arr[i]);
    }
    if (arr[i] == ')') {
      a = pop();
      if (a == 'n') {
        return 0;
      }
    }
    i++;
  }
  a = pop();
  if (a == '(') {
    return 0;
  }
  return 1;
}

int main() {
  char exp[100] = "((a*b)+(c-d))";
  // scanf("%[^\n]s", exp);
  int a = findingparenthesis(exp);
  printf("%d", a);
}
