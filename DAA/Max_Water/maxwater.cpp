#include <bits/stdc++.h>
using namespace std;

int maxStore(vector<int>& height) 
{
    int maxwater = INT_MIN;
    int current;
    int i = 0, j = height.size() - 1;
    
    while (i <= j)
    {
        current = min(height[i], height[j]) * (j - i);
        maxwater = max(current, maxwater);
        
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxwater;
}


int main()
{
    vector<int> height;
    int size;

    cout << "Enter the total number of blocks: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int temp;
        cout << "Enter the height of block " << i + 1 << ": ";
        cin >> temp;
        height.push_back(temp);
    }

    cout << "The maximum water that can be stored is of " << maxStore(height) << " unit square." << endl;
    return 0;
}