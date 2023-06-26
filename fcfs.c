#include<stdio.h>
int main()
{
 int i,j,n;
 float tsum=0,wsum=0;
 printf("Enter the number of processes:");
 scanf("%d",&n);
 int a[n][5],temp;
 printf("Enter the arrival time and burst time of each of the processes:\n");
 for(i=0;i<n;i++)
 {
  printf("Arrival time of the process %d:",i);
  scanf("%d",&a[i][1]);
  printf("Burst time of the process %d:",i);
  scanf("%d",&a[i][2]);
 }

 for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
	if(a[j][1]>a[j+1][1])
	 {
	 temp=a[j][1];
	 a[j][1]=a[j+1][1];
	 a[j+1][1]=temp;
	 temp=a[j][2]=a[j+1][2];
	 a[j][2]=a[j+1][2];
	 a[j+1][2]=temp;
	 }
	
 if(a[0][1]!=0)
   a[0][3]=a[0][2]+a[0][1];
 else
   a[0][3]=a[0][2];

 for(i=1;i<n;i++)//completion
    a[i][3]=a[i-1][3]+a[i][2];

 for(i=0;i<n;i++)//turnaround
    a[i][4]=a[i][3]-a[i][1];

 for(i=0;i<n;i++)//waiting
    a[i][5]=a[i][4]-a[i][2];

 for(i=0;i<n;i++)//total
 {
  tsum=tsum+a[i][4];
  wsum=wsum+a[i][5];
 }

 printf("\nP\tAT\tBT\tCT\tTAT\tWT\n\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t%d\t%d\t%d\t%d\t%d",i,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
  printf("\n");
 }
 
 float atsum=tsum/n;
 float awsum=wsum/n;
 printf("\nAverage turnaround time = %f\n",atsum);
 printf("\n");
 printf("Average waiting time = %f\n",awsum);
 printf("\n");
}
