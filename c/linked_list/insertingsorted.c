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

void insertinsortedll(struct node *ptr, int element) {
  struct node *p, *q;
  p = (struct node *)malloc(sizeof(struct node));
  p->data = element;
  if (ptr->data > element) {
    p->next = ptr;
    header = p;
  } else {
    ptr = ptr->next;
    q = NULL;
    while (ptr && ptr->data < element) {
      q = ptr;
      ptr = ptr->next;
    }
    p->next = ptr;
    q->next = p;
  }
}
void displayll(struct node *ptr) {
  while (ptr) {
    printf("%d  ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 4, 55, 78, 667};
  createll(arr, 5);
  displayll(header);
  insertinsortedll(header, 668);
  displayll(header);
}