// Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author : Nan
// Date   : 2019-06-10
// Runtime: 16 ms

/*
* Longest common prefix 1.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};