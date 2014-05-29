/*
 * Find a subset of a given set S = {sl, s2,...sn} of n positive integers
 * whose sum is equal to a given positive integer d. For example, if
 * S= {1, 2, 5, 6, 8} and d = 9 there are two solutions {1,2,6} and {1,8}.
 * A suitable message is to be displayed if the given problem instance
 * doesn't have a solution.
 */

#include <stdio.h>
#include <stdlib.h>

int count, fsum, elem[10], x[10];

void subset(int m, int k, int sum)
{
	/*
	 * Here we use recursion to check the sum :
	 * m is the sum added upto the current recursion
	 * k is the next element to be checked.
	 */
	
	int i;
	
	/* x acts like a array to keep track of visited elements */
	x[k] = 1;
	
	/* If the current recursion is equal to req sum, print all values */
	if(m + elem[k] == fsum)
	{
		printf("Subset sol no %d : ", ++count);
		for(i = 0; i <= k; i++)
			if(x[i])
				printf("%d ", elem[i]);
		printf("\n");
	}

	/* check if the next element can be used, if yes, next recursion */
	else if(m + elem[k] + elem[k + 1] <= fsum)
		subset(m + elem[k], k + 1, sum - elem[k]);

	/* now if the k'th element cannot be used skip and move to next
	 * 1. First condition is to check if the other elements are totally
	 * greter than fsum. 2. Second condition is to check if the next
	 * element when added, is less than fsum. */
	if ((m + sum - elem[k] >= fsum) && (m + elem[k + 1] <= fsum))
	{
		x[k] = 0;
		subset(m, k + 1, sum - elem[k]);
	}
}

int main(int argc, char *argv[])
{
	int sum = 0, i, no;

	printf ("Enter the no of items\n");
	scanf("%d",&no);

	printf ("Enter the no's in ascending order\n");
	for(i = 0; i < no; i ++)
	{
		scanf("%d", &elem[i]);
		//finding the sum of all elements
		sum = sum + elem[i];
	}

	printf ("Enter the required sum\n");
	scanf("%d", &fsum);

	/*
	 * If the sum of all the entered elements is greater than
	 * the required sum, or if the first element itself is
	 * greater than the required sum, No solution exists.
	 */
	
	if(sum < fsum || elem[0] > fsum)
		printf ("No solution\n");
	else
		subset(0, 0, sum);
	
	return 0;
}
