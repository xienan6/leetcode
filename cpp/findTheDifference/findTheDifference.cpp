// Source : https://leetcode.com/problems/find-the-difference/
// Author : Nan
// Date   : 2019-12-12
// Runtime: 0 ms

/*
* Hash.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        char res;
        for (int i = 0; i < s.length(); ++i) ++v[s[i] - 'a'];
        for (int i = 0; i < t.length(); ++i) {
            if (--v[t[i] - 'a'] < 0) {
                res = t[i];
                break;
            }
        }
        return res;
    }
};