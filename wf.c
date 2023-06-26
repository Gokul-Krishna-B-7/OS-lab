#include<stdio.h>
#define max 25
void main()
{
    int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
    static int bf[max],ff[max];
    printf("\n\tMemory Management Scheme-worst  fit");
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("\nEnter the number of files:");
    scanf("%d",&nf);
    printf("\nEnter the size of blocks:\n");
    for(i=1;i<=nb;i++)
    {
         printf("block %d:",i);
         scanf("%d",&b[i]);
    }
    printf("Enter the size of the files:\n");
    for(i=1;i<=nf;i++)
    {
         printf("file %d:",i);
         scanf("%d",&f[i]);
    }
    for(i=1;i<=nf;i++)
    {
         for(j=1;j<=nb;j++)
         {
             if(bf[j]!=1)
             { 
                 temp=b[j]-f[i];
                 if(temp>=0)
                 {
                 if(highest<temp)
                 {
                 
                     ff[i]=j;
                    highest=temp;
                 }  
                 }
             }
         }
    frag[i]=highest;
    bf[ff[i]]=1;
    highest=0;
    }
    printf("\nFile no:\tFile Size:\tBlock No:\tBlock Size:\tFragment");
    for(i=1;i<=nf;i++)
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
