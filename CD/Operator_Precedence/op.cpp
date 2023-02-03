#include "op.h"

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

/*..........................................Checkers...........................................*/


map<pair<char, char>, char> calculate_precedence_talbe(unordered_set<char> terminals)
{
    map<pair<char, char>, char> res;

    terminals.insert('$');

    for (auto it = terminals.begin(); it != terminals.end(); it++)
    {
        for (auto it2 = terminals.begin(); it2 != terminals.end(); it2++)
        {
            char input;

            cout << "Enter the Precedence over " << *it << " and " << *it2 << ": ";
            cin >> input;

            res[{*it, *it2}] = input;
        }
    }
    
    return res;
}


unordered_set<char> store_terminals(unordered_map<char, vector<string>> grammar)
{
    unordered_set<char> res;

    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        vector<string> rhs = it->second;

        for (int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs[i].size(); j++)
            {
                char element = rhs[i][j];

                if (!((int)element >= 65 && (int)element <= 90))
                    res.insert(element);
                
            }
        }
    }

    return res;
}



void parsing_process(string input, map<pair<char, char>, char> precedence_table)
{
    stack<char> st;
    int index = 0;

    st.push('$');
    input += "$";

    cout << input << endl;


    while (input[index] != '$')
    {
        char tos;

        if (!st.empty())
            tos = st.top();

        if (precedence_table[{input[index], tos}] == '>')
        {
            st.push(input[index]);
            index++;

            cout << input[index] << " Pushed." << endl;
        }
        else 
        {
            if (st.empty())
            {
                cout << "Error!" << endl;
                break;
            }
            char item = st.top();
            st.pop();

            cout << item << " Poped." << endl;
        }
    }

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


void display_precedence_table(map<pair<char, char>, char> table)
{
    for (auto it = table.begin(); it != table.end(); it++)
    {
        cout << it->first.first << "(" << it->first.second << "): ";
        cout << it->second;
        cout << endl;
    }
}