#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	char *line = NULL;
	char c;
	int no, i;
	size_t len = 0;
	pid_t x;

	printf("Enter the no of commands\n");
	scanf("%d", &no);
	scanf("%c", &c);
	x = fork();
	if (!x) {
		printf("Enter the commands\n");
		for (i = 0; i <= no; i++) {
			getline(&line, &len, stdin);
			system(line);
			free(line);
			line = NULL;
			len = 0;		
		}		
	}
	else {
		wait(&x);
	}
	return 0;
}
