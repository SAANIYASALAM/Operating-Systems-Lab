#include <stdio.h>
#include <sys/stat.h>
void main()
{
    struct stat sfile;
    char buffer[100];
    printf("enter the name of the file: ");
    scanf("%s",buffer);
    stat(buffer,&sfile);
    printf("the mode of the file is %o\n",sfile.st_mode);
    printf("the uid of the file is %d\n",sfile.st_uid);
    printf("the size of the file is %ld\n",sfile.st_size);
}