#include<stdio.h>
#include<stdlib.h>


void print(int p[10], int f, int hit, int fault) {
    for (int k = 0; k < f; k++) {
        if (p[k] == -1) {
            printf("- \t");
        } else {
            printf("%d \t", p[k]);
        }
    }
    printf("\nFaults: %d\nHits: %d\n", fault, hit);
}

void fifo(int n,int f,int a[10],int p[10]){
    int i,j,k,hit,fault,count;
    count=hit=fault=0;
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(p[j]==a[i]){
                hit++;
                break;
            }
        }
        if(j==f){
            p[count++]=a[i];
            fault++;
        }
        print(p,f,hit,fault);
        if(count==f){
            count=0;
        }
    }
}


void lru(int n,int f,int a[10],int p[10]){
    int count[10],next,i,j,min,hit,miss,found;
    hit=miss=next=0;
    for(i=0;i<f;i++){
        count[i]=0;
        p[i]=-1;
    }
    for(i=0;i<n;i++){
        found=0;
        for(j=0;j<f;j++){
            if(a[i]==p[j]){
                count[j]=next++;
                found=1;
                hit++;
            }
        }
        if(!found){
            if(i<f){
                p[i]=a[i];
                count[i]=next++;
                miss++;
            }   
            else{
                min=0;
                for(j=0;j<f;j++){
                    if(count[min]>count[j]){
                        min=j;
                    }
                }
                p[min]=a[i];
                count[min]=next++;
                miss++;
            }
        }
        print(p,f,hit,miss);
    }
}

int main(){
    int n,f,a[10],page[10];
    printf("Enter the no of reference string :");
    scanf("%d",&n);
    printf("\nEnter the elements in the reference string");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the no of frames in the page table");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        page[i]=-1;
    }
    printf("FIFO");
    fifo(n,f,a,page);
    printf("LRU");
    lru(n,f,a,page);
    return 0;
}