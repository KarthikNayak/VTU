%{
#include<stdio.h>
#include<stdlib.h>
%}
%token N L
%left '+' '-'
%left '*' '/'
%%
S : P
 ;
P : P '+' P
 | P '-' P
 | P '*' P
 | P '/' P
 | '(' P ')'
 | N
 | L
;
%%
main()
{
 printf("enter valid expression\n");
 yyparse();
 printf("valid.\n");
}
yyerror()
{
 printf("INVALID EXPRESSION");
 exit(0);
}
int yywrap()
    {
	return 1;
    }
