#include<stdio.h>
#include<stdlib.h>

void calc_need(int n[10][10],int m[10][10],int a[10][10],int p,int r){
    int i,j,k=0;
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            n[i][j]=m[i][j]-a[i][j];
        }
    }
}

int seq[10];

void safe(int n[10][10],int m[10][10],int a[10][10],int res[10][10],int p,int r){
    int i,j,k;
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            if(nedd[i][j]<)
        }
    }
}

int main(){
    int j,alloc[10][10],resource[10],need[10][10],max[10][10],avail[10],p,r,i;
    printf("Enter the no of proceses:\n");
    scanf("%d",&p);
    printf("Enter the no of resources\n");
    scanf("%d",&r);
    printf("Enter the max available instances of each resource\n");
    for(i=0;i<r;i++){
        scanf("%d",&resource[i]);
    }      
    printf("Enter the max resources need for each process \n");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the currently allocated resources to each process\n");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    calc_need(need,max,alloc,p,r);
    safe(need,max,alloc,resource,p,r);
}