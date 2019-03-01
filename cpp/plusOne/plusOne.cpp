// Source : https://leetcode.com/problems/plus-one
// Author : Nan
// Date   : 2019-03-01
// 109 / 109 cases passed.
// Runtime: 4 ms

/*
* Simulate.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if (c) digits.insert(digits.begin(), 1);
        return digits;
    }
};