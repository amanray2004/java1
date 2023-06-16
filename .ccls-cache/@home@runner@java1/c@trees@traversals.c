#include "createtree.h"
#include <stdio.h>
#include <stdlib.h>

void preorder(struct dnode *t) {
  if (t != NULL) {
    printf("%d--", t->data);
    preorder(t->lchild);
    preorder(t->rchild);
  }
}

void postorder(struct dnode *t) {
  if (t != NULL) {
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d", t->data);
  }
}

void inorder(struct dnode *t) {
  if (t != NULL) {
    inorder(t->lchild);
    printf("%d", t->data);
    inorder(t->rchild);
  }
}

int main() {

  createtree();
  preorder(root);
}