// Source : https://leetcode.com/problems/burst-balloons/
// Author : Nan
// Date   : 2019-10-09
// Runtime: 16 ms

/*
* DP. dp[i][j] is maximum coins in interval [i,j]. 
*
* Time complexity O(n^3), Space complexity O(n^2)
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};