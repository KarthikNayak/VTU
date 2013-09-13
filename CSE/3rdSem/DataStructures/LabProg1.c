/**
* Data Structures Lab
* Program to accept two polynomials, add them and print the resulting polynomial
* This program uses linked lists to perform this task
* This program is written for the Turbo C compiler and varies slightly if other compilers (like GCC) are used.

* TIP: TRACE THE PROGRAM STARTING AT THE main() FUNCTION
Here we use a Linked List Type of Data structure*/


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

void display (NODE head)
{
	NODE temp;
	if (head->link == head)
	{
		printf("Polynomial does not exist\n");
		return;
	}
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

NODE attach(int coef, int expo, NODE head)
{
	NODE cur, temp;
	MALLOC(temp, 1, struct node);
	temp->coef = coef;
	temp->expo = expo;
	cur = head->link;
	while(cur->link != head)
		cur = cur->link;
	cur->link = temp;
	temp->link = head;
	return head;
}

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

NODE polyadd (NODE head1, NODE head2, NODE head3)
{
	NODE a, b;
	int coef;
	a = head1->link;
	b = head2->link;
	while(a != head1 && b != head2)
	{
		switch(COMPARE(a->expo, b->expo))
		{
			case 0: coef = a->coef + b->coef;
					if (coef != 0)
						head3 = attach (coef, a->expo, head3);
					a = a->link;
					b = b->link;
					break;
			case 2: head3 = attach (a->coef, a->expo, head3);
					a = a->link;
					break;
			default: head3 = attach (b->coef, b->expo, head3);
					b = b->link;
		}
	}

	while(a != head1)
	{
		head3 = attach (a->coef, a->expo, head3);
		a = a->link;
	}
	while(b != head2)
	{
		head3 = attach (b->coef, b->expo, head3);
		b = b->link;
	}
	return head3;
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
	/* "->" is used as an alternative to (*ptr).member hence ptr->member
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
