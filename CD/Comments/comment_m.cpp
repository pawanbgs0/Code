#include "comment.h"

/*Write a program to check whether a line in a code is comment line or not (include the signs of comment line for every programming language like C, C++, Python etc)*/


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