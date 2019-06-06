// Source : https://leetcode.com/problems/house-robber
// Author : Nan
// Date   : 2019-06-06
// Runtime: 4 ms

/*
* DP.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        return dp[nums.size() - 1];
    }
};