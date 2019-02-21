// Source : https://leetcode.com/problems/jump-game
// Author : Nan
// Date   : 2019-02-21
// 75 / 75 test cases passed.
// Runtime: 12 ms

/*
* Greedy.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (i > cur || cur >= n - 1) break;
            cur = max(i + nums[i], cur);
        }
        return cur >= n - 1;
    }
};