%{
#include <stdio.h>
#include <stdlib.h>
%}
%token A B
%%
S : A S B
|
;
%%
main()
{
    printf("Enter the string\n");
    yyparse();
    printf("Valid.\n");
}
yyerror()
{
printf("invalid string\n");
exit(0);
}
yywrap()
{
return 1;
}
