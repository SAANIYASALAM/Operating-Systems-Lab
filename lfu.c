#include <stdio.h>
void initialize(int counts[],int frames[],int m)
{
    for(int i=0;i<m;i++)
    {
        counts[i]=0;
        frames[i]=-1;
    }
}
void display(int m,int frames[])
{
    for(int i=0;i<m;i++)
    {
        if(frames[i]!=-1)
        {
            printf("%d\t",frames[i]);
        }
        else
        {
            printf("-\t");
        }
    }
    printf("\n");
}
int findLFU(int m, int counts[])
{
    int min = counts[0];
    int lfu=0;
    for(int i=0;i<m;i++)
    {
        if(counts[i]<min)
        {
            min = counts[i];
            lfu=i;
        }
    }
    return lfu;
}
void lfu(int pages[], int n,int m, int frames[], int counts[])
{
    int pagefaults=0;
    int page;
    for(int i=0;i<n;i++)
    {
        page= pages[i];
        int found=0;
        for(int j=0;j<m;j++)
        {
            if(frames[j]==page)
            {
                found=1;
                counts[j]++;
                break;
            }
        }
        if(!found)
        {
            int lfu = findLFU(m,counts);
            frames[lfu]=page;
            counts[lfu]=1;
            pagefaults++;
        }
        display(m,frames);
    }
    printf("the number of page faults occoured = %d ",pagefaults);
}
void main()
{
    int n,m,pages[20];
    printf("enter the number of frames: ");
    scanf("%d",&m);
    int frames[m],counts[m];
    printf("enter the number of pages: ");
    scanf("%d",&n);
    printf("enter the reference sequence: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("the page replacement algorithm is : \n");
    initialize(counts,frames,m);
    lfu(pages,n,m,frames,counts);

    
}