// Source : https://leetcode.com/problems/dice-roll-simulation/
// Author : Nan
// Date   : 2019-10-13
// Runtime: 12 ms

/*
* DP. Detailed in code.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int N = 1000000007;
        //dp[i][j] represents the number of distinct sequences that can be obtained when rolling i times and ending with j
        //The one more row represents the total sequences when rolling i times
        vector<vector<long>> dp(n + 1, vector<long>(6, 0));
        vector<long> sum(n + 1, 0);
        for (int i = 0; i < 6; ++i) dp[1][i] = 1;
        sum[0] = 1;
        sum[1] = 6;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 6; ++j) {
                //If there are no constraints, the total sequences ending with j should be the total sequences from preious rolling
                dp[i][j] = sum[i - 1];
                //For axx1, we need to remove the number of a11 (211 + 311 + 411 + 511 + 611) => (..2 + ..3 + ..4 + ..5 + ..6) => (sum - ..1)
                if (i - rollMax[j] >= 1) {
                    //must add one more mod because subtraction may introduce negative numbers
                    dp[i][j] = (dp[i][j] - (sum[i - rollMax[j] - 1] - dp[i - rollMax[j] - 1][j]) + N) % N;
                }
                sum[i] = (sum[i] + dp[i][j]) % N;
            }
        }
        return sum[n];
    }
};