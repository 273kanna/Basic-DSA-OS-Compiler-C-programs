#include<stdio.h>
#include<string.h>
#include<Stdlib.h>
int main(void)
{
    char s1[20],s2[20];
    FILE *macro,*minput,*moutput;
    int flag=0;
    macro=fopen("macro.txt","r");
    minput=fopen("minput.txt","r");
    moutput=fopen("moutput.txt","w");
    while(fscanf(minput,"%s%s",s1,s2)>0)
    {
        if(strcmp(s2,"**")==0 && strcmp(s1,"END"))
        {
            char m1[20],m2[20];
            while(fscanf(macro,"%s%s",m1,m2)>0)
            {
                if(strcmp(m1,"MACRO")==0 & strcmp(m2,s1)==0)
                {
                    flag=1;
                    continue;
                }
                else if(strcmp(m1,"MEND")==0)
                {
                    flag=0;
                    break;
                }
                if(flag==1)
                {
                    fprintf(moutput,"%s%s\n",m1,m2);
                }
            }
        }
        else
        {
            fprintf(moutput,"%s%s\n",s1,s2);
        }
    }
    fclose(macro);
    fclose(minput);
    fclose(moutput);
}