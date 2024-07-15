#include <stdio.h>
int rear=-1;
void initialize(int frames[], int m)
{
    for(int i=0;i<m;i++)
    {
        frames[i]=-1;
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
void fifo(int pages[], int n , int m , int frames[])
{
    int pagefaults=0;
    int page;
    for (int i=0;i<n;i++)
    {
        page = pages[i];
        int found =0;
        for(int j=0;j<m;j++)
        {
            if (frames[j]==page)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            pagefaults++;
            rear = (rear+1)%m;
            frames[rear]= page;
        }
        display(m,frames);
    }
    printf("the number of page faults is %d", pagefaults);
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
    initialize(frames,m);
    fifo(pages,n,m,frames);
}