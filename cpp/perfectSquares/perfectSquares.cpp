// Source : https://leetcode.com/problems/perfect-squares/
// Author : Nan
// Date   : 2019-09-12
// Runtime: 128 ms

/*
* DP.
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};