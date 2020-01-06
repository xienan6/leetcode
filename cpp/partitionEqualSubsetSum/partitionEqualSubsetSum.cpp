// Source : https://leetcode.com/problems/partition-equal-subset-sum/
// Author : Nan
// Date   : 2020-01-06
// Runtime: 4 ms

/*
* DFS and prune.
*
* Time complexity O(-), Space complexity O(-)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % 2) return false;
        sum /= 2;
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << endl;
        }
        return helper(nums, sum, 0);
    }
    bool helper(vector<int> &nums, int sum, int index) {
        if (index == nums.size()) return false;
        if (sum == nums[index]) return true;
        if (sum < nums[index]) return false;
        return helper(nums, sum - nums[index], index + 1) || helper(nums, sum, index + 1);
    }
};