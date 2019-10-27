// Source : https://leetcode.com/problems/integer-break/
// Author : Nan
// Date   : 2019-10-27
// Runtime: 4 ms

/*
* Calculate the number of 3 and rest 2 or 4.
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        n -= 5;
        return (int)pow(3, (n / 3 + 1)) * (n % 3 + 2);
    }
};