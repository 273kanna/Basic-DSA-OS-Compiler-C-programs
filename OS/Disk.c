#include<stdio.h>
#include<stdlib.h>

int sort[10];

int fifo(int r[10],int n,int in,int s){
    int m=0;
    for(int i=0;i<n;i++){
        printf("%d->",in);
        m=m+abs(r[i]-in);
        in=r[i];
    }
    return m;
}

void merge(int a[10],int left,int mid,int right){
    int i,j,k;
    i=left;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=right){
        if(a[i]<a[j])
            sort[k++]=a[i++];
        else
            sort[k++]=a[j++];
    }
    while(i<=mid){
        sort[k++]=a[i++];
    }
    while(j<=right){
        sort[k++]=a[j++];
    }
}

void mergesort(int a[10],int left,int right){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void list(int a[10],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

int scan(int r[10],int n,int in,int s){
    int m,d,i,max,min,flag,begin;
    m=0;
    max=r[n];
    min=r[0];
    for(i=0;i<n+1;i++){
        if(r[i]==in)
            break;
    }
    printf("Enter The direction of scan\n1 For low to high\n0 for high to low");
    scanf("%d",&d);
    if(d==1){
        if(min<in){
            flag=1;
        }
        for(;i<n;i++){
            m=abs(r[i]-in)+m;
            in=r[i];
        }
        if(flag){
            m=m+abs(in-min);
        }
    }
    else{
        if(max>in){
            flag=1;
        }
        for(;i>=0;i--){
            m=m+abs(in-r[i]);
            in=r[i];
        }
        if(flag){
            m=m+abs(in-max);
        }
    }
    return m;
}

void bubblesort(int a[10],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
             temp=a[j+1];
             a[j+1]=a[j];
             a[j]=temp;  
            }
        }
    }
}

int cscan(int r[10],int n,int s,int in){
    int begin,i,min,max,max_flag,min_flag,movement,m,l;
    for(i=0;i<n+1;i++){
        if(r[i]==in){
            break;
        }
    }
    begin=i;
    if(max>r[begin])
        max_flag=1;
    if(min<r[begin])
        min_flag=1;

    movement=1;
    m=0;
    if(movement){
        for(i=begin;i<n;i++){
            m=m+abs(r[begin+1]-r[begin]);

            if(min_flag==1&&i==n-1){
                i=0;
                m=m+s;
                in=0;
                l=0;
            }
            if(l==0&&i==begin-1||min_flag==0&&i==n){
                break;
            }
        }
    }
    return m;
}


int main(){
    int r[10],i,n,init,s,movement,ad;
    printf("Enter the no of requests :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    printf("Enter the Initial position of head");
    scanf("%d",&init);
    printf("Enter the total size of the disk");
    scanf("%d",&s);
    movement=fifo(r,n,init,s);
    printf("Average Head Movement for FIFO is %d\n",(movement/n));
    r[n]=init;
    bubblesort(r,n+1);
    list(r,n+1);
    movement=scan(r,n,init,s);
    printf("Average head movement is %d for SCAN \n",(movement/n));
    movement=cscan(r,n,s,init);
    printf("%d is the average head movement for cscan ",(movement/n));
    return 0;
}