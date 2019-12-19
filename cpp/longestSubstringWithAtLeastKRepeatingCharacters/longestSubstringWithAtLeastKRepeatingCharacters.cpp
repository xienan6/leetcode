// Source : https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
// Author : Nan
// Date   : 2019-12-19
// Runtime: 156 ms

/*
* Recursion and divide.
*
* Time complexity O(nlogn), Space complexity O(nlogn)
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> v(26, 0);
        int idx = 0, i;
        for (i = 0; i < s.length(); ++i) v[s[i] - 'a']++;
        while (idx < 26) {
            if (v[idx] > 0 && v[idx] < k) break;
            else idx++;
        }
        if (idx == 26) return s.length();
        for (i = 0; i < s.length(); ++i) if (s[i] == 'a' + idx) break;
        int left = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i + 1), k);
        return max(left, right);
    }
};