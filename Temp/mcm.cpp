#include <bits/stdc++.h>
using namespace std;

int mcm(int i, int j, vector<int> &arr)
{
    if(i == j)
        return 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int res = arr[i - 1] + arr[k] + arr[j] + mcm(i, k, arr) + mcm(k + 1, j, arr);
        mini = min(mini, res);
    }

    return mini;
}

int mcm_table(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int> (arr.size()));

    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][i] = 0;
    }

    for (int i = arr.size() - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int res = arr[i - 1] + arr[k] + arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, res);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][arr.size() - 1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};

    cout << mcm(0, arr.size() - 1, arr) << endl;
    cout << mcm_table(arr) << endl;

    return 0;
}