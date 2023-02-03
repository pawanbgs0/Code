// This is the test file where I'll implement common subexpression elimination

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;

    a = b+c+d;
    b = 3+b+c;
    c = a+b+c;
    return 0;
}