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

// void reverseusingrecursion(struct node * ptr){
//   struct node * q;
  
//   if(ptr->next->next==NULL){
//     header=ptr->next;
//     ptr->next->next = ptr;
//     //ptr->next=NULL;
//     //return ptr;
    
//   }
//   else {
//     reverseusingrecursion(ptr->next);
//     ptr->next->next = ptr;
//     ptr->next=NULL;
//     //return ptr;
//     }
// }
void reverseusingrecursion(struct node* ptr) {
    struct node* q;

    if (ptr->next->next == NULL) {
        header = ptr;
        return;
    }
    else {
        reverseusingrecursion(ptr->next);
        ptr->next = ptr;
        ptr->next = NULL;
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
  int arr[]={1,4};
  createll(arr,2);
  displayll(header);
  reverseusingrecursion(header);
  displayll(header);
}