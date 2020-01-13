// Source : https://leetcode.com/problems/longest-repeating-character-replacement
// Author : Nan
// Date   : 2020-01-13
// Runtime: 28 ms

/*
* Use a sliding window.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int i  = 0, j  = 0, res = 0;
        while (i < s.length() && j < s.length()) {
            while (j < s.length()) {
                cnt[s[j++] - 'A']++;
                if (j - i - helper(cnt) > k) break;
                res = max(res, j - i);
            }
            while (i < j && i < s.length()) {
                cnt[s[i++] - 'A']--;
                if (j - i - helper(cnt) <= k) break;
            }
        }
        return res;
    }
    int helper(vector<int> &cnt) {
        int r = 0;
        for (int i = 0; i < 26; ++i) r = max(cnt[i], r);
        return r;
    }
};