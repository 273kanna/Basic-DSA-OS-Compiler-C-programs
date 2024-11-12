#include<stdio.h>
#include<stdlib.h>

struct process
{
    int at,ct,bt,wt,turn;
}p[10],t[10];
int n,q,tat,twait;

void p_print(struct process p[10]){
    printf("\nAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t\n",p[i].at,p[i].bt,p[i].wt,p[i].turn);
    }
}

void copy(int index,int des){
    t[des].at=p[index].at;
    t[des].bt=p[index].bt;
    t[des].ct=p[index].ct;
    t[des].turn=p[index].turn;
    t[des].wt=p[index].wt;
}

void merge(int low,int mid,int high){
    int i,j,k;
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=high){
        if(p[i].at<p[j].at){
            copy(i,k);
            i++;
            k++;
        }
        else{
            copy(j,k);
            j++;
            k++;
        }
    }
    while(i<=mid){
        copy(i,k);
        i++;
        k++;
    }
    while (j<=high)
    {
        copy(j,k);
        j++;
        k++;
    }
    
}

void mergesort(int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

void waiting_time(struct process p[10]){
    int i=0;
    p[i].wt=0;
    p[i].turn=p[i].bt+p[i].wt;
    tat=p[i].turn+tat;
    twait=p[i].wt+twait;
    for(i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        //turnaround = burst time + waiting time;
        p[i].turn=p[i].bt+p[i].wt;
        tat=p[i].turn+tat;
        twait=p[i].wt+twait;   
    }
}


void fcfs(){
    int i=0;
    waiting_time(p);
    p_print(p);
    printf("Average waiting time = %d/nAverage Turn around Time = %d",(twait/n),(tat/n));
}

void sjfs(){
    
}



int main(){
    printf("Enter the no of processes");
    scanf("%d",&n);
    printf("Enter the BT and AT for each processes");
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].bt,&p[i].at);
        p[i].ct=p[i].wt=p[i].turn=0;
    }
    printf("Enter the time quantum for each process\n");
    scanf("%d",&q);
    fcfs();
    mergesort(0,n);
    sjfs();
    return 0;
}