// Source : https://leetcode.com/problems/longest-palindromic-substring/description/
// Author : Nan
// Date   : 2018-12-07
// 103 / 103 test cases passed.
// Runtime: 4 ms

/*
* Brute force use O(n^3) time complexity.
* We can traverse each point to search both sides until they are not equal. 
* We can also use a dp, dp[i][j] = s[i]==s[j] && dp[i+1][j-1]. Time complexity is O(n^2)
* The best algorithm is O(n) called Manacher's algorithm. Time complexity is O(n). 
* Here I use Manacher's algorithm.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // Insert '#'
        string t = "$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        // Process t
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};