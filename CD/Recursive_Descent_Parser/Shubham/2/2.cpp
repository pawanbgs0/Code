#include "2.h"

void E(string  str, int &i )
{
    T( str, i );
    Edash( str, i );
}


void Edash(string  str, int &i )
{
    if ( str[i] == '+')
    {
        i++;
        T( str, i );
        Edash( str, i );
    }
    else
        return;
}


void T(string  str, int &i )
{
    F( str, i );
    Tdash( str, i );
}


void Tdash(string  str, int &i )
{
    if ( str[i] == '*')
    {
        i++;
        F( str, i );
        Tdash( str, i );
    }
    else
        return;
}


void F(string  str, int &i )
{
    if ( str[i] == '(')
    {
        i++;
        E( str, i );

        if ( str[i] == ')')
        {
            i++;
            return;
        }
    }
    else if ( str[i] == 't')
    {
        i++;
        return;
    }
}