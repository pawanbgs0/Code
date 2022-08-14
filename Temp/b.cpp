#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) 
{
    int j = 0, zeros = 0;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeros++;
        }
        else
            nums[j++] = nums[i];
    }
    
    for (int i = 0; i < zeros; i++)
    {
        nums[j++] = 0;
    }
}

int main()
{
    vector<int> a  ={1, 0, 0, 3, 1, 2};
    moveZeroes(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}