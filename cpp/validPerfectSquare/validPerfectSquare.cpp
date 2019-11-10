// Source : https://leetcode.com/problems/valid-perfect-square/
// Author : Nan
// Date   : 2019-11-09
// Runtime: 4 ms

/*
* -
*
* Time complexity O(sqrtn), Space complexity O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
};