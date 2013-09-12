#include<stdio.h>
#include<alloc.h>

struct sparse
{
  int data, row, col;
  struct sparse *llink;
  struct sparse *rlink;
};

int main()
{
  int m, n, i, j, k;
  struct sparse *anew, *ar[5], *al[5], *p, *c;
  printf("Enter the order of the matrix(mxn): ");
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++)
    {
      ar[i] = (struct sparse *) malloc(sizeof(struct sparse));
      ar[i]->rlink = ar[i];
      ar[i]->llink = NULL;
    }

  for (j = 0; j < n; j++)
    {
      al[j] = (struct sparse *) malloc( sizeof( struct sparse));
      al[j]->llink = al[j];
      al[j]->rlink = NULL;
    }

  printf("Enter the matrix: \n");

  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  anew = (struct sparse *) malloc( sizeof( struct sparse ));
	  anew->row = i;
	  anew->col = j;
	  scanf("%d", &anew->data);
	  anew->rlink = ar[i]->rlink;
	  ar[i]->rlink = anew;
	  anew->llink = al[i]->llink;
	  al[j]->llink = anew;
	}
    }
  printf("\nEnter the key element: ");
  scanf("%d", &k);

  for( i = 0; i < m; i++ )
    {
      p = ar[i];
      c = p->rlink;
      while( c != p )
	{
	  if( c->data == k)
	    {
	      printf("\nElement %d is found at row %d and column %d", c->data, c->row+1, c->col+1);
	      return; // or exit(0)
	    }
	  c = c->rlink;
	}
    }

  printf("Element is not found \n");
}
