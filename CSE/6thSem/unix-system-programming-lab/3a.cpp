#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
using namespace std;
int main(int argc,char *argv[])
{
int fd;
char *file=argv[1];
char buffer[255];
struct flock fvar;
if(argc==1)
{
cout<<"usage:./a.out filename\n";
return 1;
}
if((fd=open(file,O_RDWR))==-1)
{
perror("open");
exit(1);
}
fvar.l_type=F_WRLCK;
fvar.l_whence=SEEK_SET;
fvar.l_start=50;
fvar.l_len=150;
printf("press enter to set lock\n");
getchar();
printf("trying to get lock..\n");
if((fcntl(fd,F_SETLK,&fvar))==-1)
{
perror("fcntl");
exit(1);
}
printf("locked\n");
if((lseek(fd,50,SEEK_SET))==-1)
{
perror("lseek");
exit(1);
}

if((read(fd,buffer,100))==-1)
{
perror("read");
exit(1);
}
printf("data read from file..\n");
puts(buffer);
printf("press enter to release lock\n");
getchar();
fvar.l_type = F_UNLCK;
fvar.l_whence = SEEK_SET;
fvar.l_start = 0;
fvar.l_len = 0;
if((fcntl(fd,F_UNLCK,&fvar))==-1)
{
perror("fcntl");
exit(0);
}
printf("Unlocked\n");
close(fd);
return 0;
}
