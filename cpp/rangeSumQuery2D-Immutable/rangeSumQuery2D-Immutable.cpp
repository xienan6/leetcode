// Source : https://leetcode.com/problems/range-sum-query-2d-immutable
// Author : Nan
// Date   : 2019-09-25
// Runtime: 24 ms

/*
* DP.
*
* Time complexity O(1), Space complexity O(n^2)
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) { 
        if (matrix.size()&& matrix[0].size()) {
            vector<vector<int>> dp = matrix;
            for (int i = 0; i < dp[0].size(); ++i) {
                for (int j = 1; j < dp.size(); ++j) {
                    dp[j][i] += dp[j - 1][i];
                }
            }
            res = dp;
            for (int i = 1; i < dp[0].size(); ++i) {
                res[0][i] += res[0][i - 1];
                for (int j = 1; j < dp.size(); ++j) {
                    res[j][i] = res[j][i - 1] + matrix[j][i] + dp[j - 1][i];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1 = row1 > 0 && col1 > 0 ? res[row1 - 1][col1 - 1] : 0;
        int s2 = row1 > 0 ? res[row1 - 1][col2] : 0;
        int s3 = col1 > 0 ? res[row2][col1 - 1] : 0;
        return res[row2][col2] - s2 - s3 + s1;
    }
private:
    vector<vector<int>> res;
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */