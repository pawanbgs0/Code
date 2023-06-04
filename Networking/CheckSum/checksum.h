#include <bits/stdc++.h>
using namespace std;

vector<string> group(string input, int groupSize);
string getCheckSum(vector<string> messages, int groupSize);
string addOne(string input);
string getNewMessage(string message, int groupSize);
bool isError(string message, int groupSize);