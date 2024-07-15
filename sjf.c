#include <stdio.h>

struct processes
{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void main()
{
    int n,ct=0,ttat=0,twt=0;
    printf("enter the number of processes: ");
    scanf("%d",&n);
    struct processes process[n],temp;
    printf("enter the pid arraival time and burst time of each processes: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&process[i].id,&process[i].at,&process[i].bt);
    }
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j].at>process[j+1].at)
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int min =i;
        for (int j=i+1;j<n;j++)
        {
            if(process[j].at<=ct && process[j].bt<process[min].bt)
            {
                min =j;
            }
        }
        temp = process[i];
        process[i] = process[min];
        process[min]= temp;
        if(ct<process[i].at)
        {
            ct = process[i].at;
        }
        ct=ct+process[i].bt;
        process[i].ct = ct;
        process[i].tat= process[i].ct-process[i].at;
        process[i].wt=process[i].tat-process[i].bt;
        ttat=ttat+process[i].tat;
        twt = twt+process[i].wt;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j].id>process[j+1].id)
            {
                temp = process[j];
                process[j]= process[j+1];
                process[j+1]= temp;
            }
        }
    }
    float avgtat = (float)ttat / n;
    float avgwt = (float)twt / n;
    printf("SJF algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time\tCompletion Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", process[i].id, process[i].at, process[i].bt, process[i].tat, process[i].wt, process[i].ct);
    }
    printf("the avg tirn around time is = %.2f\n", avgtat);
    printf("the avg waiting time is = %.2f\n", avgwt);
}