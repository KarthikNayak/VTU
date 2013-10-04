/*Queue data Structure Implementation in C
  queue is a First-In-First-Out (FIFO) data structure.
  So lements entered first are on top and entered last 
  are on the rear more info available at 
  http://en.wikipedia.org/wiki/Queue_(abstract_data_type) */


//Header Files
#include <stdio.h>
/*to print and scan*/

//Pre-Pocessor Derivatives
#define N 03
/*We're setting N=3 where N is going to be used to 
  set the no of elements defined in the queue*/

//Global Variables
int queue[N],front=0,rear=-1,item;
/*queue[N] is an array holding the elemnts in Queue
  front notes the position of element in the front,
  rear notes the position of element in the rear.
  item denotes the current variable*/

//Qinsert is used to insert elements to the Queue
qinsert()
{
  if(rear==N-1)
    printf("queue overflow\n");
  //If the queue is Empty we print "queue overflow"
  else
    { 	
      printf("enter the item\n");
      scanf("%d",&item);
      queue[++rear]=item;
    }
  //else we input a value to the queue from rear and increase rear by 1
  return;
}

//Qdelete is used to delete elements from the front 
qdelete()
{
  if(rear==front-1)
    printf("queue underflow\n");
  //If the queue is Empty we print "queue overflow"
  else if(rear==front)
    {
      printf("the deleted element is :%d",queue[front]);
      front=0;
      rear=-1;
    }
  //If only one element is present in the queue 
  else
    {
      printf("deleted item is %d",queue[front]);
      front++;
    }
  //if more than one element is present in the queue
  return;
}

//Qdisplay is used to display elements of the queue
qdisplay()
{
  int i;
  if(rear==front-1)
    printf("queue is empty\n");
  //If the queue is Empty we print "queue overflow"
  else
    {
      for(i=front;i<=rear;i++)
	printf("%d",queue[i]);
      printf("front of the queue is %d",queue[front]);
      printf("rear of the queue is %d",queue[rear]);
    }
  //else all values are printed
  return;
}	

//Main Funtion
int main() 
{
  int ch;
  while(1)
    {
      printf("queue implementation using array\n");
      printf("1.qinsert\n");
      printf("2.qdelete\n");
      printf("3.qdisplay\n");
      printf("4.exit\n");
      printf("enter your choice:\n");
      scanf("%d",&ch);
      /*Asking the user to input his/her choice of Queue operation*/
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
      //Operation performed based on the choice of the user
    }
}
