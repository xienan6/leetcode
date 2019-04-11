// Source : https://leetcode.com/problems/distinct-subsequences/
// Author : Nan
// Date   : 2019-04-11
// Runtime: 8 ms

/*
* DP.  
*
* Time complexity O(nm), Space complexity O(m)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        long dp[l2 + 1], p[l2 + 1];
        dp[0] = 1;
        for (int j = 1; j <= l2; ++j) dp[j] = 0;
        for (int i = 1; i <= l1; ++i) {
            for (int j = 0; j <= l2; ++j) p[j] = dp[j];
            for (int j = 1; j <= l2; ++j) dp[j] = p[j] + (s[i - 1] == t[j - 1]) * p[j - 1];
        }
        return dp[l2];
    }
};