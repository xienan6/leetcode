// Source : https://leetcode.com/problems/power-of-two/
// Author : Nan
// Date   : 2019-08-19
// Runtime: 0 ms

/*
* Divide by 2 and take the remainder.  
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n != 1) {
            if (n % 2 != 0) return false;
            n /= 2;
        }
        return true;
    }
};