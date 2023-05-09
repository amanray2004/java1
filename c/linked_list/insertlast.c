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

void displayll(struct node * ptr){
  while(ptr){
    printf("%d   ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}

void insertfirst(struct node * ptr,int data){
  struct node * p;
  p=(struct node*)malloc(sizeof(struct node ));
  p->data=data;
  p->next=header;
  header=p;
}

// void insertlast(struct node * ptr,int data){
//   struct node * p;
//   p=(struct node*)malloc(sizeof(struct node));
//   while(ptr!=NULL){
//     ptr=ptr->next;
//   }
//   p->data=data;
//   p->next=NULL;
//   ptr->next=p;

// }

void insertlast(struct node * ptr,int data){
  struct node * p;
  p=(struct node*)malloc(sizeof(struct node));


  if(ptr == NULL){
    header = p; // If the list is empty, make the new node the header
    return;
  }

  while(ptr->next != NULL){
    ptr=ptr->next;
  }
  p->data=data;
  p->next=NULL;
  ptr->next=p;
}

  
void insert(struct node *ptr,int pos,int data){
  int i=1;
  struct node * p;
  while(i!=pos&& ptr ){
    i++;
    ptr=ptr->next;
    
  }
  p=(struct node*)malloc(sizeof(struct node));
  p->data=data;
  p->next=ptr->next;
  ptr->next=p;
}
int main(){
  int arr[]={22,33,5,6,7,88};
  createll(arr,  5);
  displayll(header);
  insertfirst(header,3456);
  displayll(header);
  insertlast(header,4444);
  displayll(header);
  insert(header,7,34552);
  displayll(header);
}