// Source : https://leetcode.com/problems/split-array-largest-sum
// Author : Nan
// Date   : 2020-01-01
// Runtime: 148 ms

/*
* DP.
*
* Time complexity O(n^2m), Space complexity O(nm)
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    long long val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};