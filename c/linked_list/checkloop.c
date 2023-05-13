#include <stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;
}*header=NULL;


void createll(int arr[],int n){
  struct node * p,* q;
  header=(struct node *)malloc(sizeof(struct node));
  header->data=arr[0];
  header->next=NULL;
  q=header;
  for (int i=1;i<n;i++){
    p=(struct node *)malloc(sizeof(struct node));
    p->data=arr[i];
    q->next=p;
    q=p;
    
    
  }
  q->next=NULL;
  
}

void displayll(struct node * ptr){
  while(ptr){
    printf("%d  ",ptr->data);
    ptr=ptr->next;
  }
}
void checkloop(struct node *  ptr){
  struct node * p,*q;
  p=ptr;
  q=ptr->next->next;
  while(q){
    if (p==q){
      printf("thereis loop\n");
    }
    p=p->next;
    q=q->next->next;
  }
}

int main(){
  int arr[]={1,4,55,667,78,66,77};
  createll(arr,7);
  displayll(header);
  
}