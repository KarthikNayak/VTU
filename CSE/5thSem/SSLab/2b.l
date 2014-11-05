%{
#include <stdio.h>
int flag = 0;
%}
%%
([aA][nN][Dd])|([bB][uU][tT])|([oO][Rr])|([nN][oO[Tt]]) {flag = 1;}

[\n] {return 0;}
%%
int main()
    {
	printf("enter the sentence\n");
	yylex();
	if(flag == 1)
	    printf("compound statement\n");
	else
	    printf("simple statement\n");
	return 0;
    }
int yywrap()
    {
	return 0;
    }
