%{
#include <stdio.h>
    int op = 0, sym = 0, b = 0;
%}
%%
[+\-*/] {sym++; printf("%s is an operator", yytext);}
[a-zA-Z0-9] {op++; printf("%s is an operand", yytext);}
%%
int main(int argc, char *argv[])
{
    printf("Enter the String\n");
    yylex();
    lb = lb > rb ? lb : rb;
    printf("C : %d\n", c + lb);
    return 0;
}

int yywrap()
    {
	return 1;
    }
 
