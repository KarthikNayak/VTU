%{
#include"y.tab.h"
%}
%%
[a-zA-Z]* {return C;}
[0-9]* {return N;}
\n {return 0;}
. {return yytext[0];}
%%
