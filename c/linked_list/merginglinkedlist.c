

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   int data;
//   struct node *next;
// };

// void createNptr(struct node *arr[], int n) {
//   int i;
//   struct node *ptr;
//   for (i = 0; i < n; i++) {
//     ptr = (struct node *)malloc(sizeof(struct node));
//     arr[i] = ptr;
//     ptr->next = NULL; // Set next pointer to NULL
//   }
// }

// void createll(struct node *ptr, int arr[], int n) {
//   struct node *p, *q;
//   ptr->data = arr[0];
//   ptr->next = NULL;
//   q = ptr;
//   for (int i = 1; i < n; i++) {
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data = arr[i];
//     q->next = p;
//     q = p;
//   }
//   q->next = NULL;
// }

// void createNnode(struct node *arr[], int n) {
//   int i, j;
//   int arr1[3];
//   for (i = 0; i < n; i++) {
//     printf("Enter elements in the array:\n");
//     for (j = 0; j < 3; j++) { // Corrected loop index
//       printf("Element %d: ", j);
//       scanf("%d", &arr1[j]); // Corrected array index
//     }
//     createll(arr[i], arr1, 3);
//   }
// }

// void displaylls(struct node *arr[]) {
//   struct node *ptr;
//   for (int i = 0; i < 2; i++) {
//     ptr = arr[i];
//     while (ptr) {
//       printf("%d     ", ptr->data);
//       ptr = ptr->next;
//     }
//     printf("\n");
//   }
// }

// struct node * mergelinkedlist(struct node * p,struct node * q){
//   struct node * first,* last;
//   if(q->data<p->data){
//     first=q;
//     last=q;
//     q=q->next;
      
//   }
//   else{
//     first=p;
//     last=q;
//     q=q->next;
    
//   }
//   while(p->next && q->next){
//     if(q->data<p->data){
//       last->next=NULL;
//       last=q;
//       q->next=q;
//       last->next=NULL;
//     }
//     else{
//       last->next=NULL;
//       last=p;
//       p->next=p;
//       last->next=NULL;
//     }
//   }
//  if(p)last->next=p;
//  if(q)last->next=q;
  
//   return first;
// }
// void displayll(struct node * ptr){
//   while(ptr){
//     printf("%d  ",ptr->data);
//     ptr=ptr->next;
//   }
// }

// int main() {
//   struct node *arr[2];
//   createNptr(arr, 2);
//   createNnode(arr, 2);
//   displaylls(arr);
//   struct node * a;
//   a=mergelinkedlist(arr[0], arr[1]);
//   displayll(a);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void createNptr(struct node *arr[], int n) {
  int i;
  struct node *ptr;
  for (i = 0; i < n; i++) {
    ptr = (struct node *)malloc(sizeof(struct node));
    arr[i] = ptr;
    ptr->next = NULL; // Set next pointer to NULL
  }
}

void createll(struct node **ptr, int arr[], int n) {
  struct node *p, *q;
  *ptr = (struct node *)malloc(sizeof(struct node));
  (*ptr)->data = arr[0];
  (*ptr)->next = NULL;
  q = *ptr;
  for (int i = 1; i < n; i++) {
    p = (struct node *)malloc(sizeof(struct node));
    p->data = arr[i];
    q->next = p;
    q = p;
  }
  q->next = NULL;
}

void createNnode(struct node *arr[], int n) {
  int i, j;
  int arr1[3];
  for (i = 0; i < n; i++) {
    printf("Enter elements in the array:\n");
    for (j = 0; j < 3; j++) {
      printf("Element %d: ", j);
      scanf("%d", &arr1[j]);
    }
    createll(&arr[i], arr1, 3);
  }
}

void displaylls(struct node *arr[]) {
  struct node *ptr;
  for (int i = 0; i < 2; i++) {
    ptr = arr[i];
    while (ptr) {
      printf("%d     ", ptr->data);
      ptr = ptr->next;
    }
    printf("\n");
  }
}

struct node *mergelinkedlist(struct node *p, struct node *q) {
  struct node *first, *last;

  if (p->data < q->data) {
    first = p;
    last = p;
    p = p->next;
  } else {
    first = q;
    last = q;
    q = q->next;
  }

  while (p != NULL && q != NULL) {
    if (p->data < q->data) {
      last->next = p;
      last = p;
      p = p->next;
    } else {
      last->next = q;
      last = q;
      q = q->next;
    }
  }

  if (p == NULL)
    last->next = q;
  else
    last->next = p;

  return first;
}

void displayll(struct node *ptr) {
  while (ptr) {
    printf("%d  ", ptr->data);
    ptr = ptr->next;
  }
}

int main() {
  struct node *arr[2];
  createNptr(arr, 2);
  createNnode(arr, 2);
  displaylls(arr);
  struct node *a;
  a = mergelinkedlist(arr[0], arr[1]);
  displayll(a);
  return 0;
}
