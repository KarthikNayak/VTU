%{
#include <stdio.h>
    int c = 0, w = 0, l = 0, b = 0;
%}
%%
[\n] {l++; w++;}
[\t] {b++; w++;}
[ ] {b++; w++;}
[^\n\t] {c++;}
%%
int main(int argc, char *argv[])
{
    printf("Enter the String\n");
    yylex();
    printf("C : %d, L : %d, S : %d, W : %d\n", c, l, b, w);
    return 0;
}

int yywrap()
    {
	return 1;
    }
