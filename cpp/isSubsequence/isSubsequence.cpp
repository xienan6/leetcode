// Source : https://leetcode.com/problems/is-subsequence/
// Author : Nan
// Date   : 2019-12-16
// Runtime: 60 ms

/*
* 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for (;i < s.length() && j < t.length(); ++j) {
            if (s[i] == t[j]) ++i;
        }
        return i == s.length();
    }
};