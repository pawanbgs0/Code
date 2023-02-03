/* Identification of Left Recursive Grammar */

#include <bits/stdc++.h>
using namespace std;

// Grammar Part
    char cut_lhs(string input, int startIndex);
    vector<string> cut_rhs(string input, int startIndex);
    unordered_map<char, vector<string>> add_grammar(string w);

// Checkers
    bool is_left_recursive(unordered_map<char, vector<string>> grammar);
    

// Display Part
    void display_rhs(vector<string> input);
    void display_grammar(unordered_map<char, vector<string>> grammar);
    