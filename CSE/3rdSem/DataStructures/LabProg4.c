#include <stdio.h>
#define N 03
int queue[N],front=0,rear=-1,item;

qinsert()
 {
 	if(rear==N-1)
    	printf("\n\t queue overflow");
 	else
 	{ 	
 		printf("enter the item");
 		scanf("%d",&item);
 		rear++;
 		queue[rear]==item;
 	}
 	return;
}
qdelete()
{
 	if(rear==front-1)
 		printf("\n\t queue underflow");
 	else if(rear==front)
 	{
 	   	printf("the deleted element is :%d",queue[front]);
 	   	front=0;
 	   	rear=-1;
 	}
 	else
 	{
 	   	printf("\n\t deleted item is %d",queue[front]);
 	   	front++;
 	}
	return;
}
qdisplay()
{
 	int i;
 	if(rear==front-1)
 		printf("queue is empty");
 	else
 	{
 		for(i=front;i<=rear;i++)
		   printf("\n\t %d",queue[i]);
 		printf("\n\t front of the queue is %d",queue[front]);
 		printf("\n\t rear of the queue is %d",queue[rear]);
 	}
 	return;
}	
int main() 
{
	int ch ;
	while(1)
	{
		printf("\n\n\t queue implementation using array");
		printf("\n\t 1.qinsert");
		printf("\n\t 2.qdelete");
		printf("\n\t 3.qdisplay");
		printf("\n\t 4.exit");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				qinsert();
			    break;
			case 2:
				qdelete();
			    break;
			case 3:
			    qdisplay();
			    break;
			case 4:
			    return;           
		}
	}
}