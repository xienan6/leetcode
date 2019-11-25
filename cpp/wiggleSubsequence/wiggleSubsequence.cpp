// Source : https://leetcode.com/problems/wiggle-subsequence/
// Author : Nan
// Date   : 2019-11-25
// Runtime: 0 ms

/*
* Greedy solution.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p = 1, q = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) p = q + 1;
            else if (nums[i] < nums[i - 1]) q = p + 1;
        }
        return min(n, max(p, q));
    }
};