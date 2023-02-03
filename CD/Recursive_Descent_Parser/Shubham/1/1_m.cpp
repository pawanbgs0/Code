#include <bits/stdc++.h>
using namespace std;

void E(string   str, int &i );
void F(string   str, int &i );

void E(string str, int& i)
{
    if (str[i] == 'i')
    {
        i++;
        F(str, i);
    }
}

void F(string str, int& i)
{
    char element = str[i];

    if (element == '+')
    {
        i++;
        
        if (str[i] == 'i')
        {
            i++;
            F(str, i  );
        }
    }
    else
        return;
}


int main()
{
    string str;
    int i = 0;

    cout << "Enter string ";
    getline(cin, str);

    str += '$';

    E(str, i);

    if (str[i] == '$')
        cout << "successful parsing" << endl;
    else
        cout << "unsuccessful parsing" << endl;

    return 0;
}