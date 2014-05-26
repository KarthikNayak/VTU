/*
 * Sort a given set of elements using the Quicksort method and determine
 * the time required to sort the elements. Repeat the experiment for different
 * values of n, the number of elements in the list to be sorted and plot a
 * graph of the time taken versus n. The elements can be read from a file or
 * can be generated using the random number generator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(long int arr[], long int low, long int high)
{
	long int i, j, temp, key;
	i = low + 1;
	j = high;
	key = arr[low];
	while(1)
	{
		while(arr[i] <= key && i <= high)
			i++;
		while(arr[j] > key && j >= low)
			j--;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp = arr[low];
			arr[low] = arr[j];
			arr[j] = temp;
			return j;
		}
	}
}

void quicksort(long int arr[], long int low, long int high)
{
	long int s;
	if(low < high)
	{
		s = partition(arr, low, high);
		quicksort(arr, low, s - 1);
		quicksort(arr, s + 1, high);
	}
}

int main(int argc, char *argv[])
{
	long int arr[1000000], i, no;
	float start, end;
	printf ("Enter no of elements\n");
	scanf("%d", no);
	srand(no);
	for(i = 0; i < no; i++)
		arr[i] = rand()%1000;
	start = clock();
	quicksort(arr, 0, no -1);
	end = clock();
	for(i = 0; i < no; i++)
		printf ("%ld\n",arr[i]);
	printf ("Time Complexity %f\n",(end - start)/CLOCKS_PER_SEC);
	return 0;
}

	
