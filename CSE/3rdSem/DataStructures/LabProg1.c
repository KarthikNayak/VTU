/**
* Data Structures Lab
* Program to accept two polynomials, add them and print the resulting polynomial
* This program uses linked lists to perform this task
* This program is written for the Turbo C compiler and varies slightly if other compilers (like GCC) are used.

TRACE THE PROGRAM STARTING AT THE main() FUNCTION
Here we use a Linked List Type of Data structure
*/


//Header Files
#include <stdio.h> // For the std input and output functions -- scanf() and printf()
#include <stdlib.h> // For the malloc function in TurboC use alloc.h :)

//Prepocessor Derivatives
#define MALLOC(p,n,type) p=(type *) malloc (n*sizeof(type))
/*
*	Defines a macro that uses the malloc function. The malloc function accepts the amount of memory required.
*	It is given by n*sizeof(type), where the type, in this program, will be the structures defined later.
*	sizeof(type) returns the space needed to store type in bytes.
*	n is the number of such structures stored.

*	malloc() returns a pointer to the variable that it has allocated memory for. This is explicitly converted
	to a pointer of the type defined.
*/

#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)
/*
*	Defines a macro to compare two values x and y.
*	If x is equal to y, it returns 0
*	If x is greater than y, it returns 1
*	If y is greater than x, it returns -1

*	Ternary operator syntax:
*	condition ? true-statement : false-statement;
*/

//Structure which acts like a linked list data type 
struct node 	//defines a structure node
{
	int coef; 	//will store the co-efficient of the polynomial
	int expo;	//will store the exponent of the polynomial
	struct node *link;	//creates a pointer of type node (A pointer to the same structure type).
};			// do not forget the trailing semi-colon!

//Typedef is used to set datatypes of the users choice
typedef struct node *NODE; // define a pointer of type node that will be identified (new type) by NODE

NODE readpoly (NODE head)
{
	int i=1, coef, expo;
	printf("Enter the coefficient as -999 to end the Polynomial\n");
	while (1) // loops continuously until broken by "break;" statement
	{
		printf("Enter %d temp\n", i++);
		printf("coef = \n");
		scanf("%d", &coef); // Accepts the coefficient of the term
		if (coef == -999) // if the coefficient entered is -999, it exits the while loop and returns the polynomial
			break;
		printf("Power of x = ");
		scanf("%d", &expo); // accepts the power of the term
		/*now after the first term is taken we need to allocate memory
		to the next term and also link this term to the next, now this is done
		by the attach funtion*/
		head = attach (coef, expo, head);
	} // the process is continued for every term of the polynomial
	return head; 
}

/*This the integral  part of the program what attach basically does is 
makes a new node and points the link pointer of the last node connected
to the node passed to the newly made node and sets its value by the parameters
recieved and points the link of the newly made node to the node recieved */ 
NODE attach(int coef, int expo, NODE head)
{
	NODE cur, temp;
	//two pointers to node structure are made 
	MALLOC(temp, 1, struct node);
	//temp is allocated memory using the malloc function
	temp->coef = coef;
	temp->expo = expo;
	//the value of temps coef and expo is set to the values passed
	cur = head->link;
	//cur now points to the link in head
	while(cur->link != head)
		cur = cur->link;
	//now we keep a loop to check which is the last node in the whole link
	//of the node recieved and set cur to point to the last loop
	cur->link = temp;
	//now the last node links to temp
	temp->link = head;
	//temp now links to the head
	return head;
	//return the head :)
}

/*poly add is used to add the two polynomials and store the result 
in the node head3*/
NODE polyadd (NODE head1, NODE head2, NODE head3)
{
	NODE a, b;
	//two pointers to the node structure 
	int coef;
	a = head1->link;
	b = head2->link;
	//set a to the first node in head1 and b to first node in head2
	//this while loop is exectued till neither reaches end 
	while(a != head1 && b != head2)
	{
		//we use compare as only exponentials of the same order can be added
		switch(COMPARE(a->expo, b->expo))
		{	
			/*case 0 is when they are equal here we add them regularly and
			sent the value to head3 using attach function (remember how it links
			new nodes to the one sent)*/
			case 0: coef = a->coef + b->coef;
					//if sum of coef is 0 we dont have to send it to the head3 node
					if (coef != 0)
						head3 = attach (coef, a->expo, head3);
					a = a->link;
					b = b->link;
					//since the both the nodes are used we use the link
					//in them to go to the next node
					break;
			/*case 1 is when a is ahead of b so we only send the value in a to head3*/
			case 1: head3 = attach (a->coef, a->expo, head3);
					a = a->link;
					//since the node is used we go to the next node
					break;
			/*case default is when b is ahead of a so we only send the value in b to head3*/
			default: head3 = attach (b->coef, b->expo, head3);
					b = b->link;
		}
	}
	/*here we check the condition when b has reached the last term 
	but a still has terms left*/
	while(a != head1)
	{
		head3 = attach (a->coef, a->expo, head3);
		a = a->link;
	}
	/*here we check the condition when a has reached the last term 
	but b still has terms left*/
	while(b != head2)
	{
		head3 = attach (b->coef, b->expo, head3);
		b = b->link;
	}
	return head3;
	//return head
}

/*Displays the result*/
void display (NODE head)
{
	NODE temp;
	// if head points to itself no polynomial has been entered
	if (head->link == head)
	{
		printf("Polynomial does not exist\n");
		return;
	}
	//else we link temp to the node pointed by head and print 
	//all nodes till head
	temp = head->link;
	while (temp != head)
	{
		if (temp->coef < 0)
			printf("%dx^%d ", temp->coef, temp->expo);
		else
		{
			printf("%dx^%d ", temp->coef, temp->expo);
			temp = temp->link;
		}
	}
}	

void main()
{
	NODE head1, head2, head3; 
	//Declare three variables of type NODE. 
	//Remember, NODE is defined as a pointer, so no memory is allocated to head1, head2 and head3. We are just created pointers to them.
	MALLOC(head1, 1, struct node);
	MALLOC(head2, 1, struct node);
	MALLOC(head3, 1, struct node);
	// NODEs head1, head2 and head3 are dynamically allocated memory using the macro MALLOC.
	// "->" is used as an alternative to (*ptr).member hence ptr->member
	head1->link = head1; 
	head2->link = head2;
	head3->link = head3;
	/*we're using the pointer within the structures to themselves 
	as theyre not linked to other notes until values given*/
	printf("Enter the first Polynomial\n");
	head1 = readpoly(head1);
	printf("Enter the second Polynomial\n");
	head2 = readpoly(head2);
	//We Input the Two polynomials
	head3 = polyadd (head1, head2, head3);
	//We add the two polynomials and the sum is stored in head3
	printf("\nPoly 1: ");
	display(head1);
	printf("\nPoly 2: ");
	display(head2);
	printf("\nPoly 3 (Addition of Poly 1 and 2: \n\n");
	display(head3);
	//We print the Inputs and Outputs
	printf("\n\n\n");
}
