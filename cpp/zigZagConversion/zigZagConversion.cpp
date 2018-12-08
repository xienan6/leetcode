// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Nan
// Date   : 2018-12-08
// 1158 / 1158 test cases passed.
// Runtime: 20 ms

/*
* You can easily infer the general formula and notice the case when numRows is 1.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string result = "";
        int pos, n = s.length(), divisor = numRows * 2 - 2;
        for (int i = 0; i <= numRows - 1; i++) {
            if (i == 0 || i == numRows - 1) {
                for (pos = i; pos < n; pos += divisor) {
                    result += s[pos]; 
                }
            }
            else {
                for (pos = i; pos < n; pos += divisor) {
                    result += s[pos];
                    int x = pos + divisor - i * 2;
                    if (x < n) {
                        result += s[x];
                    }
                }
            }
        }
        return result;
    }
};