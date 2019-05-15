// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : Nan
// Date   : 2019-05-15
// Runtime: 12 ms

/*
* String processing.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.length() - 1, start = 0;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') --i;
            start = i;
            while (i >= 0 && s[i] != ' ') --i;
            if (start >= 0) res = res + s.substr(i + 1, start - i) + " ";
        }
        return res.substr(0, res.length() - 1);
    }
};