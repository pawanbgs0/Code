#include "op.h"

int main()
{
    string input;// = "S>ASb/Cd A>a C>b/d";
    unordered_map<char, vector<string>> grammar;
    unordered_set<char> terminals; 
    map<pair<char, char>, char> precedence_table;

    string w = "t+t+t";

    cout << "Enter the Grammer in the form of string where each production is seperated by a space and the > should be used as arrow: ";
    getline(cin, input);

    grammar = add_grammar(input);
    terminals = store_terminals(grammar);

    // cout << "The terminals are: " << endl;
    // display_first_follow(terminals);
    
    // display_first_follow(terminals);
    // precedence_table = calculate_precedence_talbe(terminals);

    // cout << endl << "The given Grammar is: " << endl << endl;
    // display_grammar(grammar);
    // cout << endl;

    // display_precedence_table(precedence_table);

    parsing_process(w, precedence_table);

    return 0;
}