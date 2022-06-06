#include "dp.h"

int fibonacci(int num, vector<int> &dp)
{
    if (num <= 1)
        return num;

    if (dp[num] != -1)
        return dp[num];

    int prev = fibonacci(num - 1, dp);
    int prev2 = fibonacci(num - 2, dp);

    return dp[num] = prev + prev2;
}

int climb(int num, vector<int> &dp)
{
    if (num == 0 || num == 1)
        return 1;

    if (num < 0)
        return 0;

    if (dp[num] != -1)
        return dp[num];

    int one = climb(num - 1, dp);
    
    int two = climb(num - 2, dp);

    return dp[num] = one + two;
}

int frog_jump(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int one = frog_jump(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

    int two = INT_MAX;
    if (index > 1)
        two = frog_jump(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(one, two);
}


int subsquence_sum(int index, vector<int> arr, vector<int> &dp)
{
    if (index == 0)
        return arr[index];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = arr[index] + subsquence_sum(index - 2, arr, dp);
    int not_pick = subsquence_sum(index - 1, arr, dp);

    return dp[index] = max(pick, not_pick);
}

int subsquence_sumT(vector<int> arr)
{
    vector<int> dp(arr.size(), 0);

    dp[0] = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2]; // to counter negative index as from above code

        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
    }

    return dp[arr.size() - 1];
}

int ninja_training(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = INT_MIN;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[day][task]);
        }
        return maxi;
    }

    int maxi = INT_MIN;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + ninja_training(day - 1, task, points, dp);

            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int unique_paths(int rowIndex, int columnIndex, vector<vector<int>> &dp)
{
    if (rowIndex == 0 && columnIndex == 0)
        return 1;
    
    if (rowIndex < 0 || columnIndex < 0)
        return 0;

    if (dp[rowIndex][columnIndex] != -1)
        return dp[rowIndex][columnIndex];

    int top = unique_paths(rowIndex, columnIndex - 1, dp);
    int left = unique_paths(rowIndex - 1, columnIndex, dp);

    return dp[rowIndex][columnIndex] = top + left;
}

int unique_paths_II(int rowIndex, int columnIndex, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (rowIndex >= 0 && columnIndex >= 0 && grid[rowIndex][columnIndex] == 1)
        return 0;

    if (rowIndex == 0 && columnIndex == 0)
        return 1;
    
    if (rowIndex < 0 || columnIndex < 0)
        return 0;

    int top = unique_paths_II(rowIndex, columnIndex - 1, grid, dp);
    int left = unique_paths_II(rowIndex - 1, columnIndex, grid, dp);

    return left + top;
}

int min_path_sum(int rowIndex, int columnIndex, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (rowIndex < 0 || columnIndex < 0)
        return 214748364;
    
    if (rowIndex == 0 && columnIndex == 0)
        return grid[rowIndex][columnIndex];

    if (dp[rowIndex][columnIndex] != -1)
        return dp[rowIndex][columnIndex];

    int left = grid[rowIndex][columnIndex] + min_path_sum(rowIndex - 1, columnIndex, grid, dp);

    int top = grid[rowIndex][columnIndex] + min_path_sum(rowIndex, columnIndex - 1, grid, dp);

    return dp[rowIndex][columnIndex] = min(left, top);
}

int minimumTotal(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp)
{
    if (i == n)
        return triangle[i][j];
    
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + minimumTotal(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + minimumTotal(i+1, j+1, n, triangle, dp);

    return dp[i][j] = min(down, diagonal);
}

int maxMatrixPathSum(int columnIndex, int rowIndex, int rowSize, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (rowIndex < 0 || rowIndex > rowSize)
        return -1e8;

    if (columnIndex == 0)
        return matrix[columnIndex][rowIndex];

    int up = maxMatrixPathSum(columnIndex - 1, rowIndex, rowSize, matrix, dp);
    int dleft = maxMatrixPathSum(columnIndex - 1, rowIndex - 1, rowSize, matrix, dp);
    int dright = maxMatrixPathSum(columnIndex - 1, rowIndex - 1, rowSize, matrix, dp);

    return max(up, max(dleft, dright));
}


int cherryPickup(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 > grid[0].size() - 1 || j2 > grid[0].size() -1)
        return -1e8;
    
    if (i == grid.size() - 1)
    {
        if (j1 == j2)
            return grid[i][j1]; // as only one will pick
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e8;

    for (int r1 = -1; r1 <= 1; r1++) // for each step of r1
    {
        for (int r2 = -1; r2 <= 1; r2++)  // there will be three steps of r2
        {
            if (j1 == j2)
                maxi = max(maxi, grid[i][j1] + cherryPickup(i + 1, j1 + r1, j2 + r2, grid, dp));
            else 
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + cherryPickup(i + 1, j1 + r1, j2 + r2, grid, dp));
        }
    }
    return dp[i][j1][j2] = maxi;
}


bool hasValidSubset(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (index == 0)
        return arr[index] == target;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool not_pick = hasValidSubset(index - 1, target, arr, dp);
    bool pick = false;
        if (arr[index] <= target)
            pick = hasValidSubset(index - 1, target - arr[index], arr, dp);
    
    return dp[index][target] = pick || not_pick;
}


