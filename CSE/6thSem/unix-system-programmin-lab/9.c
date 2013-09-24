#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
int sys(const char *cmdstr)
{
pid_t pid;
int s;
if(cmdstr==NULL)
return(1);
if((pid=fork())<0)
s=-1;
else if(pid==0)
{
execl("/bin/sh","sh","-c",cmdstr,NULL);
//_exit(127);
}
else
{waitpid(pid,&s,0);
//{
//if(errno!=EINTR)
//{
//s=-1;
//break;
//}
//}
}
return s;
}
int main()
{
int s;
if((s=sys("date"))<0)
printf("date error\n");
if((s=sys("nosuchcommand"))<0)
printf("no such cmd error\n");
if((s=sys("who"))<0)
printf("who error\n");
_exit(0);
}
