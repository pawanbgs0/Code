#include <bits/stdc++.h>
using namespace std;

// Grammar Part
    char cut_lhs(string input, int startIndex);
    vector<string> cut_rhs(string input, int startIndex);
    unordered_map<char, vector<string>> add_grammar(string w);



map<pair<char, char>, char> calculate_precedence_talbe(unordered_set<char> terminals);
unordered_set<char> store_terminals(unordered_map<char, vector<string>> grammar);
void parsing_process(string input, map<pair<char, char>, char> precedence_table);


// Display Part
    void display_sets(unordered_set<string> st);
    void display_rhs(vector<string> input);
    void display_grammar(unordered_map<char, vector<string>> grammar);
    void display_first_follow(unordered_set<char> items);
    void display_precedence_table(map<pair<char, char>, char>);
