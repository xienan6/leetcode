// Source : https://leetcode.com/problems/word-break/
// Author : Nan
// Date   : 2019-05-13
// Runtime: 8 ms

/*
* DP and dp[i] is if s[0:i) can be break. s[0:i) can be break if s[0:j) can be break and s[j:i) is a word in wordDict. 
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};