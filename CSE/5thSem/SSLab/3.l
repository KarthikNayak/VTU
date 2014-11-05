%{
#include <stdio.h>
int id = 0;
%}
%%
("int"|"float"|"long int"|"char") {int ch;
ch = input();
while(1){
if (ch == ',')
id++;
else if (ch == ';')
break;
ch = input();
}
id++;
}
%%
int main(int argc,char *argv[])
{
if(argc==2)
{
yyin=fopen(argv[1],"r");
yylex();
printf("\n Number of ids=%d",id);
}
}

int yywrap()
    {
	return 1;
    }
