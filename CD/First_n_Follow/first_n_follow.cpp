#include "first_n_follow.h"


/*.............................................Grammar Part.............................................*/


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


/*............................................Functions.............................................*/



void first_helper(char input, unordered_map<char, vector<string>> grammar, unordered_set<char> &res)
{
    vector<string> rhs = grammar[input];

    for (int index = 0; index < rhs.size(); index++)
    {
        char element = rhs[index][0];
        if ((int)element >= 65 && (int)element <= 90)
        {
            first_helper(element, grammar, res);
        }
        else
            res.insert(element);
    }
}

unordered_set<char> first(char input, unordered_map<char, vector<string>> grammar)  // ASCII of A -> 65, Z -> 90, a -> 97, z -> 122
{
    unordered_set<char> res;

    first_helper(input, grammar, res);

    return res;
}

void follow_helper(char input, unordered_map<char, vector<string>> grammar, unordered_set<char> &res)
{
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        vector<string> rhs = it->second;

        if (input == 'S')
            res.insert('$');

        for (int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs[j].size(); j++)
            {
                char element = rhs[i][j];
                
                if (element == input)
                {
                    char next_element;

                    if (j + 1 <= rhs[j].size())
                        next_element = rhs[i][j+1];
                    
                    else 
                    {
                        follow_helper('S', grammar, res);
                    }

                    if ((int)next_element >= 65 && (int)next_element <= 90)
                    {
                        unordered_set<char> first_of_next_element = first(next_element, grammar);

                        for (auto it = first_of_next_element.begin(); it != first_of_next_element.end(); it++)
                        {
                            res.insert(*it);
                        }
                    }
                    
                    else
                        res.insert(next_element);
                }
            }
        }
    }
}


unordered_set<char> follow(char input, unordered_map<char, vector<string>> grammar)
{
    unordered_set<char> res;

    follow_helper(input, grammar, res);

    return res;
}


/*.............................................Display Part.............................................*/


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

void display_first_follow(unordered_set<char> items)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}