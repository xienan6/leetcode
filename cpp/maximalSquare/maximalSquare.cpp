// Source : https://leetcode.com/problems/maximal-square
// Author : Nan
// Date   : 2019-07-04
// Runtime: 20 ms

/*
* DP.
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;         
    }
};