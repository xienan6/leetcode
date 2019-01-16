// Source : https://leetcode.com/problems/permutations-ii/
// Author : Nan
// Date   : 2019-01-16
// 30 / 30 test cases passed.
// Runtime: 20 ms

/*
* Recursive  
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        nextPermute(result, 0, nums);
        return result;
    }
    void nextPermute(vector<vector<int>> &result, int start, vector<int> nums) {
        if (start >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] != nums[start] || i == start) {
                swap(nums[start], nums[i]);
                nextPermute(result, start + 1, nums);
            }
        }
    }
};