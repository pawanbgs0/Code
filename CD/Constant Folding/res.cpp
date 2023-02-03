#include <bits/stdc++.h>
using namespace std;

bool is_number(string st);
bool is_op(string st);
double solve(double num1, double num2, string op);
vector<string> constFolding(vector<string> st);

int main()
{
    vector<string> st;
    vector<string> result;
    int size;

    cout << "Enter the size of st: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string temp;
        cout << "Enter at index " << i << ": ";
        cin >> temp;
        st.push_back(temp);
    }
    

    result = constFolding(st);

    cout << endl << "The resultult is: ";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}



bool is_number(string st)
{
    if (!(st[0] >= '0' && st[0] <= '9'))
        return false;

    if(st.size() > 1)
        return true;

    if (st[0] >= '0' && st[0] <= '9')
        return true;

    return false;
}


bool is_op(string st)
{
    if(st.size() != 1)
        return false;

    if(st[0] == '+' || st[0] == '-' || st[0] == '*' || st[0] == '/')
        return true;

    return false;
}

double solve(double num1, double num2, string op)
    {
        if (op[0] == '+')
            return num1 + num2;
        
        if (op[0] == '-')
            return num1 - num2;
        
        if (op[0] == '*')
        {
            return num1 * num2;
        }
        if (num2 != 0)
            return num1 / num2;
        
        return INT_MAX;
    }


vector<string> constFolding(vector<string> st)
{
    vector<string> result;
    float calresult;
    float num1, num2;
    string op;
    queue<string> q;

    for (int i = 0; i < st.size(); i++)
    {
        if(is_op(st[i]))
        {
            op = st[i];

            if(i > 0 && is_number(st[i - 1]))
            {
                num1 = stof(st[i - 1]);

                if(i + 1 < st.size() && is_number(st[i + 1]))
                {
                    num2 = stof(st[i + 1]);

                    calresult = solve(num1, num2, op);
                    q.pop();
                    q.push(to_string(calresult));
                    i += 2;
                }
            }

            q.push(op);
        }
        else
            q.push(st[i]);
    }

    while (!q.empty())
    {
        string st = q.front();
        q.pop();
        result.push_back(st);
    }

    return result;
}