bool canPartition(vector<int>& nums)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return hasValidSubset(nums.size() - 1, target, nums, dp);
}


int knapsack(int index, vector<int> weight, vector<int> value, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= maxWeight)
            return weight[index];
        
        else 
            return 0;
    }

    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    int not_pick = knapsack(index - 1, weight, value, maxWeight, dp);
    int pick = INT_MIN;
    if (weight[index] <= maxWeight)
        pick = value[index] + knapsack(index - 1, weight, value, maxWeight - weight[index], dp);

    return dp[index][maxWeight] = max(pick, not_pick);
}


int coin_change(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (index == 0)
        return (amount % coins[0] == 0);

    int not_pick = coin_change(index - 1, amount, coins, dp);
    int pick = 0;
    if (coins[index] <= amount)
        pick = coin_change(index, amount - coins[index], coins, dp);

    return pick + not_pick;
}


int unboundedKnapsack(int index, int capacity, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (index == 0)
        return (capacity / weight[0]) * profit[index];
    
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    
    int not_pick = unboundedKnapsack(index - 1, capacity, profit, weight, dp);
    int pick = INT_MIN;
    if (weight[index] <= capacity)
        pick = profit[index] + unboundedKnapsack(index, capacity - weight[index], profit, weight, dp);
    
    return dp[index][capacity] = max(pick, not_pick);
}

int unboundedKnapsack_table(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(profit.size(), vector<int> (w + 1, 0));
    
    for (int capacity = 0; capacity <= w; capacity++)
    {
        dp[0][capacity] = (capacity / weight[0]) * profit[0];
    }
    
    for (int index = 1; index < profit.size(); index++)
    {
        for (int capacity = 0; capacity <= w; capacity++)
        {
            int not_pick = dp[index - 1][capacity];
            int pick = INT_MIN;
            if (weight[index] <= capacity)
                pick = profit[index] + dp[index][capacity - weight[index]];

            dp[index][capacity] = max(pick, not_pick);
        }
    }
    
    return dp[profit.size() - 1][w];
}


int maximumProfit(int index, int capacity, vector<int> prices, vector<vector<int>> &dp)
{
	
	if (index == 0)
		return capacity * prices[index];
	
	if (dp[index][capacity] != -1)
		return dp[index][capacity];
	
	int not_pick = maximumProfit(index - 1, capacity, prices, dp);
	int pick = INT_MIN;
	if (index + 1 <= capacity)
		pick = prices[index] + maximumProfit(index, capacity - (index + 1), prices, dp);
	
	return dp[index][capacity] = max(pick, not_pick);
}

int maximumProfit_table(int n, vector<int> prices) 
{
	vector<vector<int>> dp(prices.size(), vector<int> (n + 1, -1));
	
	for (int capacity = 0; capacity <= n; capacity++)
	{
		dp[0][capacity] = capacity * prices[0];
	}
	
	for (int index = 1; index < prices.size(); index++)
	{
		for (int capacity = 0; capacity <= n; capacity++)
		{
			int not_pick = dp[index - 1][capacity];
			int pick = INT_MIN;

			if (index + 1 <= capacity)
				pick = prices[index] + dp[index][capacity - (index + 1)];

			dp[index][capacity] = max(pick, not_pick);
		}
	}
	return dp[prices.size() - 1][n];
}


int longest_common_subsequence(int index1, int index2, string s1, string s2, vector<vector<int>> &dp)
{
    if (index1 == 0 || index2 == 0)
        return 0;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    if (s1[index1 - 1] == s2[index2 - 1])
        return dp[index1][index2] = 1 + longest_common_subsequence(index1 - 1, index2 - 1, s1, s2, dp);

    return dp[index1][index2] = max(longest_common_subsequence(index1 - 1, index2, s1, s2, dp), longest_common_subsequence(index1, index2 - 1, s1, s2, dp));
}

int longest_common_subsequence_table(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, 0));

    for (int index2 = 0; index2 <= s2.length(); index2++)
    {
        dp[0][index2] = 0;
    }

    for (int index1 = 0; index1 <= s1.length(); index1++)
    {
        dp[index1][0] = 0;
    }

    for (int index1 = 1; index1 <= s1.length(); index1++)
    {
        for (int index2 = 1; index2 <= s2.length(); index2++)
        {
            if (s1[index1 - 1] == s2[index2 - 1])
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];

            else
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    return dp[s1.length()][s2.length()];
}

string longest_common_subsequence_display(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, 0));

    for (int index2 = 0; index2 <= s2.length(); index2++)
    {
        dp[0][index2] = 0;
    }

    for (int index1 = 0; index1 <= s1.length(); index1++)
    {
        dp[index1][0] = 0;
    }

    for (int index1 = 1; index1 <= s1.length(); index1++)
    {
        for (int index2 = 1; index2 <= s2.length(); index2++)
        {
            if (s1[index1 - 1] == s2[index2 - 1])
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];

            else
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    // Copied the above function code to get the dp table;
    string ans = "";
    int index1 = s1.length();
    int index2 = s2.length();
    int strIndex = dp[s1.length()][s2.length()] - 1;

    for (int i = 0; i < dp[s1.length()][s2.length()]; i++) //initialized a dummy string with the resultant size;
    {
        ans += '$';
    }

    while (index1 > 0 && index2 > 0)
    {
        
    }

}