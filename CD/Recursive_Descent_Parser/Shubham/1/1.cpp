#include "1.h"

void E(string   str, int &i );
void F(string   str, int &i );

void E(string str, int& i )
{
    if (str[i] == 'i')
    {
        i++;
        F(str, i  );
    }
}

void F(string str, int& i )
{
    char element = str[i];

    if (element == '+')
    {
        i++;
        
        if (str[i] == 'i')
        {
            i++;
            F(str, i  );
        }
    }
    else
        return;
}