#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char opcode[10],operand[10],mnemonic[3],code[10],label[10];
    FILE *f1,*f2,*f3,*f4;
    int locctr,start,len;
    f1=fopen("input.txt",'r');
    f2=fopen("optab.txt",'r');
    f3=fopen("symtab.txt","w");
    f4=fopen("intert.txt",'w');
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    
}
