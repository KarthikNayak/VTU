%{
#include<stdio.h>
%}
%token C N
%%
s: C s1
s1: N C
| ;
%%
main()
{
printf("enter a string:");
if(yyparse()==0)
printf("valid string\n");
}
yyerror()
{
printf("\n invalid string");
return 0;
}
yywrap()
{
return 1;
}
