%{
#include <stdio.h>
#include <stdlib.h>
%}
%token N
%left '+' '-'
%left '*' '/'
%%
S: P {printf("The result is : %d\n", $1); exit(0);}
P: P '+' P {$$ = $1 + $3;}
| P '-' P {$$ = $1 - $3;}
| P '*' P {$$ = $1 * $3;}
| P '/' P { if ($3 == 0) {printf("Invalid operation"); exit(0);}
		else $$ = $1 / $3;}
| '(' P ')'{$$ = $1;}
| N	{$$ = yylval;}
%%
main()
{
    printf("Enter an Expr :\n");
    yyparse();
}
yyerror()
{
printf("invalid string\n");
return 0;
}
yywrap()
{
return 1;
}
