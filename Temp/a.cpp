#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string s;
    int index = 0;

    string s2 = "|";
    string s3 = "Leetcode";
    // s = s3.append(s2);

    index = index + s3.length() - 1;

    string s = "scott>=tiger";
    string delimiter = ">=";
    string token = s.substr(s.find(delimiter) + 1, s.length()); 

    // cout << s << index;
    cout << token;
    return 0;
}