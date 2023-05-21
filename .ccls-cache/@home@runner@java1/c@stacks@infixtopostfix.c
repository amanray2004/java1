// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   char data;
//   int prec;
//   struct node *next;
// } * top=NULL;

// int isOperator(char ch) {
//   if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//     return 1;
//   } else {
//     return 0;
//   }
// }

// void push(char x)
// {
//   struct node *t;
//   t=(struct node*)malloc(sizeof(struct node));

//  if(t==NULL)
//  printf("stack is full\n");
//  else
//  {
//  t->data=x;
//  t->next=top;
//  top=t;
//  }

// }

// void Display()
// {
//  struct node *p;
//  p=top;
//  while(p!=NULL)
//  {
//  printf("%c ",p->data);
//  p=p->next;
//  }
//  printf("\n");
// }

// char pop()
// {
//  struct node *t;
//  int x='n';

//  if(top==NULL)
//  printf("Stack is Empty\n");
//  else
//  {
//  t=top;
//  top=top->next;
//  x=t->data;
//  free(t);
//  }
//  return x;
// }

// char peektop(){
//   if (top!=NULL){
//     return (top->data);
//   }
//   return 'n';
// }

// int precedence(char a) {

//   if (isalpha(a)) {
//     a = 3;
//   }
//   else if (isdigit(a)) {
//     a = 3;
//   }
//   else if (isOperator(a)) {
//     if (a == '+' || a == '-') {
//       a = 1;
//     } else if (a == '*' || a == '/') {
//       a = 2;
//     }
//   return a;
// }}

// void infixtopostfix(char arr[], char narr[]){
//     int i=0, a = 0;
//     struct node * p;
//     while (arr[i] != '\0') {

//       a = precedence(arr[i]);
//       if(peektop()!='n'){
//         p = (struct node *)malloc(sizeof(struct node));
//         p->data=arr[i];
//         p->next=top;
//         p->prec=precedence(arr[i]);
//         top=p;
//       }
//       else{
//         p=top;
//         struct node * q;
//         if(p->prec<precedence(arr[i])){
//           q = (struct node *)malloc(sizeof(struct node));
//           q->data=arr[i];
//           q->next=p;
//           q->prec=precedence(arr[i]);
//           top=q;
//         }
//         else{
//           narr[i]=top->data;
//           p=top;
//           top=top->next;
//           free(p);
//           i++;
//           continue;

//         }
//       }
//       i++;
//     }
//   while (top != NULL) {
//     narr[i] = top->data;
//     p = top;
//     top = top->next;
//     free(p);
//     i++;
//   }

//   narr[i] = '\0';
//   }
// int main() {
//   char arr[100];
//   char narr[100];

//   printf("Enter an infix expression: ");
//   scanf("%[^\n]s", arr);

//   infixtopostfix(arr, narr);

//   printf("Postfix expression: %s\n", narr);

//   return 0;
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   char data;
//   int prec;
//   struct node *next;
// } *top = NULL;

// int isOperator(char ch) {
//   if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//     return 1;
//   } else {
//     return 0;
//   }
// }

// void push(char x) {
//   struct node *t;
//   t = (struct node *)malloc(sizeof(struct node));

//   if (t == NULL)
//     printf("stack is full\n");
//   else {
//     t->data = x;
//     t->next = top;
//     top = t;
//   }
// }

// void Display() {
//   struct node *p;
//   p = top;
//   while (p != NULL) {
//     printf("%c ", p->data);
//     p = p->next;
//   }
//   printf("\n");
// }

// char pop() {
//   struct node *t;
//   char x = 'n';

//   if (top == NULL)
//     printf("Stack is Empty\n");
//   else {
//     t = top;
//     top = top->next;
//     x = t->data;
//     free(t);
//   }
//   return x;
// }

// char peektop() {
//   if (top != NULL) {
//     return top->data;
//   }
//   return 'n';
// }

// int precedence(char a) {
//   if (isalpha(a) || isdigit(a)) {
//     a = 3;
//   } else if (isOperator(a)) {
//     if (a == '+' || a == '-') {
//       a = 1;
//     } else if (a == '*' || a == '/') {
//       a = 2;
//     }
//   }
//   return a;
// }

// void infixtopostfix(char arr[], char narr[]) {
//   int i = 0;
//   struct node *p = NULL, *q = NULL;

//   while (arr[i] != '\0') {
//     if (peektop() != 'n') {
//       p = (struct node *)malloc(sizeof(struct node));
//       p->data = arr[i];
//       p->next = top;
//       p->prec = precedence(arr[i]);
//       top = p;
//     } else {
//       p = top;
//       if (p->prec < precedence(arr[i])) {
//         q = (struct node *)malloc(sizeof(struct node));
//         q->data = arr[i];
//         q->next = p;
//         q->prec = precedence(arr[i]);
//         top = q;
//       } else {
//         narr[i] = top->data;
//         p = top;
//         top = top->next;
//         free(p);
//         i++;
//         continue;
//       }
//     }
//     i++;
//   }

