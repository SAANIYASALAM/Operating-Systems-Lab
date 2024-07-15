#include <stdio.h>
#include <stdlib.h>

int mutex=1;
int full=0;
int empty=5;
int x=0;

void wait(int *s)
{
    while(*s<=0)
    ;
    (*s)--;
}
void signal(int *s)
{
    (*s)++;
}

void producer()
{
    wait(&mutex);
    wait(&empty);
    signal(&full);
    x++;
    printf("the produced item is %d\n",x);
    signal(&mutex);
}

void consumer()
{
    wait(&mutex);
    wait(&full);
    signal(&empty);
    printf("the consumed item is %d\n",x);
    x--;
    signal(&mutex);
}

void main()
{
    int ch;
    printf("choices..\n1.producer\n2.consumer\n3.exit\n");
    do
    {
        printf("enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                if(mutex==1&&empty!=0)
                {
                    producer();
                }
                else
                {
                    printf("the buffer is full\n");
                }
                break;
            case 2:
                if(mutex==1&&full!=0)
                {
                    consumer();
                }
                else
                {
                    printf("the buffer is empty\n");
                }
                break;
        }
    }
    while(ch!=3);
}
