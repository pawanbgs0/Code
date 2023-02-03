#include "c.h"

bool is_digit(string st)
{
    if (!(st[0] >= '0' && st[0] <= '9'))
        return false;

    if(st.size() > 1)
        return true;

    if (st[0] >= '0' && st[0] <= '9')
        return true;

    return false;
}


bool is_operator(string st)
{
    if(st.size() != 1)
        return false;

    if(st[0] == '+' || st[0] == '-' || st[0] == '*' || st[0] == '/')
        return true;

    return false;
}

double eval(double num1, double num2, string op)
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


vector<string> constant_folding(vector<string> input)
{
    vector<string> res;
    float calres;
    float num1, num2;
    string op;
    queue<string> midres;

    for (int i = 0; i < input.size(); i++)
    {
        if(is_operator(input[i]))
        {
            op = input[i];

            if(i > 0 && is_digit(input[i - 1]))
            {
                num1 = stof(input[i - 1]);

                if(i + 1 < input.size() && is_digit(input[i + 1]))
                {
                    num2 = stof(input[i + 1]);

                    calres = eval(num1, num2, op);
                    midres.pop();
                    midres.push(to_string(calres));
                    i += 2;
                }
            }

            midres.push(op);
        }
        else
            midres.push(input[i]);
    }

    while (!midres.empty())
    {
        string st = midres.front();
        midres.pop();
        res.push_back(st);
    }

    return res;
}