#include<stdio.h>
#include<stdlib.h>

int r,p,alloc[10][10],max[10][10],need[10][10],avail[10];

void read_matrix(int a[10][10]){
int data;
printf("Enter the data you need to insert");
for(int i=0;i<p;i++){
	for(int j=0;j<r;j++){
		scanf("%d",&data);
		a[i][j]=data;
		}
	}
}

void need_calc(){
for(int i=0;i<p;i++){
	for(int j=0;j<r;j++){
		need[i][j]=max[i][j]-alloc[i][j];
		}
	}
}

void display(int a[10][10]){
	for(int i=0;i<p;i++){
		printf("\n");
		for(int j=0;j<r;j++){
			printf("%d\t",a[i][j]);
			}
	}
}


void banker(){
int i,j,k=0,finish[10],sequence[10],flag,avail[10];
for(i=0;i<p;i++){
finish[i]=0;
}
for(i=0;i<p;i++){
	flag=0;
	if(finish[i]==0){
		for(j=0;j<r;j++){
			if(need[i][j]>avail[j]){
				flag=1;
				break;
			}
		}
			if(flag==0){
				sequence[k]=i;
				k++;
				finish[i]=1;
				for(j=0;j<p;j++){
					avail[j]=avail[j]+alloc[i][j];
				}
				i=-1;
			}
		}
	}

flag=0;
for(i=0;i<p;i++){
	if(finish[i]==1){
		flag=0;
}
}
if(flag!=0){
	printf("detected deadlock");
}
else{
	printf("Safe Seqence \n");
	for(i=0;i<p;i++){
	printf("%d\t",sequence[i]); 
}
}
}
}
int main(){
printf("Enter the no of Resources\n");
scanf("%d",&r);
printf("Enter the no of Processes\n");
scanf("%d",&p);
printf("Enter the data in allocated matrix\n");
read_matrix(alloc);
printf("Enter the data in the max matrix\n");
read_matrix(max);
printf("Enter the data stored in the available matrix");
for(int i=0;i<r;i++){
	scanf("%d",&avail[i]);
}


display(alloc);
display(max);
printf("\n");
for(int i=0;i<r;i++){
	printf("%d\t",avail[i]);
}
printf("Need=Max-Allocation");
need_calc();
display(need);
banker();
}