#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &matrix, int index1, int index2, vector<vector<int>> &dp)
{
    int left, up;
    if (index1 == 0 || index2 == 0)
    {
        if (matrix[index1][index2] != -1)
            return 1;
        
        return 0;
    }
    
    if (dp[index1][index2] != -1)
        return dp[index1][index2];
    
    if (matrix[index1][index2] != -1)
    {
        left = 1 + helper(matrix, index1 - 1, index2, dp);
        up = 1 + helper(matrix, index1, index2 - 1, dp);
    }
    
    return left + up;
}

int main() 
{
    int A = 5, B = 2;
    int mid = (A - 1) / 2;
    
    vector<vector<int>> dp(A, vector<int> (A, -1));
    vector<vector<int>> matrix(A, vector<int> (A, 0));
    
    
    for (int i = mid - B; i <= mid + B; i++)
    {
        matrix[mid][i] = -1;
    }
    
    for (int i = mid - B; i <= mid + B; i++)
    {
        matrix[i][mid] = -1;
    }
    
    for (int i = mid - B; i <= mid + B; i++)
    {
        for (int j = mid - B; j <= mid + B; j++)
        {
            if (i == j)
                matrix[i][j] = -1;
            
            if (i + j == A - 1)
                matrix[i][j] = -1;
        }
    }
    

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
