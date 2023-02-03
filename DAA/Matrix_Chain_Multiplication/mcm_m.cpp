#include "mcm.h"

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

    // cout << mcm_recursive(1, arr.size() - 1, arr, dp) << endl;

    cout << mcm_tabulation(arr) << endl;
    return 0;
}