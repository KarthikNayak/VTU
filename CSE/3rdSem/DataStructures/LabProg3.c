/* This program takes a postfix expression and prints the resultant value , so entry should be integers and regular operators +,-,*,/,^. This is achieved by taking the input from an user
 and storing it in a char array called postfix */

//Header Files
#include <stdio.h>      //For Std Input and Output
#include <math.h>       //For the Power Function “^”
#include <ctype.h>      //For checking whether alphabet or numerical
#include <string.h>		//For string length

//Global Variables

int s[20], top = 0;		//s[20] stores the characters, saves the final reult 

//push function takes characters and stores them in global array s temporarily to evaluvate the //term

void push(int elem) 
{
	s[top] = elem; 
	top++;
}

//pop function this is used to get the element on top of s[]
int pop() 
{
	top--; 	//here we 
	return s[top];
}

int main() 
{
	char postfix[20], ch;	//postfix is used to get input and ch is used for checking each character
	int i, op1, op2, res;	//i is for the loop op1 op2 and res is for calculations
	printf("Postfix Expression Evaluvation\n");
	printf("Enter the expression : \n");
	scanf("%s", postfix);		//expression is obtained
	for (i=0; i<strlen(postfix); i++)  //loop to check each character till end of expression
	{
		ch = postfix[i];	//ch is set to i'th element of postfix ,starting from 0
		if (isdigit(ch))	//if its a digit it needs to be stored hence the check
		push(ch - '0');	//push is used to send the digit to s[] array and we negate 0 to make it an integer and convert from char to int
		else	//this states that there is an operation 
		{
			op2 = pop();		//so we need to get the last two digits to operate on hence pop is used 
			op1 = pop();
			switch (ch) 	//depending on the operator , the operation is performed
			{
				case '+': res = op1 + op2; break;
				case '-': res = op1 - op2; break;
				case '*': res = op1 * op2; break;
				case '/': res = op1 / op2; break;
				case '^': res = pow(op1,op2); break;
				default : printf("Invalid Entry");
			}
			push(res); 	//now we need to push the result obtained to the top of s
		}
	}
	printf("Result expression : % d", pop()); // here we print the final value . which is the top of s 
}
