#include "comment.h"


string file_to_string(string file_name_with_extension)
{
    fstream f;
    string temp;
    string res;

    ifstream src(file_name_with_extension); // checking if string is valid;
    

    if (src)
        f.open(file_name_with_extension, ios::in);
    else 
    {
        cout << "File does not exist." << endl;
        return "NULL";
    }

    while (true)
    {
        f >> temp;
        res += temp;
        
        if (f.eof())
            break;
    }

    return res;
}


bool single_line_comment_python(string code)
{
    bool quote_flag = false;

    for (int i = 0; i < code.size(); i++)
    {
        if (quote_flag == false && (code[i] == '\"' || code[i] == '\''))
            {
                quote_flag = true;
            }

        else if (quote_flag == true && (code[i] == '\"' || code[i] == '\''))
            {
                quote_flag = false;
            }

        if(quote_flag == false && code[i] == '#')
            return 1;
    }

    return false;
}

bool multi_line_comment_python(string code)
{
    bool started = false;
    bool changed = false;

    for (int i = 0; i < code.size(); i++)
    {
        if (i + 2 < code.size() && code[i] == '\"' && code[i+1] == '\"' && code[i+2] == '\"')
        {
            changed = true;

            if (started)
                started = false;
            else
                started = true;
        }

        
    }

    if (changed && !started)
        return true;

    return false;
}


bool single_line_comment_C(string code)
{
    bool quote_flag = false;

    for (int i = 0; i < code.size(); i++)
    {
        if (quote_flag == false && (code[i] == '\"' || code[i] == '\''))
            {
                quote_flag = true;
            }

        else if (quote_flag == true && (code[i] == '\"' || code[i] == '\''))
            {
                quote_flag = false;
            }

        if(quote_flag == false && i + 1 < code.size() && code[i] == '/' && code[i+1] == '/')
            return 1;
    }

    return false;
}


bool multi_line_comment_C(string code)
{
    bool started = false;
    bool changed = false;
    int index;
    bool quote_flag = false;

    for (int i = 0; i < code.size(); i++)
    {
        if (quote_flag == false && (code[i] == '\"' || code[i] == '\''))
        {
            quote_flag = true;
        }

        else if (quote_flag == true && (code[i] == '\"' || code[i] == '\''))
        {
            quote_flag = false;
        }
        

        if (quote_flag == false)
        {
            if (i + 2 < code.size() && code[i] == '/' && code[i+1] == '*')
            {
                index = i + 1;
                changed = true;
                started = true;
            }

            if (started == true && index != i && i + 2 < code.size() && code[i] == '*' && code[i+1] == '/')
            {
                started = false;
            }
        }
    }

    if (changed && !started)
        return true;

    return false;
}