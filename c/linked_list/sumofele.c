#include <stdio.h>

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


int sumll(struct node * ptr){
  int sum=0;
  while(ptr){
    sum+=ptr->data;
    ptr=ptr->next;
    
  }
  return sum;
  
}

int main(){
  int arr[]={11,2,3,4,5};
  createll(arr,5);
  int a=sumll(header);
  printf("%d",a);
}