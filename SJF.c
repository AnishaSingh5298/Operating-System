#include<stdio.h>
#include<conio.h>
void waitingtime(char p[],int n,int bt[], int wt[] )
{
	int i;
	wt[0]=0;
	for(i=1;i<n;i++)
	wt[i]=bt[i-1]+wt[i-1];
}
void turnaroundtime(char p[],int n,int bt[], int wt[], int tat[] )
{
	int i;
	for(i=0;i<n;i++)
	tat[i]=bt[i]+wt[i];
	
}
void avgtime(char p[],int n,int bt[])
{
	int i, wt[n],tat[n],totalwt=0,totaltat=0;
	waitingtime(p,n,bt,wt);
	turnaroundtime(p,n,bt,wt,tat);
	printf("Process    Burst Time    Waiting Time    Turn Around Time\n");
	for(i=0;i<n;i++)
	{
		totalwt=totalwt + wt[i];
		totaltat=totaltat + tat[i];
		printf("%d",(i+1));
		printf("               %d",bt[i]);
		printf("              %d",wt[i]);
		printf("            %d\n",tat[i]);
		
	}
	float x=(float)totalwt/n;
	float y=(float)totaltat/n;
	printf("Average waiting time = %f\n",x);
	printf("Average turn around time = %f\n",y);
	
}

int main()
{
	int i,j,n,bt[100],temp,pos;
	char p[100];
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter the names of processes\n");
	for(i=0;i<n;i++)
	{
	scanf("%s",&p[i]);
    }
	printf("Enter the CPU burst time according to the processes\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&bt[i]);
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
		
	}
	avgtime(p,n,bt);
	return 0;
	
	
}
