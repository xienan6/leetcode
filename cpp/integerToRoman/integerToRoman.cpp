// Source : https://leetcode.com/problems/integer-to-roman/description/
// Author : Nan
// Date   : 2018-12-07
// 3999 / 3999 test cases passed.
// Runtime: 76 ms

/*
* See in code. Mirror problem. https://leetcode.com/problems/roman-to-integer/description/
*/

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};