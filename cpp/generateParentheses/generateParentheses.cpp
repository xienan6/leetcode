// Source : https://leetcode.com/problems/generate-parentheses/description/
// Author : Nan
// Date   : 2018-12-13
// 8 / 8 test cases passed.
// Runtime: 0 ms

/*
* If you are stuck, recursion is your friend. Generate parenthesis when it is valid.
*
* Time complexity and space complexity are exponential growth.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addpar(result, "", n, 0);
        return result;
    }
    void addpar(vector<string> &v, string s, int n, int m) {
        if (n == 0 && m == 0) {
            v.push_back(s);
        }
        else {
            if (n > 0) {
                addpar(v, s + '(', n - 1, m + 1);
            }
            if (m > 0) {
                addpar(v, s + ')', n, m - 1);
            }
        }
    }
};