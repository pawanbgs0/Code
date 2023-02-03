#include <bits/stdc++.h>
using namespace std;

class Res
{
    public:
        int no_ident, no_numbers, no_keywords, no_blank, no_operator, no_seperator, no_parenthesis;
        Res()
        {
            no_ident = 0;
            no_numbers = 0;
            no_keywords = 0;
            no_blank = 0;
            no_operator = 0;
            no_seperator = 0;
            no_parenthesis = 0;
        }
};


void helper(unordered_map<string, int> keywordsMap, unordered_map<string, int> operatorMap, unordered_map<string, int> parenthMap, Res &result, string input);