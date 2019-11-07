// Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Author : Nan
// Date   : 2019-11-07
// Runtime: 4 ms

/*
* f(k) = 9 * 9 * ... * (11 - k). Result = f(1) + ... + f(k).
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res[] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
        return n > 10 ? 8877691 : res[n];
    }
};