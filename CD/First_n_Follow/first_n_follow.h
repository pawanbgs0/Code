/* Calculation of first and follow set */

#include <bits/stdc++.h>
using namespace std;

// Grammar Part
    char cut_lhs(string input, int startIndex);
    vector<string> cut_rhs(string input, int startIndex);
    unordered_map<char, vector<string>> add_grammar(string w);


// Functions
    void first_helper(char input, unordered_map<char, vector<string>> grammar, unordered_set<char> &res);
    unordered_set<char> first(char input, unordered_map<char, vector<string>> grammar);

    void follow_helper(char input, unordered_map<char, vector<string>> grammar, unordered_set<char> &res);
    unordered_set<char> follow(char input, unordered_map<char, vector<string>> grammar);
    


// Display Part
    void display_rhs(vector<string> input);
    void display_grammar(unordered_map<char, vector<string>> grammar);
    void display_first_follow(unordered_set<char> items);
