

#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
} *header = NULL;

void createll(int arr[], int n) {
  struct node *p, *q;
  header = (struct node *)malloc(sizeof(struct node));
  header->data = arr[0];
  header->next = NULL;
  q = header;
  for (int i = 1; i < n; i++) {
    p = (struct node *)malloc(sizeof(struct node));
    p->data = arr[i];
    q->next = p;
    q = p;
  }
  q->next = NULL;
}

void displayll(struct node *ptr) {
  while (ptr) {
    printf("%d  ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void Reverse1(struct node *p) {
  int *A, i = 0;
  struct node *q = p;

  A = (int *)malloc(sizeof(int) * 10);

  while (q != NULL) {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL) {
    q->data = A[i];
    q = q->next;
    i--;
  }
}

int main() {
  int arr[] = {1, 2, 5, 6, 6, 7, 7, 8, 9, 9};
  createll(arr, 10);
  displayll(header);
  Reverse1(header);
  displayll(header);
}
