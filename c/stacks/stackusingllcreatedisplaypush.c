
// //my code
// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//   int data;
//   struct node * next;
// };

// struct stack{
//   struct node * top;
//   int size;
//   int numberele;
// };

// void push(struct stack * st,int ele){
//   //printf("%d %d \n",st->numberele,st->size);
//   if (st->numberele>=st->size){
//     printf("stackoverflow\n");
//     return;
//   }
//   else{
//     struct node * p=(struct node*)malloc(sizeof(struct node));
//     if (st->numberele==0){
//       p->data=ele;
//       p->next=NULL;
//       st->top=p;
//     }
//     else{
//       p->data=ele;
//       p->next=st->top;
//       st->top=p;

//     }
//     st->numberele++;
//   }
// }
// void display(struct stack * st){
//   struct node * ptr;
//   ptr=st->top;
//   while(ptr){
//     printf("%d    ",ptr->data);
//     ptr=ptr->next;

//   }
//   printf("\n");
// }

// int main(){
//   struct stack st;
//   st.top=NULL;
//   st.numberele=0;
//   scanf("%d",&st.size);
//   push(&st,23);
//   push(&st,133);
//   push(&st,121);
//   display(&st);
// }

// see stack using linked list means we have to use only linked list structure
// to implement stack concept.in stack using array we had to create a structure
// stack because to implement stack usng array we need two more things in
// addition to arrays ie:size of array and top of array. you have created a
// struct stack that has no meaning. you want to use ll. so your code is wrong

// while defining struct node we are creating a global pointer top.it is not
// recommended.we should create a pointer (node type) and then pass it as an
// argument to functions in case of many stacks.but here we are dealing only
// with one so it its okay.

// sirs code

#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
} *top = NULL;
void push(int x) {
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));

  if (t == NULL)
    printf("stack is full\n");
  else {
    t->data = x;
    t->next = top;
    top = t;
  }
}
void Display() {
  struct Node *p;
  p = top;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
int main() {
  push(10);
  push(20);
  push(30);

  Display();

  // printf("%d ", pop());

  return 0;
}