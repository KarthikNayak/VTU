#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
/*#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,state,tty,comm"
#else*/
#define PSCMD "ps -o pid,ppid,state,tty,command"
//#endif
int main()
{
pid_t pid;
if((pid=fork())<0)
printf("fork error\n");
else if(pid==0)
_exit(0);
sleep(2);
system(PSCMD);
_exit(0);
}
