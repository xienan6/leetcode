// Source : https://leetcode.com/problems/climbing-stairs
// Author : Nan
// Date   : 2018-12-31
// 45 / 45 test cases passed.
// Runtime: 0 ms

/*
* Fibonacci sequence.  
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        int a[3] = {0, 1, 2};
        int result = 2, lastr = 1, tl;
        if (n <= 2) {
            return a[n];
        }
        else {
            for (int i = 3; i <= n; i++) {
                tl = lastr;
                lastr = result;
                result += tl;
            }
            return result;
        }
    }
};