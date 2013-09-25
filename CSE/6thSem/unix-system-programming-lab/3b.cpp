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
		return -1;
	}
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		perror("open");
		exit(1);
	}
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=50;
	fvar.l_len=150;
	while(fcntl(fd,F_SETLK,&fvar)==-1)
	{
		while((fcntl(fd,F_GETLK,&fvar)!=-1)&&fvar.l_type!=F_UNLCK)
		{
			cout<<*argv <<"locked by process "<<fvar.l_pid<<"from "<<fvar.l_start<<"for "<<fvar.l_len<<"bytes"<<" Lock set is "<<(fvar.l_type==F_WRLCK?'w':'r')<<endl;
		}
	}
	printf("file locked\n");
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
	printf("data read..\n");
	puts(buffer);
	printf("enter to release lock\n");
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
	printf("Unlocked file\n");
	close(fd);
	return 0;
}
