// Source : https://leetcode.com/problems/water-and-jug-problem/
// Author : Nan
// Date   : 2019-11-09
// Runtime: 4 ms

/*
* -
*
* Time complexity O(logn), Space complexity O(logn)
*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};