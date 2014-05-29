/*Programme to check if a graph is connected using DFS traversal*/


#include<stdio.h>
#include<stdlib.h>

int a[20][20], n, vis[20]={0};

void Dfs(int src)
{
	int j;
	vis[src] = 1;
	for(j = 1; j <= n; j++)
	{
		if(a[src][j] == 1 && vis[j] == 0) 
		{
			Dfs(j);
		}
	}
}
      
int main()
{
	int i, j, src;
	printf("\nimplementation of DFS taversal\n");
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
	Dfs(src);
	for(j =0; j <= n; j++)
	{
		if( vis[j] != 1)
		{
			printf("\ngraph is not connected\n"); 
			return 0;
		}
	}
	printf("\n the graph is connected\n");   
	return 0;
}
