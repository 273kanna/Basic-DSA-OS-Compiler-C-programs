#include <stdio.h>
struct fcfs{
	int pid;	
	int wtime;
	int ttime;
	int btime;
}p[10];
void main(){
	int n,i;
	int totttime=0,totwtime=0;
	printf("FCFS SCHEDULING\n");
	printf("Enter the process");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Enter the burst time of the process %d\t ",p[i].pid );
		scanf("%d",&p[i].btime);
	}
	p[0].wtime=0;
	p[0].ttime=p[0].btime;
	for(i=0;i<n;i++){
		p[i].wtime=p[i-1].wtime+p[i-1].btime;
		totwtime+=p[i].wtime;
		p[i].ttime=p[i].wtime+p[i].btime;
		totttime+=p[i].ttime;
	}
	printf("process\twaiting time\tturnaround time\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t\t%d\n",p[i].pid,p[i].wtime,p[i].ttime);
	}

	printf("Total waiting time:%d\n",totwtime);
	printf("Average waiting time:%d\n",totwtime/n);
	printf("Total turn around time:%d\n",totttime);
	printf("Average turn around time:%d\n",totttime/n);
}
