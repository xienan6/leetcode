// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// Author : Nan
// Date   : 2019-03-10
// 166 / 166 cases passed.
// Runtime: 16 ms

/*
* Simulate.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> m;
        for (int i = 0; i < t.length(); i++) m[t[i]]++;
        int cnt = 0, left = 0, minLen = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            if (--m[s[i]] >= 0) cnt++;
            while (cnt == t.length()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++m[s[left]] > 0) cnt--;
                left++;
            }
        }
        return res;
    }
};