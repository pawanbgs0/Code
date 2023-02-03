#include "1.h"

int main()
{
    string input;// = "i+i$";
    int index = 0;
    bool invalid = false;

    cout << "Enter the input string: ";
    getline(cin, input);

    input += '$';

    E(input, index, invalid);

    if (!invalid && input[index] == '$')
        cout << "Parsing Successful" << endl;
    else
        cout << "Unsuccessful" << endl;

    return 0;
}