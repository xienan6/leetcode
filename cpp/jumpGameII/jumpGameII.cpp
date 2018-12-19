// Source : https://leetcode.com/problems/jump-game-ii/
// Author : Nan
// Date   : 2018-12-19
// 92 / 92 test cases passed.
// Runtime: 8 ms

/*
* greedy
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int last = 0, cur = 0, result = 0;
        for (int i = 0; i < n; i++) {
            if (i > last) {
                result++;
                last = cur;
            }
            cur = max(i + nums[i], cur);
        }
        return result;
    }
};