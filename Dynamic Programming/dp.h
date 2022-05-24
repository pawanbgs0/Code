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