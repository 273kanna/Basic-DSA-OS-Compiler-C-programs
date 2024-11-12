#include<stdio.h>
struct fcfs{
    int pid;
    int wtime;
    int tatime;
    int btime;
}p[10];
void main(){
    int n,i;
    int tottime=0,totwtime=0;
    printf("FCFS sched\n");
    printf("Enter the no of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter the burst time of the process %d: ",p[i].pid);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].tatime=p[0].btime;
    for(i=0;i<n;i++){
        p[i].wtime += p[i].btime;
        totwtime+=p[i].wtime;
        p[i].tatime=p[i].wtime+p[i].btime;
        tottime+=p[i].tatime;
    }
    printf("\nPID\tWaiting Time\t\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t\t%d\n",p[i].pid,p[i].wtime,p[i].tatime);
    }
    printf("Total Wait time: %d\n",totwtime);
    printf("Total Turnaround time: %d\n",tottime);
    printf("Average Wait time: %d\n",totwtime/n);
    printf("Average Turnaround time: %d\n",tottime/n);
}
