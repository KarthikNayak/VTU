#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
pid_t pid;
if((pid=fork())<0)
printf("fork error\n");
else if(pid==0)
{
if((pid=fork())<0)
printf("fork error\n");
else if(pid>0)
{
_exit(0);
}
sleep(2);
printf("second child,parent pid:%d\n",getppid());
_exit(0);
}
if(waitpid(pid,NULL,0)!=pid)
printf("waitpid error\n");
_exit(0);
}
