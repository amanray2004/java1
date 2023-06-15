
#include <stdio.h>
#include <stdlib.h>

struct dnode {
  int data;
  struct dnode *lchild;
  struct dnode *rchild;
} * root;

struct node {
  struct dnode *ptr;
  struct node *next;
};

struct queue {
  struct node *head;
  struct node *tail;
};

struct node *getnode(struct dnode *ptr) {
  struct node *t = (struct node *)malloc(sizeof(struct node));
  t->ptr = ptr;
  t->next = NULL;
  return t;
}

void enqueue(struct queue *q, struct dnode *p) {
  struct node *t = getnode(p);
  if (q->head == NULL) {
    q->head = t;
    q->tail = t;
  } else {
    q->tail->next = t;
    q->tail = t;
  }
}

struct node *dequeue(struct queue *q) {
  if (q->head == NULL) {
    return NULL;
  }
  struct node *temp = q->head;
  q->head = q->head->next;
  return temp;
} // i can havw made it more efficient by just storing and returning address
  // q->head->ptr and freeing temp;

int isempty(struct queue *q) { return q->head == NULL; }

// struct tree {
//   struct dnode *root;
// } *t = NULL;

void createtree() {
  int a = 1;
  struct queue q;
  q.head = q.tail = NULL;
  root = (struct dnode *)malloc(sizeof(struct dnode));
  root->lchild = root->rchild = NULL;
  int x;
  scanf("%d", &x);
  root->data = x;
  enqueue(&q, root);
  // printf("%d",a);

  while (!isempty(&q)) {
    printf("%d \n", a);
    struct node *p = dequeue(&q);
    printf("enter lchild: ");
    scanf("%d", &x);
    if (x != -1) {
      struct dnode *ptr = (struct dnode *)malloc(sizeof(struct dnode));
      ptr->data = x;
      ptr->lchild = ptr->rchild = NULL;
      p->ptr->lchild = ptr;
      enqueue(&q, ptr);
    }
    printf("enter rchild: ");
    scanf("%d", &x);
    if (x != -1) {
      struct dnode *ptr = (struct dnode *)malloc(sizeof(struct dnode));
      ptr->data = x;
      ptr->lchild = ptr->rchild = NULL;
      p->ptr->rchild = ptr;
      enqueue(&q, ptr);
    }
    printf("%d %d ", a, p->ptr->data);
    if (p->ptr->lchild)
      printf("%d ", p->ptr->lchild->data);
    else
      printf("NULL ");
    if (p->ptr->rchild)
      printf("%d\n", p->ptr->rchild->data);
    else
      printf("NULL\n");

    a++;
  }
}

int main() {
  createtree();
  return 0;
}