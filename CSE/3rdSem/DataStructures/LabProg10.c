#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int insert_head( int item, int a[], int n )
{
  int c, p;
  if ( n == MAX_SIZE )
    {
      printf("Heap is full\n");
      return n;
    }

  c = n;
  p = (c-1)/2;

  while( c != 0 && item > a[p] )
    {
      a[c] = a[p];
      c = p;
      p = (c-1)/2;
    }
  a[c] = item;
  return n+1;
}

int delete_heap( int a[], int n )
{
  int p, c;
  if ( n == 0 )
    {
      printf("Heap is empty.\n");
      return 0;
    }
  printf("Item deleted = %d\n", a[0]);
  p = 0;
  c = 2 * p + 1;
  while( c < n )
    {
      if( c + 1 < n )
	{
	  if( a[c] < a[c+1])
	    c++;
	}
      a[p] = a[c];
      p = c;
      c = 2 * p + 1;
    }
  return n - 1;
}

void display( int a[], int n )
{
  int i;
  if( n == 0 )
    {
      printf("Heap is empty\n");
      return;
    }
  printf("The priority queue contents: \n");
  for( i = 0; i < n; i++)
    printf("%d", a[i]);
  printf("%d", a[i]);
  printf("\n");
}

void main()
{
  int a[MAX_SIZE];
  int n = 0, choice, item;
  for (;;)
    {
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice)
	{
	case 1:
	  printf("Enter the item to be inserted\n");
	  scanf("%d", &item);
	  n = insert_heap(item, a, n);
	  break;

	case 2:
	  n = delete_head(a,n);
	  break;

	case 3:
	  display(a, n);
	  break;

	default:
	  return; // or use exit(0);
	}
    }
}
