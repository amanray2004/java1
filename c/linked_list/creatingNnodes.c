

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

void createll(struct node *ptr, int arr[], int n) {
  struct node *p, *q;
  ptr->data = arr[0];
  ptr->next = NULL;
  q = ptr;
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
    for (j = 0; j < 3; j++) { // Corrected loop index
      printf("Element %d: ", j);
      scanf("%d", &arr1[j]); // Corrected array index
    }
    createll(arr[i], arr1, 3);
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

int main() {
  struct node *arr[2];
  createNptr(arr, 2);
  createNnode(arr, 2);
  displaylls(arr);
  return 0;
}
