#include "left_rec.h"

int main()
{
    string input;// = "S>ASb/CD A>a C>b/d";

    cout << "Enter the Grammer in the form of string where each production is seperated by a space and the > should be used as arrow: ";
    getline(cin, input);

    unordered_map<char, vector<string>> grammar = add_grammar(input);

    cout << "The given Grammar is: " << endl << endl;

    display_grammar(grammar);

    cout << endl << endl;

    if (is_left_recursive(grammar))
        cout << "And the above grammar is Left Resurcive." << endl;

    else 
        cout << "And the grammar is not Left Resurcive." << endl;
   
    return 0;
}