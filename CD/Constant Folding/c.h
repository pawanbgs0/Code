#include <bits/stdc++.h>
using namespace std;

bool is_digit(string st);
bool is_operator(string st);
double eval(double num1, double num2, string op);
vector<string> constant_folding(vector<string> input);