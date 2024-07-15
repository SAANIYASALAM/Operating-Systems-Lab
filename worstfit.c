#include <stdio.h>
void worstfit(int alloc[],int n,int m,int psize[],int bsize[])
{
    for(int i=0;i<n;i++)
    {
        alloc[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int windex=-1;
        for(int j=0;j<m;j++)
        {
            if(bsize[j]>psize[i])
            {
                if(windex==-1||bsize[windex]<bsize[j])
                {
                    windex=j;
                }
            }
        }
        if(windex!=-1)
        {
            alloc[i] = windex;
            bsize[windex]=bsize[windex]-psize[i];
        }
    }
}
void display(int alloc[],int n,int m,int psize[],int bsize[])
{
    printf("PID\tpsize\talloc_block\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,psize[i]);
        if(alloc[i]!=-1)
        {
            printf("%d\n",alloc[i]+1);
        }
        else
        {
            printf("not allocated\n");
        }
    }
    printf("free blocks\n");
    for(int i=0;i<m;i++)
    {
        printf("%d->",bsize[i]);
    }
}
void main()
{
	int n,m,psize[10],bsize[10],alloc[10];
	printf("enter the number of processes");
	scanf("%d",&n);
	printf("enter the number of blocks");
	scanf("%d",&m);
	printf("enter the size of processes");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&psize[i]);
	}
	printf("enter the size of blocks");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&bsize[i]);
	}
	worstfit(alloc,n,m,psize,bsize);
	display(alloc,n,m,psize,bsize);
}
