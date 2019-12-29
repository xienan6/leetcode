// Source : https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Author : Nan
// Date   : 2019-12-29
// Runtime: 4 ms

/*
* 
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    string toHex(int num) {
        string res = "", str = "0123456789abcdef";
        int cnt = 0;
        while (num != 0 && cnt++ < 8) {
            res = str[(num & 0xf)] + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};