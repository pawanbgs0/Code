#include "fibo.h"

int main()
{
    int n;

    cout << "Enter the size of N: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    // cout << fibo(7, dp) << endl;
    // cout << fibo_table(n) << endl;
    cout << fibo_optimised(n) << endl;
    return 0;
}