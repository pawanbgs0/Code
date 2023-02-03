/* Identification of LL1 Grammar */

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

    void find_production_helper(unordered_map<char, vector<string>> grammar, char terminal, vector<string> &res);
    unordered_set<string> find_production(unordered_map<char, vector<string>> grammar, char terminal);


    map<pair<char,char>, unordered_set<string>> construct_ll1_parse_table(unordered_map<char, vector<string>> grammar);



// Checkers
    bool is_left_recursive(unordered_map<char, vector<string>> grammar);
    bool is_right_recursive(unordered_map<char, vector<string>> grammar);
    bool is_ambiguous(unordered_map<char, vector<string>> grammar);
    bool is_ll1(unordered_map<char, vector<string>> grammar);
    


// Display Part
    void display_sets(unordered_set<string> st);
    void display_rhs(vector<string> input);
    void display_grammar(unordered_map<char, vector<string>> grammar);
    void display_first_follow(unordered_set<char> items);
    void display_ll1_parse_table(map<pair<char, char>, unordered_set<string>> table);


