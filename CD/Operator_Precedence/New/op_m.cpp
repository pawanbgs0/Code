#include "op.h"

int main()
{
    string input;// = "t+t";

    cout << "Enter the input string: ";
    getline(cin, input);

    set<char> terminals = input_terminals();

    map<pair<char, char>, char> table = calculate_precedence_talbe(terminals);

    parsing_process(input, table);
    return 0;
}