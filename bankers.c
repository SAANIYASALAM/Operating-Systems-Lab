#include <stdio.h>
void main()
{
    int n,m,alloc[10][10],max[10][10],avail[10],need[10][10],work[10],finish[10];
    int flag,index=0,safeseq[10];
    printf("enter the number of processes:\n");
    scanf("%d",&n);
    printf("enter the number of resources:\n");
    scanf("%d",&m);
    printf("enter the allocation matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter the max matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the available matrix:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    printf("the need matrix is:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                flag=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    index++;
                    safeseq[index]=i;
                    for(int y=0;y<m;y++)
                    {
                        work[y]=work[y]+alloc[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
    int isSafe=1;
    for(int i=0;i<n;i++)
    {
        if(finish[i]!=1)
        {
            isSafe=0;
            break;
        }
    }
    if(isSafe=1)
    {
        printf("the safe sequence is:\n");
        for(int i=1;i<=n;i++)
        {
            printf("P%d->",safeseq[i]);
        }
    }
    else
    {
        printf("no safe sequence");
    }
}