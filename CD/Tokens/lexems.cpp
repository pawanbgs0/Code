#include "lexems.h"


void helper(unordered_map<string, int> keywordsMap, unordered_map<string, int> operatorMap, unordered_map<string, int> parenthMap, Res &result, string input)
{
    string st;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ';')
        {
            cout << "; is a seperator" << endl;
            result.no_seperator++;
        }

        else if (input[i] == ' ')
        {
            if (keywordsMap.find(st) != keywordsMap.end())
            {
                cout << st << " is a keyword" << endl;
                result.no_keywords++;
            }

            if (operatorMap.find(st) != operatorMap.end())
            {
                cout << st << " is a operator" << endl;
                result.no_operator++;
            }

            if (parenthMap.find(st) != parenthMap.end())
            {
                cout << st << " is a parenthesis" << endl;
                result.no_parenthesis++;
            }

            if (st[st.size() - 1] >= '0' && st[st.size() - 1] <= '9') 
            {
                cout << st << " is a Number" << endl;
                result.no_numbers++;
            }

            st.clear();
            result.no_blank++;            
        }

        else
        {
            st += input[i];
        }
    }
}