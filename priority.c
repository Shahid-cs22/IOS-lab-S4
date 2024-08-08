#include<stdio.h>
#include<string.h>
void main()
{
 int n,Bu[20],Twt=0,Ttt=0,A[10],Wt[10],w,ch,i,j,temp,temp1,P[10];
 float Awt,Att;
 char pname[20][20],c[20][20];
 printf("\n Enter the number of processes: ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 printf("\n\n Enter the process name: ");
 scanf("%s",pname[i]);
 printf("\n BurstTime for %s",pname[i]);
 scanf("%d",&Bu[i]);
 printf("\n\n Enter the priority ");
 scanf("%d",&P[i]);
 }
 printf("\n\n PRIORITY SCHEDULING ALGORITHM\n\n");
 for(i=1;i<=n;i++)
 {
 for(j=i+1;j<=n;j++)
 {
 if(P[i]>P[j])
 {
 temp=Bu[i];
 Bu[i]=Bu[j];
 Bu[j]=temp;
 strcpy(c[i],pname[i]);
 strcpy(pname[i],pname[j]);
 strcpy(pname[j],c[i]);
 }
 }
 }
 for(i=1;i<=n;i++)
 {
 A[i]=0;
 }
 Wt[1]=0;
 for(i=2;i<=n;i++)
 {
 Wt[i]=Bu[i-1]+Wt[i-1];
 }
 for(i=1;i<=n;i++)
 {
 Twt=Twt+(Wt[i]-A[i]);
 Ttt=Ttt+((Wt[i]+Bu[i])-A[i]);
 }
 Att=(float)Ttt/n;
 Awt=(float)Twt/n;
 printf("\n\n Average Turn around time=%3.2f ms ",Att);
 printf("\n\n AverageWaiting Time=%3.2f ms",Awt);
 printf("\n\n\t\t\tGANTT CHART\n");
 for(i=1;i<=n;i++)
 printf("|\t%s\t",pname[i]);
 printf("|\t\n");
 printf("\n");
 for(i=1;i<=n;i++)
 printf("%d\t\t",Wt[i]);
 printf("%d",Wt[n]+Bu[n]);
printf("\n");
}	
