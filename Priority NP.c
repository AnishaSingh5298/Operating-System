#include<stdio.h>
#include<conio.h>
void waitingtime(char pr[],int n,int bt[], int wt[] )
{
	int i,j;
	wt[0]=0;
	for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
}
void turnaroundtime(char pr[],int n,int bt[], int wt[], int tat[] )
{
	int i;
	for(i=0;i<n;i++)
	tat[i]=bt[i]+wt[i];
	
}
void avgtime(char pr[],int n,int bt[])
{
	int i, wt[n],tat[n],totalwt=0,totaltat=0;
	waitingtime(pr,n,bt,wt);
	turnaroundtime(pr,n,bt,wt,tat);
	printf("Process    Burst Time    Waiting Time    Turn Around Time\n");
	for(i=0;i<n;i++)
	{
		totalwt=totalwt + wt[i];
		totaltat=totaltat + tat[i];
		printf("%d",(i+1));
		printf("               %d",bt[i]);
		printf("               %d",wt[i]);
		printf("               %d\n",tat[i]);
		
	}
	float x=(float)totalwt/n;
	float y=(float)totaltat/n;
	printf("Average waiting time = %f\n",x);
	printf("Average turn around time = %f\n",y);
	
}

int main()
{
	int i,j,n,bt[100],p[100],pos,temp,pr[100];
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter the burst time and priority\n");
	for(i=0;i<n;i++)
	{
		printf("\np[%d]\n",i+1);
		printf("Burst time: ");
		scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;        
	
    }
	
    for(i=0;i<n;i++)
    {
    	p[i]=p[i+1];
	}
     for(i=0;i<n;i++)
    {
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
    		if(bt[j]<bt[pos])
    		pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
		
	}
	avgtime(pr,n,bt);
	return 0;
	
	
}
