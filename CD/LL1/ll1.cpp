#include "ll1.h"


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

string find_production_helper(unordered_map<char, vector<string>> grammar, char terminal, char variable)
{
    vector<string> production = grammar[variable];

    for (int i = 0; i < production.size(); i++)
    {
        for (int element = 0; element < production[i].size(); element++)
        {
            if ((int)element >= 65 && (int)element <= 90)
                find_production_helper(grammar, terminal, element);

            else if (element == terminal)
                return production[i];
        }
    }

    return "NULL";
}

unordered_set<string> find_production(unordered_map<char, vector<string>> grammar, char terminal)
{
    unordered_set<string> res;

    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        vector<string> rhs = it->second;

        for (int i = 0; i < rhs.size(); i++)
        {
            string item = rhs[i];

            for (int index = 0; index < item.size(); index++)
            {
                char element = item[index];

                if ((int)element >= 65 && (int)element <= 90)
                {
                    string midres = find_production_helper(grammar, terminal, element);

                    if (midres != "NULL")
                        res.insert(midres);
                }

                if (element == terminal)
                    res.insert(rhs[i]);
            }
        }
    }

    return res;
}


map<pair<char,char>, unordered_set<string>> construct_ll1_parse_table(unordered_map<char, vector<string>> grammar) // map<pair<variable, terminal>, unordered_set<list of productios>> 
{
    map<pair<char, char>, unordered_set<string>> table;
    
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        char variable = it->first;
        unordered_set<char> first_of_variable = first(variable, grammar);

        for (auto first_it = first_of_variable.begin(); first_it != first_of_variable.end(); first_it++)
        {
            if (*first_it == '#') // if the first contains a Epsilion
            {
                unordered_set<char> all_follow = follow(variable, grammar);

                for (auto follow_it = all_follow.begin(); follow_it != all_follow.end(); follow_it++)
                {
                    char f_terminal = *follow_it;
                    table[{variable, f_terminal}] = find_production(grammar, f_terminal);
                }
            }
            else
            {
                char terminal = *first_it;
                unordered_set<string> production = find_production(grammar, terminal);
                table[{variable, terminal}] = production;
            }
        }
    }

    return table;
}


/*..............................................Checkers................................................*/



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


bool is_right_recursive(unordered_map<char, vector<string>> grammar)
{
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        char lhs = it->first;
        vector<string> rhs = it->second;
        
        for (int index = 0; index < rhs.size(); index++)
        {
            int last_index = rhs[index].size() - 1;
            if (lhs == rhs[index][last_index])
                return true;
        }
    }

    return false;
}


bool is_ambiguous(unordered_map<char, vector<string>> grammar)
{
    if (is_left_recursive(grammar) && is_right_recursive(grammar))
        return true;

    return false;
}


bool is_ll1(unordered_map<char, vector<string>> grammar)
{
    map<pair<char, char>, unordered_set<string>> table;

    if (is_left_recursive(grammar) || is_ambiguous(grammar))
        return false;

    table = construct_ll1_parse_table(grammar);

    for (auto it = table.begin(); it != table.end(); it++)
    {
        if (it->second.size() > 1)
            return false;
    }

    return true;
}


/*.............................................Display Part.............................................*/


void display_sets(unordered_set<string> st)
{
    for (auto it = st.begin(); it != st.end(); it)
    {
        cout << *it;

        if (++it != st.end())
            cout << " / ";
    }
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

void display_first_follow(unordered_set<char> items)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


void display_ll1_parse_table(map<pair<char, char>, unordered_set<string>> table)
{
    for (auto it = table.begin(); it != table.end(); it++)
    {
        cout << it->first.first << "(" << it->first.second << "): ";
        display_sets(it->second);
        cout << endl;
    }
}