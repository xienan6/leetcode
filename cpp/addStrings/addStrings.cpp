// Source : https://leetcode.com/problems/add-strings/
// Author : Nan
// Date   : 2020-01-05
// Runtime: 8 ms

/*
* 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        string res = "";
        while (i >= 0 && j >= 0) {
            int num = num1[i--] - '0' + num2[j--] - '0' + carry;
            res = to_string(num % 10) + res;
            carry = num / 10;
        }
        while (i >= 0) {
            int num = num1[i--] - '0' + carry;
            res = to_string(num % 10) + res;
            carry = num / 10;
        }
        while (j >= 0) {
            int num = num2[j--] - '0' + carry;
            res = to_string(num % 10) + res;
            carry = num / 10;
        }
        return carry == 0 ? res : to_string(carry) + res;
    }
};