#include <stdio.h>
void initialize(int counts[], int frames[], int m)
{
    for(int i=0;i<m;i++)
    {
        frames[i]=-1;
        counts[i]=0;
    }
}
void display(int m, int frames[])
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
int findlru(int counts[], int m)
{
    int max = counts[0];
    int lru=0;
    for(int i=0;i<m;i++)
    {
        if(counts[i]>max)
        {
            max = counts[i];
            lru = i;
        }
    }
    return lru;
}
void lru(int pages[], int n, int m , int frames[], int counts[])
{
    int pagefaults=0;
    int page;
    for (int i=0;i<n;i++)
    {
        int page = pages[i];
        int found =0;
        for (int j=0;j<m;j++)
        {
            if(frames[j]==page)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            int lru = findlru(counts,m);
            frames[lru] = page;
            counts[lru]=0;
            pagefaults++;
        }
        for(int j=0;j<m;j++ )
        {
            counts[j]++;
        }
        for(int j=0;j<m;j++ )
        {
            if(frames[j]==page)
            {
                counts[j]=0;
                break;
            }
        }
        display(m,frames);
    }
    printf("the number of page faults = %d ",pagefaults);
}
void main()
{
    int n,m,pages[40];
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
    lru(pages,n,m,frames,counts);
}