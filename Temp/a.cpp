#include <bits/stdc++.h>
using namespace std;



string greatestLetter(string s) 
{
    int start = 0, mid;
    string res = "";

    if (s.length() == 0)
        return res;

    sort(s.begin(), s.end());

    cout << s << endl;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            mid = i;
            break;
        }
    }
    
    cout << "mid is " << s[mid] << endl;

    while (start < mid && mid < s.length())
    {
        if (abs(s[start] - s[mid]) == 32)
        {
            res = s[start];
            start++;
            mid++;
            
            cout << 1  << "start++ and mid++" << " res is " << res << endl; 
        }

        else if (abs(s[start] - s[mid]) > 32)
        {
            start++;
            cout << 2 << " res is start++ " << res << endl; 
        }

        else 
        {
            mid++;
            cout << 3 << " res is mid++ " << s[mid] << endl; 
        }
    }    

    return res;    
}



int main()
{
    string s = "abzcdCEEEEZ";
    cout << greatestLetter(s);
    return 0;
}


