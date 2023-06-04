#include "crc.h"

string xorr(string s1, string s2)
{
    string res;

    if (s1.size() != s2.size())
    {
        cout << "Invalid input for XOR: ";
        return "";
    }

    for (int i = 0; i < s1.size(); i++)
    {
        int num1 = s1[i] - '0';
        int num2 = s2[i] - '0';

        res += to_string(num1 ^ num2);
    }

    res = res.substr(1); // removing the leftmost bit as not required while division

    return res;
}


bool validateMessage(string message)
{
    for (auto &it: message)
    {
        if (it != '0' && it != '1')
            return false;
    }

    return true;
}


string getCRC(string message, string tail)
{
    string zeros;

    if (!validateMessage(message))
    {
        return "";
    }

    // Adding k - 1 bits;
    for (int i = 0; i < tail.size() - 1; i++)
    {
        message += '0';
    }

    // Adding zeros 
    for (int i = 0; i < tail.size(); i++)
    {
        zeros += '0';
    }
    
    int index = tail.size();
    string rem;

    rem = xorr(tail, message.substr(0, tail.size()));
    // cout << "message is " << message << endl;
    // cout << rem << endl;

    while (index < message.size())
    {
        // cout << rem << endl;
        rem += message[index++];
        
        if (rem[0] == '0')
        {
            // cout << "xoring " << rem << " and " << zeros;
            rem = xorr(rem, zeros);
            // cout << " the result is " << rem << endl;
        }
        else
        {
            // cout << "xoring " << rem << " and " << tail;
            rem = xorr(rem, tail);
            // cout << " the result is " << rem << endl;
        }
    }

    return rem;
}

bool isCorrect(string message, string tail)
{
    int index = tail.size();
    string rem;
    string zeros;

    // making zeros;
    for (int i = 0; i < tail.size(); i++)
    {
        zeros += '0';
    }

    rem = xorr(tail, message.substr(0, tail.size()));

    while (index < message.size())
    {
        rem += message[index++];
        
        if (rem[0] == '0')
        {
            rem = xorr(rem, zeros);
        }
        else
        {
            rem = xorr(rem, tail);
        }
    }

    if (stoll(rem) == 0)
        return true;

    return false;
}