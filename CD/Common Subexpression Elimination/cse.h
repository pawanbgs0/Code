#include <bits/stdc++.h>
using namespace std;

string file_read(string file_name_with_txt);
string get_variable(string input, int index);
vector<string> make_tokens(string input);
void possible_subsequences(int index, vector<int> &midres, vector<vector<int>> &res); // list of all 2 length subsequences;
string longest_common_substring(vector<string> tokens, int st1_index, int st2_index);
vector<string> all_possible_common_substring(vector<string> tokens);
vector<string> beautify_common_subexpressions(vector<string> expressions); // remove extra operators at the start and same expressions
string replace_string_with_another(string original_string, string to_replace, string to_replace_with);
void append_file(string input_file_name_with_ext, vector<string> beautified_expression);


//header file