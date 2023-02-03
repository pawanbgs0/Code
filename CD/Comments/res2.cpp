#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string input;
    string code;// = "Ram /*aam khata hai But milne*/ kabhi nhi aata hai";
    int choice;
    bool loop = true;

    cout << "1. To check Single Line Comment in C / C++.\n2. To check Single Line Commnet in Python.\n3. To check Multi Line Comment in C / C++.\n4. To check Mutli Line Comment in Pythonn.\n5. Exit." << endl << endl;

    cout << "Choose the desired option by choosing a number: ";
    cin >> choice;


    while (loop)
    {
        switch (choice)
        {
            case 1: 
                    cout << "Enter the File Name with extension: ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin, input);

                    if (input[input.size() - 1] != 'c' && input[input.size() - 1] != 'p') 
                    {
                        cout << "Invalid File Name" << endl;
                        break;
                    }

                    code = file_to_string(input);

                    if (code == "NULL")
                    {
                        loop = false;
                        break;
                    }


                    if (single_line_comment_C(code))
                        cout << endl << "There exist some Single Line Comment in the file." << endl;
                    else 
                        cout << endl << "There doesn't exist Single Line Comment in the file." << endl;

                    loop = false;
                    break;
            
            case 2: 
                    cout << "Enter the File Name with extension: ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin, input);
                    
                    if (input.size() < 2 && input[input.size() - 1] != 'y' && input[input.size() - 2] == 'p') 
                    {
                        cout << "Invalid File Name" << endl;
                        break;
                    }

                    code = file_to_string(input);

                    if (single_line_comment_python(code))
                        cout << "There exist some Single Line Comment in the file." << endl;
                    else 
                        cout << "There doesn't exist Single Line Comment in the file." << endl;

                    loop = false;
                    break;

            case 3: 
                    cout << "Enter the File Name with extension: ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin, input);
                    
                    if (input[input.size() - 1] != 'c' && input[input.size() - 1] != 'p') 
                    {
                        cout << "Invalid File Name" << endl;
                        break;
                    }

                    code = file_to_string(input);

                    if (multi_line_comment_C(code))
                        cout << "There exist some Multi Line Comment in the file." << endl;
                    else 
                        cout << "There doesn't exist Multi Line Comment in the file." << endl;

                    loop = false;
                    break;
                
            case 4: 
                    cout << "Enter the File Name with extension: ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin, input);
                    
                    if (input.size() < 2 && input[input.size() - 1] != 'y' && input[input.size() - 2] == 'p') 
                    {
                        cout << "Invalid File Name" << endl;
                        break;
                    }

                    code = file_to_string(input);

                    if (multi_line_comment_python(code))
                        cout << "There exist some Multi Line Comment in the file." << endl;
                    else 
                        cout << "There doesn't exist Multi Line Comment in the file." << endl;

                    loop = false;
                    break;

            case 5:
                    loop = false;
                    break;

            default:
                    cout << "Please Enter a valid Choice: ";
        }
    }

    return 0;
}