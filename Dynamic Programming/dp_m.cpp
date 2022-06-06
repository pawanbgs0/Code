#include "dp.h"

int main()
{
    vector<int> test = {3, 1, 8, 9};
    vector<int> dp(test.size(), -1);

    vector<vector<int>> test2 = {{10, 20, 30}, {20, 30, 50}, {30, 60, 90}};
    vector<vector<int>> dp2(23, vector<int> (12, -1));
    vector<vector<vector<int>>> dp3(test2.size(), vector<vector<int>> (test2[0].size(), vector<int> (test2[0].size(), -1)));

    string s1 = "Pawan";
    string s2 = "Pkauwmaanr";
    
    // cout << fibonacci(5, dp);
    // cout << climb(1, dp);

    // cout << subsquence_sum(test.size() -1, test, dp) << endl;
    // cout << subsquence_sumT(test) << endl;

    // cout << ninja_training(test2.size() - 1, 3, test2, dp2); 

    // cout << unique_paths(22, 11, dp2);

    // cout << unique_paths_II(test2.size() - 1, test2[0].size() - 1 , test2, dp2) << endl;

    // cout << min_path_sum(test2.size() - 1, test2[0].size() - 1, test2, dp2) << endl;

    // cout << minimumTotal(0, 0, test2.size() - 1, test2, dp2) << endl;

    // cout << cherryPickup(0, 0, test2[0].size() - 1, test2, dp3) << endl;

    // cout << hasValidSubset(3, 8, test, dp2) << endl;

    // cout << canPartition(test) << endl;

    // cout << longest_common_subsequence(s1.length(), s2.length(), s1, s2, dp2);

    cout << longest_common_subsequence_table(s1, s2);
    
    return 0;
}