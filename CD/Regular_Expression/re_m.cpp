#include "re.h"

int main()
{   
    string input;

    cout << "Enter the input string: ";
    getline(cin, input);

    // if (input.size() == 0 || (input.size() == 1 && input[0] == 'a'))
    // {
    //     cout << "Accepted at a*" << endl;
    // }

    if (input.size() == 3)
    {
        if (three(input))
        {
            cout << "Accepted at abb" << endl;
        }
    }
    else //if (input[input.size() - 1] == 'b')
    {
        if (two(input))
        {
            cout << "Accepted at a*b+" << endl;
        }
        else 
        {
            cout << "There must be a \'b\'" << endl;
            cout << "Not_Accepted" << endl;
        }
            
    }
    // else 
    // {
    //     if (one(input))
    //         cout << "Accepted at a*" << endl;
        
    //     else
    //         cout << "Not_Accepted" << endl;

    // }

    return 0;
}