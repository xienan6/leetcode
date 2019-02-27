// Source : https://leetcode.com/problems/unique-paths-ii
// Author : Nan
// Date   : 2019-02-27
// 43 / 43 cases passed.
// Runtime: 4 ms

/*
* DP. If there is no obstacle in a point, the 
* solution of this point is the solution of the 
* left and top of this point.  
*
* Time complexity O(nm), Space complexity O(nm)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long>> dp(row + 1, vector<long>(col + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++) 
                if (obstacleGrid[i - 1][j - 1] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[row][col];
    }
};