#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *fp;
    int i,addr1,j,staddr1;
    char name[10],line[50],ch,name1[10],addr[10],staddr[10];
    printf("Enter your program name: ");
    scanf("%s",name);
    fp=fopen("objectcode.txt","r");
    fscanf(fp,"%s",line);
    for(i=2,j=0;i<8,j<6;i++,j++)
        name1[j]=line[i];
    name[j]="\0";
    printf("Name from Objectcode : %s\n",name1);
    if(strcmp(name,name1)==0){
        fscanf(fp,"%s",line);
        do{
            if(line[0]='T'){
                for(i=2,j=0;i<8,j<6;i++,j++)
                    staddr[j]=line[i];
                staddr[j]='\0';
                staddr1=atoi(staddr);
                i=12;
                while(line[i]!='$')
                {
                    if(line[i]!='^');
                }

            }
        }
    }
}