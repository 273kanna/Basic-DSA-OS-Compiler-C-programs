#include<stdio.h>
#include<stdlib.h>

int temp[10];
int k=0;
void merge(int a[10],int left,int mid,int right){
    int i,j;
    i=left,j=mid+1;
    while(i<=mid&&j<=right){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
     }
     while(i<=mid){
        temp[k++]=a[i++];
     }
    while(j<=right){
        temp[k++]=a[j++];
     }
}
//$$unbreakable
void mergesort(int a[10],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void printarray(int size,int a[10]){
    for(int i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
}

int main(){
    int a[10]={1,32,4,5,64,7,8,9,23};
    printarray(9,a);
    int left,right;
    left=0;
    right=8;
    mergesort(a,left,right);
    printf("Sorted array is");
    printarray(9,temp);
    return 0;
}