#include<stdio.h>
#include<stdlib.h>

int cscan(int r[10],int n,int h){
    int i,j=0,index,f=0,seek;
    index=h;
    for(i=0;i<n;i++){
        if(r[i]<h){
            f=1;
        }
        if(h<r[i]){
            printf("moving from current head(%d) to %d\n",h,r[i]);
            seek=r[i]-h;
            printf("Seek time = %d\n",seek);
            h=r[i];
        }   
        if(f!=0){
            i=0;
            while(r[i]<index){
                printf("moving from current head(%d) to %d\n",h,r[i]);
                seek=abs(r[i]-h);
                printf("Seek time = %d\n",seek);
                h=r[i];
                i++;
            }
        }
    }
}
void main()
{
    int r[10],head,n,i,j,movement;
    printf("Enter the total no. of Requests: ");
    scanf("%d",&n);
    printf("\nEnter the Requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    printf("Enter the initial position of the Head: ");
    scanf("%d",&head);
    movement=cscan(r,n,head);
}