// This is the test file where I'll implement common subexpression elimination

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int v1;
    int a, b, c, d;
	v1 = b+c;
	

    a = v1+d;
    b = 3+v1;
    c = a+v1;
    return 0;
}