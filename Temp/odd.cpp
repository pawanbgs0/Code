#include <bits/stdc++.h>
using namespace std;


int maxSumOddLengthSubarrays(vector<int> &arr, int& index1, int& index2) 
{
    int sum = 0, ans = INT_MIN;
    bool flag = true;

    for(int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            if (flag)
            {
                sum += arr[j];
                flag = false;
            }
            else
            {
                    sum -= arr[j];
                    flag = true;
            }

            // cout << "sum is " << sum << endl;    

            if(((j + 1 - i) & 1) == 1)
            {
                if (sum > ans) 
                {
                    ans = sum;
                    index1 = i;
                    index2 = j;

                    // cout << "ans is " << ans << " index1 is " << index1 <<  " index2 is " << index2 << endl;
                }
                // ans = max(ans, sum);
            }
        }
    }
    return ans; 
}    

int solve(vector<int> &arr)
{
    int index1, index2;
    int left_size;
    int maxOddSum;
    int current_sum = 0;
    bool flag = true;

    maxOddSum = maxSumOddLengthSubarrays(arr, index1, index2);
    left_size = arr.size() - 1 - index2;

    // cout << "index2 is " << index2 << endl;

    for (int i = 0; i < index1; i++) //before index1 sum
    {
        if (flag)
            {
                current_sum += arr[i];
                flag = false;
            }
            else
            {
                    current_sum -= arr[i];
                    flag = true;
            }
    }

    
    if ((index1 + 1) % 2 == 0)
        flag = true;
    else 
        flag = false;

    for (int i = index2 + 1; i < arr.size(); i++) //after index2 sum
    {
        if (flag)
            {
                current_sum += arr[i];
                flag = false;
            }
            else
            {
                    current_sum -= arr[i];
                    flag = true;
            }
    }

    // cout << "Current Sum is: " << current_sum << endl;

    if (left_size % 2 == 0)
        current_sum += maxOddSum;

    else
        current_sum -= maxOddSum;

    return current_sum;
}

int main()
{
    vector<int> arr = {1, 10, 1, 5, 2};

    int res = solve(arr);

    cout << res << endl;
    return 0;
}