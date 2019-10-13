// Source : https://leetcode.com/problems/split-a-string-in-balanced-strings
// Author : Nan
// Date   : 2019-10-13
// Runtime: 4 ms

/*
* Greedy solution. If the number of 'R' and the number of 'L' are equal. Result++.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'R') ++cnt1;
            else ++cnt2;
            if (cnt1 == cnt2) {
                ++res;
                cnt1 = cnt2 = 0;
            }
        }
        return res;
    }
};