// Source : https://leetcode.com/problems/reverse-bits/
// Author : Nan
// Date   : 2019-06-04
// Runtime: 0 ms

/*
* Bit operation.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, i = 32;
        while (i--) {
            res = res << 1;
            res += n & 1;
            n = n >> 1;
        }
        return res;
    }
};