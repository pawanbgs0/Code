#include "2.h"

void E(string input, int &index, bool &valid)
{
    T(input, index, valid);
    Edash(input, index, valid);
}


void Edash(string input, int &index, bool &valid)
{
    if (input[index] == '+')
    {
        index++;
        T(input, index, valid);
        Edash(input, index, valid);
    }
    else
        return;
}


void T(string input, int &index, bool &valid)
{
    F(input, index, valid);
    Tdash(input, index, valid);
}


void Tdash(string input, int &index, bool &valid)
{
    if (input[index] == '*')
    {
        index++;
        F(input, index, valid);
        Tdash(input, index, valid);
    }
    else
        return;
}


void F(string input, int &index, bool &valid)
{
    if (input[index] == '(')
    {
        index++;
        E(input, index, valid);

        if (input[index] == ')')
        {
            index++;
            return;
        }
    }
    else if (input[index] == 't')
    {
        index++;
        return;
    }
    else 
    {
        cout << "Invalid Input String." << endl;
        valid = false;
        return;
    }

    
}