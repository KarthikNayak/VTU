%{
#include <stdio.h>
    int c = 0, lb = 0, rb = 0;
char a[20];
%}
%%
"//".*[^\n] {c++;}
"/*".*"*/" {c++;}
"/*"[^"*/"]* {lb++;}
[^"/*"]*"*/" {rb++;}
.* 
%%
int main(int argc, char *argv[])
{
    printf("Enter the String\n");
    scanf("%s", a);
    yyin = fopen(a, "r");
    yylex();
    lb = lb > rb ? lb : rb;
    printf("C : %d\n", c + lb);
    return 0;
}

int yywrap()
    {
	return 1;
    }
 
