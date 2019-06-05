// Source : https://leetcode.com/problems/number-of-1-bits
// Author : Nan
// Date   : 2019-06-05
// Runtime: 0 ms

/*
* Bit operation.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1) ++res;
            n = n >> 1;
        }
        return res;
    }
};