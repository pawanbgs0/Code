#include "lexems.h"


int main()
{
    vector<string> keywords = {"auto", "break", "case" "char", "const", "continue", "default", "do", "double", "else", "enum", "extern","float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    vector<string> opera = {"+", "-", "*", "/", "%", "^"};
    vector<string> parenth = {"(", ")", "{", "}", "[", "]"};

    unordered_map<string, int> keywordsMap;
    unordered_map<string, int> operatorMap;
    unordered_map<string, int> parenthMap;
    Res result;

    string input;// = "int * ( ) - + ; 45 6 32 ] ";

    cout << "Enter the Input: ";
    getline(cin, input);

    for (int i = 0; i < keywords.size(); i++)
    {
        keywordsMap[keywords[i]]++;
    }

    for (int i = 0; i < opera.size(); i++)
    {
        operatorMap[opera[i]]++;
    }

    for (int i = 0; i < parenth.size(); i++)
    {
        parenthMap[parenth[i]]++;
    }

    helper(keywordsMap, operatorMap, parenthMap, result, input);

    cout << endl << endl;
    cout << "Total Number of keywords is: " << result.no_keywords << endl;
    cout << "Total Number of Operators is: " << result.no_operator << endl;
    cout << "Total Number of Parenthesis is: " << result.no_parenthesis << endl;
    cout << "Total Number of Blank Space is: " << result.no_blank << endl;
    cout << "Total Number of Seperator is: " << result.no_seperator << endl;
    cout << "Total Number of Number is: " << result.no_numbers << endl;

    return 0;
}