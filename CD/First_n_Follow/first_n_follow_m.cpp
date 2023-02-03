#include "first_n_follow.h"

// Note: '#' is represented as Epsilion

int main()
{
    string input;// = "S>ASb/Cd A>a C>b/d";
    char variable;
    unordered_map<char, vector<string>> grammar;
    unordered_set<char> firsts, follows;
    

    cout << "Enter the Grammer in the form of string where each production is seperated by a space and the > should be used as arrow: ";
    getline(cin, input);

    cout << "Enter the Variable to find First and Follow Set: ";
    cin >> variable;

    grammar = add_grammar(input);
    firsts = first(variable, grammar);
    follows = follow(variable, grammar);

    cout << endl << "The given Grammar is: " << endl;
    display_grammar(grammar);
    cout << endl << endl;

    cout << "The First Set of " << variable << " is: ";
    display_first_follow(firsts);
    cout << endl;

    cout << "The Follow Set of " << variable << " is: ";
    display_first_follow(follows);

   
    return 0;
}