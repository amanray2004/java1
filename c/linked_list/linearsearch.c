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

int linearSearch(struct node *ptr, int target) {
  struct node *current = ptr;
  int index = 0;

  while (current != NULL) {
    if (current->data == target) {
      return index;
    }
    current = current->next;
    index++;
  }

  return -1;
}

struct node *rlinearsearch(struct node *ptr, int target) {
  if (ptr == NULL) {
    return NULL;
  }
  if (target == ptr->data) {
    return ptr;
  }
  return rlinearsearch(ptr->next, target);
}
