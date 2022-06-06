#include <bits/stdc++.h>
using namespace std;

int fibonacci(int num, vector<int> &dp);
int climb(int num, vector<int> &dp); // https://bit.ly/3t1Sjyx
int frog_jump(int index, vector<int> &heights, vector<int> &dp); //https://bit.ly/3JPcoOx
int subsquence_sum(int index, vector<int> arr, vector<int> &dp); //https://leetcode.com/problems/house-robber/
int subsquence_sumT(vector<int> arr); // above question in tabulation form
int ninja_training(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp); //https://bit.ly/3F4yl8z
int unique_paths(int rowIndex, int columnIndex, vector<vector<int>> &dp); //https://leetcode.com/problems/unique-paths/
int unique_paths_II(int rowIndex, int columnIndex, vector<vector<int>> &grid, vector<vector<int>> &dp); //https://leetcode.com/problems/unique-paths-ii/

int min_path_sum(int rowIndex, int columnIndex, vector<vector<int>> &grid, vector<vector<int>> &dp); //https://leetcode.com/problems/minimum-path-sum/

int minimumTotal(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp); //https://leetcode.com/problems/triangle/

int maxMatrixPathSum(int columnIndex, int rowIndex, int rowSize, vector<vector<int>> &matrix, vector<vector<int>> &dp); //https://workat.tech/courses/dynamic-programming-fglj0mglee3j/practice-problems-yc2idsnnw3nw/8a3cfa4234f7

/* call this function on all the rows of last column through main function and return the maximum of all*/

int cherryPickup(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp); //https://leetcode.com/problems/cherry-pickup-ii/

bool hasValidSubset(int index, int target, vector<int> &arr, vector<vector<int>> &dp);

bool canPartition(vector<int>& nums); //https://leetcode.com/problems/partition-equal-subset-sum/

int knapsack(int index, vector<int> weight, vector<int> value, int maxWeight, vector<vector<int>> &dp); //https://bit.ly/3KHpP3v

int knapsack_table(int );

int coin_change(int index, int amount, vector<int> &coins, vector<vector<int>> &dp); //https://leetcode.com/problems/coin-change-2/submissions/

int unboundedKnapsack(int index, int capacity, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp); //https://bit.ly/3IvPdXS

int unboundedKnapsack_table(int n, int w, vector<int> &profit, vector<int> &weight);

int maximumProfit(int index, int capacity, vector<int> prices, vector<vector<int>> &dp); //https://workat.tech/courses/dynamic-programming-fglj0mglee3j/practice-problems-yc2idsnnw3nw/26e281a03473

int maximumProfit_table(int n, vector<int> prices);

int longest_common_subsequence(int index1, int index2, string s1, string s2, vector<vector<int>> &dp);

int longest_common_subsequence_table(string s1, string s2);

string longest_common_subsequence_display(string s1, string s2);