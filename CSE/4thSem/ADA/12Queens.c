/*
 *  Implement N Queen's problem using Back Tracking.
 */

#include <stdio.h>

int no;

int isSafe(int board[10][10], int row, int col)
{
	int i, j;
 
	/* Check this row on left side */
	for (i = 0; i < col; i++)
	{
		if (board[row][i])
			return 0;
	}
 
	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return 0;
	}
 
	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < no; i++, j--)
	{
		if (board[i][j])
			return 0;
	}
 
	return 1;
}
 
/* A recursive utility function to solve 10 Queen problem */
int solveNQUtil(int board[10][10], int col)
{
	int i;
	/* base case: If all queens are placed then return 1 */
	if (col >= no)
		return 1;
 
	/* Consider this column and try placing this queen in all rows
	   one by one */
	for (i = 0; i < no; i++)
	{
		/* Check if queen can be placed on board[i][col] */
		if ( isSafe(board, i, col) )
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;
 
			/* recur to place rest of the queens */
			if ( solveNQUtil(board, col + 1) == 1 )
				return 1;
 
			/* If placing queen in board[i][col] doesn't lead to a solution
			   then remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}
 
	/* If queen can not be place in any row in this colum col
	   then return 0 */
	return 0;
}

int main(int argc, char *argv[])
{
	int a[10][10] = {0}, i, j;
	printf ("Enter the size of the board\n");
	scanf("%d", &no);
	if(!solveNQUtil(a, 0))
		return 0;
	printf("Solution is :\n");
	for(i = 0; i < no; i++)
	{
		for(j = 0; j < no; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

