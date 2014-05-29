/*Programme to print all reachable nodes in a diagraph using BFS traversam*/


#include <stdio.h>
#include <stdlib.h>

int a[20][20], src, n;

void Bfs()
{
	int i, f, r = 0, u, v, q[50], vis[20] = {0};
	q[r] = src;
	vis[src] = 1;
	for(f = 0, r = 0; f <= r; f++) 
	{
		u = q[f]; //deleting front node
		for(v = 1; v <= n; v++)
		{
			if(a[u][v] == 1 && vis[v] == 0)
			{
				vis[v] = 1;  //mark as visited
				q[++r] = v;  //add neighbour to the rear of queue
			}
		}
	}
	for( i = 1; i <= n; i++)
	{
		if (vis[i] == 1)
			printf("%d ---> %d\n",src,i);
		else
			printf("%d ---> %d is not possible\n",src,i);
	}
}
      
int main()
{
	int i, j;
	printf("\nimplementation of BFS taversal\n");
	printf("enter the number of verticies of the graph\n");         
	scanf("%d", &n);
	printf("enter the adjecency matrix\n");
	for( i = 1; i <= n; i++)
	{
		for( j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);
		}

	}
	printf("enter the source vertex\n");
	scanf("%d",&src);
	Bfs();
	return 0;
}
