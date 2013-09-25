#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
#define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
int pipe_fd,res=0;
int bytes_read=0;
char buffer[BUFFER_SIZE+1];
memset(buffer,'\0',BUFFER_SIZE);
if(argc!=2)
{
cout<<"usage:./a.out pipe_name\n";
return 1;
}
cout<<"Process "<<getpid()<<"opening fifo in read mode"<<endl;
pipe_fd=open(argv[1],O_RDONLY);
cout<<"FD of fifo in read mode:"<<pipe_fd<<endl;
if(pipe_fd!=-1)
{
res=read(pipe_fd,buffer,BUFFER_SIZE);
bytes_read+=res;
cout<<"data read..\n";
puts(buffer);
(void) close(pipe_fd);
}
else
{
perror("fifo read");
}
cout<<"process "<<getpid()<<"finished reading"<<endl;
return 0;
}
