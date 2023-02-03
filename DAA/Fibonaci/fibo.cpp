#include "fibo.h"

int fibo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int fibo_table(int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

int fibo_optimised(int n)
{
    int prev = 0;
    int n_prev = 1;
    int current;

    for (int i = 2; i <= n; i++)
    {
        current = prev + n_prev;
        n_prev = prev;
        prev = current;
    }

    return prev;
}