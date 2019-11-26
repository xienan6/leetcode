// Source : https://leetcode.com/problems/combination-sum-iv/
// Author : Nan
// Date   : 2019-11-26
// Runtime: 4 ms

/*
* DP.
*
* Time complexity O(nk), Space complexity O(n)
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i < a) break;
                dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};