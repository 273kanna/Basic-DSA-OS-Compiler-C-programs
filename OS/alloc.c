#include<stdio.h>
#include<stdlib.h>

int t,n;

struct memory{
    int size;
    int flag;
}temp[10];

struct processes{
    int id;
    int size;
}tem[10];


void first(struct processes a[10],struct memory m[10]){
    int i=0;
    int j=0;
    printf("Process Size      Size Of MemoryBlock\n");
    while(i<n){
        if(a[i].size<=m[j].size&&m[j].flag==0){
            printf("%d\t\t%d\n",a[i].size,m[j].size);
            m[j].flag=1;
            j=0;
            i++;
        }
        else{
            j++;
            if(j==t){
                printf("%d\tNOT Allocated\n",a[i].size);
                j=0;
                i++;
            }
        }
    }
}

int k=0;
void pmerge(struct processes a[10],int left,int mid,int right){
    int i,j;
    i=left,j=mid+1;
    while(i<=mid&&j<=right){
        if(a[i].size<a[j].size){
            tem[k++].size=a[i++].size;
            tem[k].id=a[i].id;
        }
        else{
            tem[k++].size=a[j++].size;
            tem[k].id=a[j].id;
        }
     }
     while(i<=mid){
        tem[k++].id=a[i++].id;
        tem[k].size=a[i].size;
     }
    while(j<=right){
        tem[k++].id=a[j++].id;
        tem[k].size=a[j].size;
     }
}

void pmergesort(struct processes a[10],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        pmergesort(a,left,mid);
        pmergesort(a,mid+1,right);
        pmerge(a,left,mid,right);
    }
}

void merge(struct memory p[10],int left,int mid,int right){
    int i,j;
    i=left,j=mid+1;
    while(i<=mid&&j<=right){
        if(p[i].size<p[j].size){
            temp[k++].size=p[i++].size;
            temp[k].flag=0;
    }
        else
            temp[k++].size=p[j++].size;
            temp[k].flag=0;
     }
     while(i<=mid){
        temp[k++].size=p[i++].size;
        temp[k].flag=0;
     }
    while(j<=right){
        temp[k++].size=p[j++].size;
        temp[k].flag=0;
     }
}

void mergesort(struct memory p[10],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(p,left,mid);
        mergesort(p,mid+1,right);
        merge(p,left,mid,right);
    }
}

void worstfit(struct memory m[10],struct processes p[10]){
    int i=0,j=t;
    while(i<=n){
        if(p[i].size<=m[j].size&&m[j].flag==0){
            printf("p%d=%d allocated to %d",p[i].id,p[i].size,m[j].size);
            i++;
            j=t;
        }
        else{
            j--;
            if (j==-1){
                j=t;
                i++;
            }
        }
    }
}

void bestfit(struct memory m[10],struct processes p[10]){
    int i,j;
    j=i=0;
    while (i<=n-1)
    {
        /* code */
        if(p[i].size<=m[i].size&&m[j].flag==0){
            pritnf("%d is allocated to %d \n",p[i].size,m[j].size);
            i++;
            j=0;
        }
        else{
            j++;
            if(j==t+1){
                j=0;
                printf("%d is unallocated \n",p[i].size);
                i++;
            }
        }
    }
    
}

int main(){
struct memory p[10];
printf("Enter the no of processes :\n");
scanf("%d",&n);
struct processes pro[10];
printf("Enter the size of each processes:\n");
for(int i=0;i<n;i++){
    scanf("%d",&pro[i].size);
    pro[i].id=i+1;
}
printf("Enter the no of memory blocks\n");
scanf("%d",&t);
printf("Enter the size of each blocks\n");
for(int i=0;i<t;i++){
    scanf("%d",&p[i].size);
    p[i].flag=0;
}
first(pro,p);
int left,right;
left=0;
right=n;
pmergesort(pro,left,right);
mergesort(p,left,t);
worstfit(temp,tem);
bestfit(temp,tem);
return 0;
}