// Source : https://leetcode.com/problems/edit-distance
// Author : Nan
// Date   : 2019-03-05
// 1146 / 1146 cases passed.
// Runtime: 12 ms

/*
* DP. If two characters are not same, then think 
* about insert = dp[i+1][j] + 1, delete = dp[i][j+1] + 1, 
* replace = dp[i][j] + 1. And take minimum of them.    
*
* Time complexity O(mn), Space complexity O(mn)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        int dp[l1 + 1][l2 + 1];
        for (int i = 0; i <= l1; i++) dp[i][0] = i;
        for (int i = 0; i <= l2; i++) dp[0][i] = i;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[l1][l2];
    } 
};