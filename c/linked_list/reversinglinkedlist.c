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
  
  
  void reveseusingusingpointer(struct node* ptr) {
    struct node *p, *q, *r;
    p = NULL;
    q = ptr;
    r = ptr->next;
    q->next = NULL;

    while (r != NULL) {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }

    header = q; // Updating the header to the new first node (previously the last node)
}


void displayll(struct node * ptr){
  while(ptr){
    printf("%d  ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}

int main(){
  int arr[]={2,3,4,5,666,7,88,9};
  createll(arr, 8);
  displayll(header);
  reveseusingusingpointer(header);
  displayll(header);
}









//mycode

// void reveseusingusingpointer(struct node * ptr){
//   struct node *p,*q,*r;
//   p=ptr;
//   q=ptr->next;
//   r=ptr->next->next;
//   p->next=NULL;
//   while(r->next){
//     q->next=p;
//     p=q;
//     q=r;
//     r=r->next;
    
//   }
//   q->next=p;
//   r->next=q;
//   header=r;
// }