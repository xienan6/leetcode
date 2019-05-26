// Source : https://leetcode.com/problems/excel-sheet-column-title/
// Author : Nan
// Date   : 2019-05-26
// Runtime: 0 ms

/*
* Binary conversion, 10 to 26. 
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n--) {
            res = char('A' + n % 26) + res;
            n /= 26;
        }
        return res;
    }
};