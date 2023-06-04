#include <bits/stdc++.h>
using namespace std;

vector<string> group(string input, int groupSize);
string getCheckSum(vector<string> messages, int groupSize);
string addOne(string input);
string getNewMessage(string message, int groupSize);
bool isError(string message, int groupSize);


vector<string> group(string input, int groupSize)
{
    string temp;
    int size = groupSize;
    vector<string> res;

    for (int i = 0; i < input.size(); i++)
    {
        temp = "";
        size = groupSize;

        while (i < input.size() && size--)
        {
            temp += input[i];
            i++;
        }
        i--;

        if (temp.size() == groupSize)
            res.push_back(temp);
    }

    if (temp.size() < groupSize)
    {
        size = groupSize - temp.size();

        while (size--)
        {
            temp += '0';
        }

        res.push_back(temp);
    }

    return res;
}


string addOne(string input)
{
    char carry = '1';
    string res;

    for (int i = 0; i < input.size(); i++)
    {
        res += '0';
    }

    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (carry == '1')
        {
            if (input[i] == '0')
            {
                res[i] = '1';
                carry = '0';
            }
            else 
            {
                res[i] = '0';
                carry = '1';
            }
        }
        else // carry 0
        {
            if (input[i] == '0')
            {
                res[i] = '0';
                carry = '0';
            }
            else 
            {
                res[i] = '1';
                carry = '0';
            }
        }
    }

    if (carry == '1')
    {
        string cres;
        cres += '1';
        cres += res;
        return cres;
    }

    return res;
}


string getCheckSum(vector<string> messages, int groupSize)
{
    // pair {carry, res}
    char carry = '0';
    string res;    

    for (int i = 0; i < groupSize; i++)
    {
        res += '0';
    }

    // cout << res << endl;

    for (auto &it: messages)
    {
        for (int i = groupSize - 1; i >= 0; i--)
        {
            if (carry == '1')
            {
                if (res[i] == '1' && it[i] == '1') // 3 ones
                {
                    carry = '1';
                    res[i] = '1';
                }
                else if (res[i] == '1' || it[i] == '1') // 2 ones
                {
                    carry = '1';
                    res[i] = '0';
                }
                else if (res[i] == '0' && it[i] == '0') // 1 ones
                {
                    carry = '0';
                    res[i] = '1';
                } 
            }
            else 
            {
                if (res[i] == '1' && it[i] == '1') // 2 ones
                {
                    carry = '1';
                    res[i] = '0';
                }
                else if (res[i] == '1' || it[i] == '1') // 1 ones
                {
                    carry = '0';
                    res[i] = '1';
                }
                else if (res[i] == '0' && it[i] == '0') // 0 ones
                {
                    carry = '0';
                    res[i] = '0';
                } 
            }
        }
    }

    // cout << "partial sum is " << res << endl;

    while (carry == '1')
    {
        string temp = addOne(res);
        // cout << "temp is " << temp << endl;

        if (temp.size() == groupSize)
        {
            res = temp;
            break;
        }
        else 
        {
            res = res.substr(1);
        }
    }

    // converting to one's compliment

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == '0')
        {
            res[i] = '1';
        }
        else
        {
            res[i] = '0';
        }
    }

    return res;
}

string getNewMessage(string message, int groupSize)
{
    vector<string> res;

    res = group(message, groupSize);

    string checkSum = getCheckSum(res, groupSize);
    
    return message + checkSum;
}

bool isError(string message, int groupSize)
{
    vector<string> input = group(message, groupSize);

    string res = getCheckSum(input, groupSize);

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == '1')
            return true;
    }

    return false;
}


int main()
{
    string message = "10101110";

    // for (auto &it: res)
    // {
    //     cout << it << endl;
    // }

    cout << getNewMessage(message, 4);

    return 0;
}