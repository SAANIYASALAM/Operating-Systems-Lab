#include <stdio.h>

void findwt(int n,int wt[],int at[], int bt[])
{
    int i;
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        wt[i]-=at[i]-at[i-1];
    }
    if(wt[i]<0)
    {
        wt[i]=0;
    }
}
void findtat(int n,int tat[], int wt[], int bt[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }
}
void findavgtime(int n,int at[], int bt[])
{
    int wt[n],tat[n];
    float twt=0,ttat=0;
    findwt(n,wt,at,bt);
    findtat(n,tat,wt,bt);
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
    {
        twt=twt+wt[i];
        ttat=ttat+tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],wt[i],tat[i]);
    }
    printf("the avg waiting time is: %f\n",twt/n);
    printf("the avg turn around time is: %f",ttat/n);
}
void main()
{
    int n;
    printf("enter the number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the arraival time of P%d: ",i);
        scanf("%d",&at[i]);
        printf("enter the burst time of P%d: ",i);
        scanf("%d",&bt[i]);
    }
    findavgtime(n,at,bt);
    //return 0;
}