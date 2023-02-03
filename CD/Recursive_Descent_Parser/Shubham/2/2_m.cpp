#include <bits/stdc++.h>
using namespace std;

void E(string input, int &index );
void Edash(string input, int &index );
void T(string input, int &index );
void Tdash(string input, int &index );
void F(string input, int &index );

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
    else if ( str[i] == 'v')
    {
        i++;
        return;
    }
}



int main()
{
    string str;
    int i = 0;
    cout << "enter string ";
    getline(cin, str);
    str += "$";
    E(str, i);
    if (str[i] == '$')
        cout << "successful parsing" << endl;
    else
        cout << "unsuccessful parsing" << endl;
    return 0;
}