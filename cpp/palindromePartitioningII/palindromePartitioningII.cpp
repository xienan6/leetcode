// Source : https://leetcode.com/problems/palindrome-partitioning-ii/
// Author : Nan
// Date   : 2019-04-24
// Runtime: 24 ms

/*
* DP.
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        vector<int> cut(s.length() + 1, 0);
        for (int i = s.length() - 1; i >= 0; --i){
            cut[i] = INT_MAX;
        	for (int j = i; j < s.length(); ++j) {
                if (s[i]==s[j] && (j - i <= 1 || dp[i + 1][j - 1] == 1)) {
                    dp[i][j] = 1;
                    cut[i] = min(1 + cut[j + 1], cut[i]);  
                }
            }
        }
        return cut[0] - 1;
    }
};