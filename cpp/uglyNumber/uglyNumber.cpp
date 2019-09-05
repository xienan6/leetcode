// Source : https://leetcode.com/problems/ugly-number
// Author : Nan
// Date   : 2019-09-05
// Runtime: 4 ms

/*
* Continuous factor division.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1 ? true : false;
    }
};