#include <bits/stdc++.h>
using namespace std;

bool is_available(int num, vector<int> &special)
{
    int start = 0, end = special.size() - 1;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
        
        if (special[mid] == num)
            return true;
        
        else if (special[mid] < num)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 6, 8};

    cout << is_available(-2, arr);
    return 0;
}


/*class Solution {
public:
    bool is_available(int num, vector<int> &special)
    {
        int start = 0, end = special.size() - 1;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            
            if (special[mid] == num)
                return true;
            
            else if (special[mid] < num)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return false;
    }
    
    int helper(int startIndex, int endIndex, vector<int> &special, vector<int> &dp, int &ans)
    {
        if (endIndex < startIndex)
            return 0;
        
        if (endIndex == startIndex)
        {
            if (!is_available(endIndex, special))
                return 1;
            else 
                return 0;
        }
        
        int left = 0, right = 0;
        
        if (!is_available(endIndex, special))
            left = 1 + helper(startIndex, endIndex - 1, special, dp, ans);
        else
            endIndex--;
        
        ans = max(ans, left);
        return max(left, ans);
    }
    
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        vector<int> dp(top, -1);
        int ans = -1e8;
        return helper(bottom, top, special, dp, ans);
    }
};*/











/*class Solution {
public:
    bool is_available(int num, vector<int> &special)
    {
        int start = 0, end = special.size() - 1;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            
            if (special[mid] == num)
                return true;
            
            else if (special[mid] < num)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return false;
    }
    
    int helper(int startIndex, int endIndex, vector<int> &special)
    {
        int ans = 0, maxi = 0;
        
        sort(special.begin(), special.end());
        
       for (int i = startIndex; i <= endIndex; i++)
       {
           if (!is_available(i, special))
           {
               ans++;
               maxi = max(maxi, ans);
           }
           else
               ans = 0;
       }
        return maxi;
    }
    
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        return helper(bottom, top, special);
    }
};*/


/*
    int maxConsecutive(int startIndex, int endIndex, vector<int>& special) 
    {
        int ans = 0, maxi = 0, k = 0, test;
        
        sort(special.begin(), special.end());
        
        
       for (int i = startIndex; i <= endIndex; i++)
       {
           if (k < special.size())
            test = special[k];
           
           if (i != test)
           {
               ans++;
               maxi = max(maxi, ans);
           }
           else
           {
               ans = 0;
               if (k < special.size())
                k++;
           }
       }
        return maxi;
    }
};*/