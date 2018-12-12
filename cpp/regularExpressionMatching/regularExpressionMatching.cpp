// Source : https://leetcode.com/problems/regular-expression-matching/description/
// Author : Nan
// Date   : 2018-12-12
// 447 / 447 test cases passed.
// Runtime: 8 ms

/*
* If you are stuck, recursion is your friend.  
* But we can use a dp to solve this problem. There are three conditions. 
* Assume that dp[i][j] is if s[0:i-1] and p[0:j-1] match.  
* 1.If p[j]!='*'  
*     dp[i+1][j+1] = dp[i][j] && (s[i]==p[j] || p[j] == '.')  
* 2.If p[j]=='*' and match 0 character (like "aab" and "ac*ab")   
*     dp[i+1][j+1] = dp[i+1][j-1]   
* 3.If p[j]=='*' and match at least 1 character (like "aaccb" and "ac*b")  
*     dp[i+1][j+1] = dp[i][j+1] && (s[i]==p[j-1] || p[j-1] == '.')  
* Notice that dp[0][0] = true and dp[0][j] = false.    
*
* Time complexity O(mn), Space complexity O(mn). m, n are length of s and p.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();
        bool **dp = new bool* [l1 + 1];
        for(int i = 0; i <= l1; i++) {
            dp[i] = new bool[l2 + 1];
            for(int j = 0; j <= l2; j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for(int i = 0; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(p[j - 1] != '*') {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                else {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[l1][l2];
    }
};
