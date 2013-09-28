/* Takes an infix expression and converts it a postfix expression. 
characters are taken as input and we assume that each character is postive*/

//Caution: Unless where explicitly defining a string, you must use single quotes and not double quotes. C will automatically add a null character to a double quoted string.

//Header Files
#include <stdio.h>
//For Std Input and Output
#include <ctype.h>   
//For string length    
#include <string.h>
//For checking whether alphabet/numerical		

//Pre-pocessor derivatives
//Here we take twenty to be the maximum size of input taken
#define MAX 20		

//Global Variables

char s[MAX];
/*Here array S is taken as a temporary array and we use to 
check the precedence of operators to basically know where each operator
must be place*/
int top=0;
/*top is used to keep the position of the last operator sent 
to the array s */


/*Push is used to push operators to the array s */
void push(char elem) 
{
	top++;
	s[top] = elem;
}

/*pop is used to get the last operator inserted to the array s*/
int pop() 
{
	return s[top--];
}

/*precedence is used to check the precedence of the operators being checked
notice that # is given 0 becasue it the the default value sent to s*/
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
	/*infix=input postfix=result to be obtained 
	ch=variable to keep each element of input*/
	int i=0,j=0;
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	push('#');
	/*we push # as we have given it the lowest value
	which I mention before in precedence*/
	//loop to go through each element of input
	for(i=0;i<strlen(infix);i++) 
	{
		ch=infix[i];
		//ch is given the i'th value of infix
		//if alphabet/number directly send it to postfix
		if(isalnum(ch))		
			postfix[j++]=ch;
		/*if opening bracket send it to array s 
		as opening bracket has highest importance*/
		else if(ch=='(')	
			push(ch);
		/*if closing braket everything in s has to sent 
		to the postfix so till opening bracket is found*/
		else if(ch==')')
		{
			while(s[top]!='(')
				postfix[j++]=pop();
				pop();
		}
		/*if just an operator we check it with the last operator
		and the operator with higher precedence is sent to postfix
		and ch is sent to array s*/
		else
		{
			while(precedence(s[top])>=precedence(ch))
				postfix[j++]=pop();
			push(ch);
		}
	}
	/*remaining operator is sent to postfix*/
	while(s[top]!='#')
		postfix[j++]=pop();
	postfix[j]='\0';
	/*end postfix and print it*/
	printf("postfix expression conversion is %s\n",postfix);
}
