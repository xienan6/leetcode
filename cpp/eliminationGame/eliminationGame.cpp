// Source : https://leetcode.com/problems/elimination-game
// Author : Nan
// Date   : 2019-12-13
// Runtime: 8 ms

/*
* Recursion solution.
*
* Time complexity O(logn), Space complexity O(logn)
*/

class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, left);
    }
    int helper(int n, bool left){
        if(n == 1)
            return 1;
        if(left == true)
            return 2 * helper(n / 2, false);
        else
            return 2 * helper(n / 2, true) - 1 + n % 2;
    }
};