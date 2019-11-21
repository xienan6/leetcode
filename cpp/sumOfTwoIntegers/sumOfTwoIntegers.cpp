// Source : https://leetcode.com/problems/sum-of-two-integers/
// Author : Nan
// Date   : 2019-11-21
// Runtime: 0 ms

/*
* Bit operation.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b & 0x7fffffff) << 1);
    }
};