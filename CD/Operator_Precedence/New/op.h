#include <bits/stdc++.h>
using namespace std;

set<char> input_terminals();
map<pair<char, char>, char> calculate_precedence_talbe(set<char> terminals);
void parsing_process(string input, map<pair<char, char>, char> precedence_table);
