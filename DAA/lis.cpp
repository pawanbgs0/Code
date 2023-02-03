#include <bits/stdc++.h>
using namespace std;


int helper(int index, int prev, vector<int> &A)
{
	if (index == A.size() - 1)
	{
		if (A[index] > prev)
			return 1;
		
		return 0;
	}
	
	int take = INT_MIN;
	if (A[index] > prev)
		take = 1 + helper(index + 1, A[index], A);
	
	int not_take = helper(index + 1, prev, A);
	
	return max(take, not_take);
}

int getLengthOfLIS(vector<int> &A) 
{
	return helper(0, INT_MIN, A);
}

int main()
{
    vector<int> A = {10, 20, 2, 5, 3, 8, 8, 25, 6};

    cout << getLengthOfLIS(A) << endl;
    
    return 0;
}