// Source : https://leetcode.com/problems/powx-n/
// Author : Nan
// Date   : 2019-01-18
// 304 / 304 test cases passed.
// Runtime: 4 ms

/*
* Fast power.  
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int i = n;
        while (i != 0) {
            if (i % 2 != 0) res *= x;
            x *= x;
            i /= 2;
        }
        return n < 0 ? 1.0 / res : res;
    }
};