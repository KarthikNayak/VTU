#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ran[16] = "abcdefghijklmnop";
	int fd;
	
	fp = fopen("test", "w+");
	fd = fileno(fp);
	write(fd, ran, 16);
	lseek(fd, 32, SEEK_CUR);
	write(fd, ran, 16);
	system("vi test");
	return 0;
}
