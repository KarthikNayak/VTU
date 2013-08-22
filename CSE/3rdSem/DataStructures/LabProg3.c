/* This program takes a postfix expression and prints the resultant value , so entry should be integers and regular operators +,-,*,/,^. This is achieved by taking the input from an user
 and storing it in a char array called postfix */

//Header Files
#include <conio.h>      //For Clear Screen Function
#include <stdio.h>      //For Std Input and Output
#include <math.h>       //For the Power Function “^”
#include <ctype.h>      //For String Length 
//Global Variables

int s[20], top = 0;		//s[20] stores the characters, acts like a temporary storage

//push function takes characters and stores them in global array s temporarily to evaluvate the //term

void push(int elem) {
	s[top] = elem;
	top++;
}

//pop function
int pop() {
	top--;
	return s[top];
}

void main() {
	char postfix[20], ch;
	int i, op1, op2, res;
	clrscr();
	printf(“Postfix Expression Evaluvation\n”);
	printf(“Enter the expression : \n”);
	scanf(“ % s”, postfix);
	for (i = 0; i < strlen(postfix); i++) {
		ch = postfix[i];
		if (isdigit(ch))
		push(ch - ’0’)
	else
	{
		op2 = pop();
		op1 = pop();
		switch (ch)
		{
			case ‘+’: res = op1 + op2; break;
			case ‘-’: res = op1 - op2; break;
			case ‘*’: res = op1 * op2; break;
			case ‘/’: res = op1 / op2; break;
			case ‘^’: res = pow(op1, op2); break;
			default : printf(“Invalid Entry”);
		}
		push(res);
	}
}
printf(“Result expression : % d”, pop());
getch();
}
