#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid = shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("the key of the shared memory is %d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("the address of the shared memory is %p\n",shared_memory);
    printf("enter some data into the shared memory:\n");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("the data written in the shared memory is : \n");
    printf("%s",(char*)shared_memory);
}