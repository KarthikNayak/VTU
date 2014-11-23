%{
#include <stdio.h>
    int c = 0, lb = 0, rb = 0;
char a[20];
char b[20];
%}
%%
"//".*[^\n] {c++;}
"/*".*"*/" {c++;}
"/*"[^"*/"]* {lb++;}
[^"/*"]*"*/" {rb++;}
[a-zA-Z0-9] {fprintf(yyout, "%s", yytext);}
.* 
%%
int main(int argc, char *argv[])
{
    printf("Enter the input file\n");
    scanf("%s", a);
    printf("Enter the output file\n");
    scanf("%s", b);
    yyin = fopen(a, "r");
    yyout = fopen(b, "w");
    yylex();
    lb = lb > rb ? lb : rb;
    printf("C : %d\n", c + lb);
    return 0;
}

int yywrap()
    {
	return 1;
    }
 
