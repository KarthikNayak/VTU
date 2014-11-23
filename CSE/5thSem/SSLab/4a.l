%{
#include "y.tab.h"
%}
%%
[A-Za-z]+ {return L;}
[0-9]+ {return N;}
\n {return 0;}
. {return yytext[0];}
%%
