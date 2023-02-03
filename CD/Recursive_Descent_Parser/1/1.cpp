#include "1.h"

void E(string input, int& index, bool &invalid)
{
    if (input[index] == 'i')
    {
        index++;
        F(input, index, invalid);
    }
}

void F(string input, int& index, bool &invalid)
{
    char element = input[index];

    if (element == '+')
    {
        index++;
        
        if (input[index] == 'i')
        {
            index++;
            F(input, index, invalid);
        }
        else 
        {
            cout << "Invalid Pattern" << endl;
            invalid = true;
            return;
        }
    }
    else
        return;
}






// if (!((int)element >= 65 && (int)element <= 90)) // if not variable
//     {
//         match(input, index, '+');
//         match(input, index, element);
//         F(input, index);
//     }