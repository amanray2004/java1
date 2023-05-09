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


void removeduplicatesll(struct node * ptr){
  struct node *p,*q;
  q=ptr->next;
  while(ptr->next){
    if(ptr->data==q->data){
      ptr->next=q->next;
      free(q);
      q=p->next;
    }
    else{
      ptr=ptr->next;
      q=q->next;
    }
  }
}

void displayll(struct node * ptr){
  while(ptr){
    printf("%d  ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}


int main(){
  int arr[]={1,2,5,6,6,7,7,8,9,9};
  createll(arr,  10);
  displayll(header);
  removeduplicatesll(header);
  displayll(header);
  
}