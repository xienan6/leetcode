// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : Nan
// Date   : 2019-05-28
// Runtime: 4 ms

/*
* Binary conversion, 26 to 10. 
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int titleToNumber(string s) {
        long long res = 0;
        for (int i = 0; i < s.length(); ++i) res = res * 26 + s[i] - 'A' + 1;
        return res;
    }
};