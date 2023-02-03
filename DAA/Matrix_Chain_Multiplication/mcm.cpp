#include "mcm.h"

int mcm_recursive(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    int mini = INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] + arr[k] + arr[j] + mcm_recursive(i, k, arr, dp) + mcm_recursive(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int mcm_tabulation(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(),vector<int> (arr.size(), 0));

    for (int i = 1; i < dp.size(); i++)
    {
        dp[i][i] = 0;
    }

    for (int i = arr.size() - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int steps = arr[i - 1] + arr[k] + arr[j] + dp[i][k] +dp[k + 1][j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][arr.size() - 1];
}