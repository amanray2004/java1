// iterative traversal

// preorder

// if(t!=null){
// print()
// push(t)
// t=t->lchild
// }

// else if (t==NULL){
// t=pop();
// t=t->rchild;
// }

#include "createtree.h"
#include <stdio.h>
#include <stdlib.h>
struct node *st = NULL;
void pushstack(struct dnode *p) {
  struct node *q = (struct node *)malloc(sizeof(struct node));
  q->ptr = p;
  q->next = st;
  st = q;
}

struct dnode *popstack() {
  if (st == NULL) {
    return NULL;
  } else {
    struct node *p = st;
    st = st->next;
    struct dnode *poppedValue = p->ptr;
    free(p);
    return poppedValue;
  }
}

int isemptyst() {
  if (st == NULL) {
    return 1;
  }
  return 0;
}

void preorderiterative(struct dnode *t) {
  // struct dnode *t = ptr;
  //  pushstack(t);
  while (t != NULL || !isemptyst()) {
    if (t != NULL) {
      printf("%d ", t->data);
      pushstack(t);
      t = t->lchild;
    }

    else if (t == NULL) {
      t = popstack();
      t = t->rchild;
    }
  }
}
int main(void) {
  createtree();
  preorderiterative(root);
  return 0;
}
