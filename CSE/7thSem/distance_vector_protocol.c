#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void dis()
{ struct dv
  { 
	unsigned distance[10];
	unsigned from[10]; 
  }rt[10];
 int i=0,j=0,k=0,c=0,dm[10][10],n;
 printf("Enter number of nodes \t");
 scanf("%d",&n);
 for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		scanf("%d",&dm[i][j]);
		rt[i].distance[j]=dm[i][j];
		rt[i].from[j]=j;
	}
 do 
 {
	c=0;
 	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(rt[i].distance[j]>dm[i][k]+rt[k].distance[j])
				{
					rt[i].distance[j]=rt[j].distance[k]+rt[k].distance[j];
					rt[i].from[j]=k;
					c++;

				}
 }while(c!=0);
 printf("\nDistnace Vector table is :");
 for(i=0;i<n;i++)
 {	printf("The state of routes %d is ",i+1);
	for(j=0;j<n;j++)
		printf("\n From %d to %d is %d ", i+1, j+1, rt[i].distance[j]);
 }
 printf("\n Enter Source and Destination Node\n");
 scanf("%d%d",&i,&j);
 printf("The shortest path from %d to %d is %d \n", i ,j, rt[i-1].distance[j-1] );
		
}
int main()
{ dis();
   return 1;
}
