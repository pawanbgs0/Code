%{
#include <stdio.h>
int v = 0, op = 0, id = 0, flag = 0;
%}%%
[a-zA-Z]+[0-9a-zA-Z]* {id++; printf("\n Identifer ");ECHO;}
[+|"-"|*|/|=] {op++; printf("\n Operator "); ECHO;}
"(" {v++;}
")" {v--;}
";" {flag = 1;}
.|\n {;}
%%

int yywrap()
{
    return 1;
}
int main()
{
    printf("Enter the Expression\n");
    yylex();
    printf("After yylex");
    if((op+1)==id && v == 0 && flag == 0)
    {
        printf("The given expression is valid.\n");
        printf("The no of identifiers are %d .\n", id);
    }

    return 0;
}
