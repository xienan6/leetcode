// Source : https://leetcode.com/problems/number-of-digit-one/
// Author : Nan
// Date   : 2019-08-21
// Runtime: 4 ms

/*
* Use two stacks.   
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        return ones;
    }
};