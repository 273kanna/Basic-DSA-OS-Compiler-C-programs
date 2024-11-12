#include<stdio.h>

int main(){
    int n,m,i,j,alloc[10][10],max[10][10],avail[10];
    printf("enter the no. of process :");
    scanf("%d",&n);
    printf("enter the no. of resources :");
    scanf("%d",&m);

    printf("enter the allocation matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("enter the max matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("enter the available values\n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }

    int finish[10],need[10][10],work[10],safesequence[10],c=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("need matrix is :\n");
    for(i=0;i<n;i++){
            printf("\n");
        for(j=0;j<m;j++){
            printf("%d  ",need[i][j]);
        }
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    for(i=0;i<m;i++){
        work[i]=avail[i];
    }

    for(int k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(work[j]<need[i][j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safesequence[c]=i;
                    c++;
                    for(int y=0;y<m;y++){
                        work[y] += alloc[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }

    printf("\n\nsafe sequence is :");
    for(i=0;i<n;i++){
        printf("P%d",safesequence[i]+1);
        if(i!=n-1)
            printf("->");
    }
    printf("\n");
    return 0;
}

