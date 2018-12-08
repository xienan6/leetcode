// Source : https://leetcode.com/problems/roman-to-integer/description/
// Author : Nan
// Date   : 2018-12-08
// 3999 / 3999 test cases passed.
// Runtime: 84 ms

/*
* See in code. Mirror problem. https://leetcode.com/problems/integer-to-roman/description/
*/

class Solution {
public:
    int romanToInt(string s) {
        int m[131];
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int l = s.length();
        int result = m[s[l - 1]];
        for (int i = 0; i < l - 1; i++) {
            if (m[s[i]] < m[s[i + 1]]) {
                result -= m[s[i]];
            }
            else {
                result += m[s[i]];
            }
        }
        return result;
    }
};