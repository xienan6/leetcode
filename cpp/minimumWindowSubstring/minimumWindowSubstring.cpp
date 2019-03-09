// Source : https://leetcode.com/problems/minimum-window-substring/
// Author : Nan
// Date   : 2019-03-09
// 268 / 268 cases passed.
// Runtime: 28 ms

/*
* Sliding window. Slide the window to the right 
* until all characters are included and then slide 
* the window from the left until it does not contain 
* all the characters. Repeat the above steps.  
*
* Time complexity O(n), Space complexity O(m)
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