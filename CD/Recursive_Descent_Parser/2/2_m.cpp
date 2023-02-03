#include "2.h"

int main()
{
    string input;
    int index = 0;
    bool valid = true;

    cout << "Enter the input string: ";
    getline(cin, input);

    input += "$";

    cout << endl << input << endl;

    E(input, index, valid);

    if (valid && input[index] == '$')
        cout << "Parsing Successful" << endl;
    else
        cout << "Unsuccessful" << endl;
    return 0;
}