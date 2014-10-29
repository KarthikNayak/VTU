#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t pid;
    pid = fork();
    if (!pid) {
        printf("== In child ==\n");
        printf("Child PID: %ld\n", (long) getpid());
        printf("Parent PID: %ld\n", (long) getppid());
    }
    else {
        wait(&status);
        printf("\n== In Parent ==\n");
        printf("Parent PID: %ld\n", (long) getpid());
        printf("Child PID: %ld\n", (long) pid);
    }
}
