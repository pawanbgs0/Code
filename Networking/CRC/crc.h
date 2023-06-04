#include <bits/stdc++.h>
using namespace std;

bool validateMessage(string message);
string getCRC(string message, string tail);
bool isCorrect(string message, string tail);
string xorr(string s1, string s2);