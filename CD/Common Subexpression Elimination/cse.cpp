#include "cse.h"

// defination of all the functions at header file

string file_read(string file_name_with_ext)
{
    fstream f;
    string temp;
    string res;

    ifstream src(file_name_with_ext); // checking if string is valid;
    

    if (src)
    {
        f.open(file_name_with_ext, ios::in);
        while (getline (f, temp))
        {
            res += temp;
        } // this is taking last char twice
    }
    else 
        cout << "File does not exist." << endl;


    res.erase(remove(res.begin(), res.end(), '\t'), res.end());
    res.erase(remove(res.begin(), res.end(), ' '), res.end());
    return res;
}

string get_variable(string input, int index)
{
    string res;

    while (index >= 0 && (input[index] != ';' && input[index] != '{'))
    {
        res += input[index];
        index--;
    }
    reverse(res.begin(), res.end());
    // cout << "res is" << res << endl;
    return res;
}


vector<string> make_tokens(string input)
{
    string midres;
    vector<string> res;

    for (int i = 0; i < input.size(); i++)
    {
        if(input[i] == '=' && input[i+1] != '=')
        {
            // midres = get_variable(input, i - 1);
            i++;
            
            while(input[i] != ';')
            {
                midres += input[i];
                i++;
            }

            res.push_back(midres);
            midres.clear();
        }
    }

    return res;
}

void possible_subsequences(int index, vector<int> &midres, vector<vector<int>> &res)
{
    if (index < -1)
        return;

    if(index == -1) // comparing with -1 to get the value 0
    {
        if(midres.size() == 2)
            res.push_back(midres);

        // for (auto &it: midres)
        //     cout << it << " ";

        // midres.clear();

        return;
    }

    //take condition
    midres.push_back(index);
    possible_subsequences(index - 1, midres, res);
    //not_take condition
    midres.pop_back();
    possible_subsequences(index - 1, midres, res);
}

string longest_common_substring(vector<string> tokens, int st1_index, int st2_index)
{
    int longest_length = 0;
    string longest_substring;
    string s1, s2;

    s1 = tokens[st1_index];
    s2 = tokens[st2_index];

    for (int i = 0; i < s1.size(); i++) 
    {
        for (int j = 0; j < s2.size(); j++) 
        {
            if (s1[i] == s2[j]) 
            {
                // If we find a common character, check if the
                // rest of the substrings match
                int length = 1;
                int k = i + 1;
                int l = j + 1;
                while (k < s1.size() && l < s2.size() && s1[k] == s2[l]) 
                {
                    length++;
                    k++;
                    l++;
                }
                if (length > longest_length) 
                {
                    longest_length = length;
                    longest_substring = s1.substr(i, length);
                }
            }
        }
    }

    return longest_substring;
}

vector<string> all_possible_common_substring(vector<string> tokens)
{
    vector<string> res;
    string midres;
    vector<vector<int>> comparing_indeces;
    vector<int> temp;

    possible_subsequences(tokens.size() - 1, temp, comparing_indeces);

    // cout << "inside all_possible" << endl;
    for (int i = 0; i < comparing_indeces.size(); i++)
    {
        // cout << comparing_indeces[i][0] << " " << comparing_indeces[i][1] << endl;
        // cout << tokens[comparing_indeces[i][0]] << " " << tokens[comparing_indeces[i][1]] << endl;
        midres = longest_common_substring(tokens, comparing_indeces[i][0], comparing_indeces[i][1]);

        // cout << midres << endl;
        if(midres.size() >= 3)
            res.push_back(midres);
    }

    return res;
}

vector<string> beautify_common_subexpressions(vector<string> expressions)
{
    unordered_set<string> set;
    string midres;
    vector<string> res;

    for (int i = 0; i < expressions.size(); i++)
    {
        if(expressions[i][0] == '+' || expressions[i][0] == '-' || expressions[i][0] == '*' || expressions[i][0] == '/')
        {
            midres = expressions[i].substr(1);
            set.insert(midres);
        }
        else
            set.insert(expressions[i]);
    }

    for (auto &it: set)
    {
        res.push_back(it);
    }

    return res;
}


string replace_string_with_another(string original_string, string to_replace, string to_replace_with)
{
    // Find the position of the old string in the input string
    int pos = original_string.find(to_replace);
    while (pos != string::npos) 
    {
        // Replace old string with the new string
        original_string.replace(pos, to_replace.size(), to_replace_with);
        // Find the position of the old string again, starting from the end
        // of the new string that was just inserted
        pos = original_string.find(to_replace, pos + to_replace_with.size());
    }

    // Print modified string
    // cout << "Modified string: " << original_string << endl;

    return original_string;
}




void append_file(string input_file_name_with_ext, vector<string> beautified_expression)
{
    fstream out;
    string input;
    char temp;
    bool flag = false; // to mark the first search of {
    unordered_map<string, string> map;
    string added_var;
    
    ifstream src(input_file_name_with_ext);

    while(src.good())
    {
        src.get(temp);
        input += temp;
    }

    out.open("output.cpp", ios::out);

    for (int i = 0; i < input.size() - 1; i++)
    {
        if (!flag && input[i] == '{')
        {
            flag = true;

            added_var += "{";
            added_var += "\n";
            added_var += "\t";
            added_var += "int ";

            for (int j = 0; j < beautified_expression.size(); j++)
            {
                string v = "v" + to_string(j + 1);
                added_var += v;

                if (j != beautified_expression.size() - 1)
                    added_var += ", ";
                else 
                    added_var += ";";

                // linking the expression with variable
                cout << beautified_expression[j] << endl;
                map[v] = beautified_expression[j];
            }
            cout << "map";
        }

        else
            added_var += input[i];
    }

    string res;
    for (auto &it: map)
    {
        res = added_var;
        res = replace_string_with_another(res, it.second, it.first);
        added_var = res;
    }

    int count = 0;
    string final_res;
    flag = true;

    for (int i = 0; i < added_var.size(); i++)
    {
        if (added_var[i] == ';')
            count++;
        
        if(count == 3 && flag == true)
        {
            final_res += added_var[i];
            flag = false;
            for (auto &it: map)
            {
                string lhs = it.first;
                string rhs = it.second;

                cout << lhs << " " << rhs << endl;

                final_res += "\n\t";
                final_res += lhs;
                final_res += " = ";
                final_res += rhs;
                final_res += ";\n\t";
            }
        }
        else
            final_res += added_var[i];
    }

    out << final_res;
}