/*
 * Using OpenMP, implement a parallelized Merge Sort algorithm to
 * sort a given set of elements and determine the time required to
 * sort the elements. Repeat the experiment for different values of
 * n, the number of elements in the list to be sorted and plot a
 * graph of the time taken versus n. The elements can be read from
 * a file or can be generated using the random number generator
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int *a;

void merge(int low, int mid, int high)
{
	int i, j, k;
	int b[6000];
	i = low;
	j = mid + 1;
	k = low;
	while((i <= mid) && (j <= high))
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while(i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while(j <= high)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	for(i = low; i <= k; i++)
		a[i] = b[i];
}

void mergesort(int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		#pragma omp task
		{
			mergesort(low, mid);
		}
		#pragma omp task
		{
			mergesort(mid + 1, high);
		}
		merge(low, mid, high);
	}
}

int main(int argc, char *argv[])
{
	int size;
	int i, thread_id;
	double start_time, end_time;
	printf("Enter the size of array \n");
	scanf("%d", &size);
	a = calloc(size, sizeof(int));
	for(i = 0; i < size; i++)
	{
		a[i] = (rand() % size);
		printf("%d\t", a[i]);
	}
	start_time = omp_get_wtime();
	mergesort(0, size - 1);
	end_time = omp_get_wtime();
	printf("Elapse time is %d\n",end_time - start_time);
	return 0;
}
