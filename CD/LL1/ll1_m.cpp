#include "ll1.h"

// Note: '#' is represented as Epsilion

int main()
{
    string input;// = "S>ASb/Cd A>a C>b/d";
    unordered_map<char, vector<string>> grammar;
    map<pair<char, char>, unordered_set<string>> table;

    cout << "Enter the Grammer in the form of string where each production is seperated by a space and the > should be used as arrow: ";
    getline(cin, input);

    grammar = add_grammar(input);
    table = construct_ll1_parse_table(grammar);

    cout << endl << "The given Grammar is: " << endl << endl;
    display_grammar(grammar);
    cout << endl;

    cout << "The LL(1) Parse Table of above Grammar is: " << endl << endl;
    display_ll1_parse_table(table);
    cout << endl;

    if (is_ll1(grammar))
        cout << "And the above grammar is LL(1)." << endl;

    else 
        cout << "And the above grammar is not LL(1)." << endl;
  
    return 0;
}