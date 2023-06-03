#include<stdio.h>
#include<stdlib.h>


void merge(int ls,int re,int arr[],int mid){
  int sorted[re-ls+1];
  int i=ls;
  int j =mid+1;
  int k=0;
  while(i<=mid&&j<=re){
    if (arr[i]<=arr[j]){
      sorted[k]=arr[i];
      i++;
      
    }
    else{
      sorted[k]=arr[j];
      j++;
    }
    k++;
    
  }
  while(i<=mid){
    sorted[k]=arr[i];
    i++;
    k++;
  }
  while(j<=re){
    sorted[k]=arr[j];
    j++;
    k++;
  }
  for (int x=ls;x<=re;x++){
    arr[x]=sorted[x-ls];
  }
}

void mergesort(int arr[],int ls,int re){
  int mid;
  if(ls<re){
    mid=(ls+re)/2;
    mergesort(arr,ls,mid);
    mergesort(arr,mid+1,re);
    merge(ls,re,arr,mid);
  }
}

int main(){
  int arr[]={12,3,7,8,90,8766};
  mergesort(arr,0,5);
  for(int i=0;i<6;i++){
    printf("%d   ",arr[i]);
  }
}