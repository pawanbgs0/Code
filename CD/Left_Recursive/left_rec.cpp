#include "left_rec.h"

char cut_lhs(string input, int startIndex)
{
    char res;
    for (int i = startIndex; i < input.size(); i++)
    {
        if (input[i] == '>')
            return input[i - 1];
    }
    cout << "The LHS is " << res << endl;
    return res;
}

vector<string> cut_rhs(string input, int startIndex)
{
    string midres;
    vector<string> res;

    int index = startIndex;

    while (input[index] != '>')
    {
        index++;
    }
    index++;

    for (int i = index; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            res.push_back(midres);
            return res;
        }

        else if (input[i] == '/')
        {
            res.push_back(midres);
            midres.clear();
        }
        else
            midres += input[i];

    }

    res.push_back(midres);

    return res;
}

unordered_map<char, vector<string>> add_grammar(string w)
{
    unordered_map<char, vector<string>> map;

    for (int i = 0; i < w.length(); i++)
    {
        char lhs = cut_lhs(w, i);
        vector<string> rhs = cut_rhs(w, i);

        map[lhs] = rhs;

        while (w[i] != ' ')
            i++;
    }

    return map;
}


bool is_left_recursive(unordered_map<char, vector<string>> grammar)
{
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        char lhs = it->first;
        vector<string> rhs = it->second;
        
        for (int index = 0; index < rhs.size(); index++)
        {
            if (lhs == rhs[index][0])
                return true;
        }
    }

    return false;
}

void display_rhs(vector<string> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i];

        if (i != input.size() - 1)
            cout << " / ";
    }
}


void display_grammar(unordered_map<char, vector<string>> grammar)
{
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        cout << it->first << " -> ";
        display_rhs(it->second);
        cout << endl;
    }
}