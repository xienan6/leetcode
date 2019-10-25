// Source : https://leetcode.com/problems/self-crossing/
// Author : Nan
// Date   : 2019-10-25
// Runtime: 4 ms

/*
* 3 situations.
*      x(1)
*     ┌───┐
* x(2)│   │x(0)
*     └───┼──>
*     x(3)│
*
*      x(1)
*     ┌──────┐
*     │      │x(0)
* x(2)│      ^
*     │      │x(4)
*     └──────│
*       x(3)
*
*       x(1)
*     ┌──────┐
*     │      │x(0)
* x(2)│     <│────│
*     │       x(5)│x(4)
*     └───────────│
*        x(3)
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); ++i) {
            if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]) {
                return true;
            }
            if (i >= 4 && x[i-1] == x[i-3] && x[i] >= x[i-2] - x[i-4]) {
                return true;
            }
            if (i >= 5 && x[i-2] >= x[i-4] && x[i-3] >= x[i-1] && x[i-1] >= x[i-3] - x[i-5] && x[i] >= x[i-2] - x[i-4]) {
                return true;
            }
        }
        return false;
    }
};