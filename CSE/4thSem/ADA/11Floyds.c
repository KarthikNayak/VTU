/*
 *Implement All-Pairs Shortest Paths Problem using Floyd's algorithm.
 *Parallelize this algorithm, implement it using OpenMP and
 *determine the speed-up achieved.
 */

#include <stdio.h>
#include <omp.h>

#define min(a, b) a < b ? a : b

void floyds(int a[10][10], int n)
{
	int thread_id, i, j, k, starttime, endtime;
	starttime = omp_get_wtime();
	omp_set_num_threads(2);
#pragma omp parallel for shared(a) private(i, j, k)
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				thread_id = omp_get_thread_num();
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				printf("Thread %d : a[%d][%d] = %d\n", thread_id, i, j, a[i][j]);
			}
	endtime = omp_get_wtime();
	printf("Shortest path :\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("Time taken is : %d\n", (endtime - starttime));
}

int main(int argc, char *argv[])
{
	int no, a[10][10], i, j;
	printf("Enter the no of elem\n");
	scanf("%d", &no);
	printf("Enter the elem\n");
	for(i = 0; i < no; i++)
		for(j = 0; j < no; j++)
			scanf("%d", &a[i][j]);
	floyds(a, no);
	return 0;
}
