// Source : https://leetcode.com/problems/decode-string/
// Author : Nan
// Date   : 2019-12-18
// Runtime: 4 ms

/*
* Recursion solution.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    string decode(string &s, int &i) {
        string res = "";
        int n = s.size();
        while (i < n && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                res += s[i++];
            }
            else {
                int cnt = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                ++i;
                string t = decode(s, i);
                ++i;
                while (cnt-- > 0) res += t;
            }
        }
        return res;
    }
};