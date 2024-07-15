#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
struct dirent *dptr;
void main()
{
    char buff[200];
    DIR *dirp;
    printf("enter the directory name:");
    scanf("%s",buff);
    dirp = opendir(buff);
    if(dirp==NULL)
    {
        printf("error");
        exit(1);
    }
    while((dptr = readdir(dirp))!=NULL)
    {
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}