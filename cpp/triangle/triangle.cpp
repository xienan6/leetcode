// Source : https://leetcode.com/problems/triangle/
// Author : Nan
// Date   : 2019-04-16
// Runtime: 8 ms

/*
* DP.      
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n < 1) return 0;
        int dp[n][n];
        for (int i = n - 1; i >= 0; --i) dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};