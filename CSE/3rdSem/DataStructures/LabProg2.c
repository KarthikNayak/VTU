/* Takes a regular expression and converts it a postfix expression. 
characters are taken as input and we assume that each character is postive*/

//Header Files
#include <conio.h>      //For Clear Screen Function
#include <stdio.h>      //For Std Input and Output
#include <ctype.h>      //For String Length 
#include <stdlib.h> 	

//Pre-pocessor derivatives

#define MAX 20;

//Global Variables

char s[MAX];
int top=0;

void push(char elem) 
{
	top++;
	s[top] = elem;
}

int pop() 
{
	top--;
	return s[top];
}

int precedence(char elem)
{
	switch(elem)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
		case '(':
		case '#':return 0;
	}
}

void main()
{
	char infix[MAX],postfix[MAX],ch;
	int i=0,j=0;
	clrscr();
	printf("Enter the infix expression\n");
	scanf("%s,&infix");
	push('#');
	for(i=0;i<strlen(infix);i++)
	{
		ch=infix[i];
		if(isalnum(ch))
			postfix[j++]=ch;
		else if(ch=='(')
			push(ch);
		else if(ch==')')
		{
			while(s[top]!='(')
				postfix[j++]=pop();
		}
		else
		{
			while(precedence(s[top]>=precedence(ch)))
				postfix[j++]=pop();
			push(ch);		
		}
	}
	while(s[top]!='#')
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("postfix expression conversion is %s\n",postfix );
	getch();
}
