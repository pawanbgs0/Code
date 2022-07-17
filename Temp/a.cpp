#include <bits/stdc++.h>
using namespace std;

bool is_divisible(int num, vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % num != 0)
            return false;
    }
    return true;
}

int minOperations(vector<int>& nums, vector<int>& numsDivide)
{
    int res = 0;
    bool flag = false;
    
    sort(numsDivide.begin(), numsDivide.end());
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (is_divisible(nums[i], numsDivide))
        {
            flag = true;
            break;
        }
        else 
        {
            res++;
        }
    }
    
    if (!flag)
        return -1;
    
    return res;
}

int main()
{
    vector<int> nums = {2,3,2,4,3};
    vector<int> numsDivide = {9,6,9,3,15};

    sort(nums.begin(), nums.end());

    cout << minOperations(nums, numsDivide) << endl;
    return 0;
}