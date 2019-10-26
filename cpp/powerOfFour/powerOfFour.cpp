// Source : https://leetcode.com/problems/power-of-four/
// Author : Nan
// Date   : 2019-10-26
// Runtime: 0 ms

/*
* Not a multiple of 2 and the odd bit is 1.
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};