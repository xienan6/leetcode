// Source : https://leetcode.com/problems/dungeon-game/
// Author : Nan
// Date   : 2019-05-31
// Runtime: 8 ms

/*
* DP. When arrive pricess's room, knight has at least 1 
* health. Traverse from princess's room to knight's room. 
*
* Time complexity O(mn), Space complexity O(mn)
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};