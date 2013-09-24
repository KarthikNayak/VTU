#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5
void callme(int sig_no)
{
alarm(INTERVAL);
printf("Hello!!");
}
int main()
{
struct sigaction action;
sigemptyset(&action.sa_mask);
action.sa_handler=(void(*)(int))callme;
action.sa_flags=SA_RESTART;
if(sigaction(SIGALRM,&action,0)==-1)
{
perror("sigaction\n");
return 1;
}
/*if(alarm(INTERVAL)==-1)
{
perror("alarm\n");
}
else
{*/
sleep(10);
//}
return 0;
}
