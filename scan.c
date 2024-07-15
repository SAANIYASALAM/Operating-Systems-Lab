#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n,initial,thm=0,move,temp,size;
    printf("enter the number of requests: ");
    scanf("%d",&n);
    printf("enter the total size of the cylinder: ");
    scanf("%d",&size);
    int req[n];
    printf("enter the request sequence: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("enter the initial head position: ");
    scanf("%d",&initial);
    printf("enter the direction\n1 for high\n0 for low: ");
    scanf("%d",&move);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(initial<req[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {
        for(int i=index;i<n;i++)
        {
            thm=thm+abs(req[i]-initial);
            initial = req[i];
        }
        if(index<n)
        {
            thm=thm+abs(size-1-initial);
            initial = size-1;
        }
        for(int i=index-1;i>=0;i--)
        {
            thm=thm+abs(req[i]-initial);
            initial=req[i];
        }
    }
    else
    {
        for(int i=index-1;i>=0;i--)
        {
            thm=thm+abs(req[i]-initial);
            initial=req[i];
        }
        if(index>0)
        {
            thm =thm+abs(initial-0);
            initial = 0;
        }
        for(int i=index;i<n;i++)
        {
            thm=thm+abs(req[i]-initial);
            initial = req[i];
        }
    }
    printf("the total head movement is %d",thm);
}