//   while (top != NULL) {
//     narr[i] = top->data;
//     p = top;
//     top = top->next;
//     free(p);
//     i++;
//   }

//   narr[i] = '\0';
// }

// int main() {
//   char arr[100];
//   char narr[100];

//   printf("Enter an infix expression: ");
//   scanf("%[^\n]s", arr);

//   infixtopostfix(arr, narr);

//   printf("Postfix expression: %s\n", narr);

//   return 0;
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   char data;
//   int prec;
//   struct node *next;
// } *top = NULL;

// int isOperator(char ch) {
//   if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//     return 1;
//   } else {
//     return 0;
//   }
// }

// void push(char x) {
//   struct node *t;
//   t = (struct node *)malloc(sizeof(struct node));

//   if (t == NULL)
//     printf("stack is full\n");
//   else {
//     t->data = x;
//     t->next = top;
//     top = t;
//   }
// }

// void Display() {
//   struct node *p;
//   p = top;
//   while (p != NULL) {
//     printf("%c ", p->data);
//     p = p->next;
//   }
//   printf("\n");
// }

// char pop() {
//   struct node *t;
//   char x = 'n';

//   if (top == NULL)
//     printf("Stack is Empty\n");
//   else {
//     t = top;
//     top = top->next;
//     x = t->data;
//     free(t);
//   }
//   return x;
// }

// char peektop() {
//   if (top != NULL) {
//     return top->data;
//   }
//   return 'n';
// }

// int precedence(char a) {
//   if (isalpha(a) || isdigit(a)) {
//     return 3;
//   } else if (isOperator(a)) {
//     if (a == '+' || a == '-') {
//       return 1;
//     } else if (a == '*' || a == '/') {
//       return 2;
//     }
//   }
//   return -1; // Invalid operator
// }

// void infixtopostfix(char arr[], char narr[]) {
//   int i = 0;
//   struct node *p = NULL, *q = NULL;

//   while (arr[i] != '\0') {
//     if (peektop() != 'n') {
//       p = (struct node *)malloc(sizeof(struct node));
//       p->data = arr[i];
//       p->next = top;
//       p->prec = precedence(arr[i]);
//       top = p;
//     } else {
//       if (top == NULL)
//         break; // Operator stack is empty, break the loop

//       p = top;
//       if (p->prec <= precedence(arr[i])) { // Modified condition
//         q = (struct node *)malloc(sizeof(struct node));
//         q->data = arr[i];
//         q->next = p;
//         q->prec = precedence(arr[i]);
//         top = q;
//       } else {
//         narr[i] = top->data;
//         p = top;
//         top = top->next;
//         free(p);
//         i++;
//         continue;
//       }
//     }
//     i++;
//   }

//   while (top != NULL) {
//     narr[i] = top->data;
//     p = top;
//     top = top->next;
//     free(p);
//     i++;
//   }

//   narr[i] = '\0';
// }

// int main() {
//   char arr[]="a+b*c-d/e";
//   char narr[100];

//   // printf("Enter an infix expression: ");
//   // scanf("%[^\n]s", arr);

//   infixtopostfix(arr, narr);

//   printf("Postfix expression: %s dd\n", narr);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
//  int prec;
  struct node *next;
} *top = NULL;

int isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
    return 1;
  } else {
    return 0;
  }
}

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

void Display() {
  struct node *p;
  p = top;
  while (p != NULL) {
    printf("%c ", p->data);
    p = p->next;
  }
  printf("\n");
}

char pop() {
  struct node *t;
  char x = 'n';

  if (top == NULL)
    printf("Stack is Empty\n");
  else {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}

char peektop() {
  if (top != NULL) {
    return top->data;
  }
  return 'n';
}

int precedence(char a) {
  if (isOperator(a)) {
    if (a == '+' || a == '-') {
      return 1;
    } else if (a == '*' || a == '/') {
      return 2;
    }
  }
  return -1; // Invalid operator
}

void infixtopostfix(char arr[], char narr[]) {
  int i = 0, j = 0;
  while (arr[i] != '\0') {
    if (isalpha(arr[i]) || isdigit(arr[i])) {
      narr[j++] = arr[i++];
    } else if (isOperator(arr[i])) {
      if (peektop() != 'n' && precedence(arr[i]) <= precedence(peektop())) {
        narr[j++] = pop();
      } else {
        push(arr[i++]);
      }
    } else {
      i++;
    }
  }
  while (top != NULL) {
    narr[j++] = pop();
  }
  narr[j] = '\0';
}

int main() {
  char arr[] = "a+b*c-d/e";
  char narr[100];

  infixtopostfix(arr, narr);

  printf("Postfix expression: %s\n", narr);

  return 0;
}
