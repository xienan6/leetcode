// Source : https://leetcode.com/problems/subsets-ii/
// Author : Nan
// Date   : 2019-03-19
// Runtime: 8 ms

/*
* Recursion.       
*
* Time complexity O(2^n), Space complexity O(2^n)
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        sort(nums.begin(), nums.end());
        if (nums.size() < 1) return res;
        fun(res, r, 0, nums);
        return res;
    }
    void fun(vector<vector<int>> &res, vector<int> &r, int pos, vector<int> &nums) {
        res.push_back(r);
        for (int i = pos; i < nums.size(); ++i) {
            r.push_back(nums[i]);
            fun(res, r, i + 1, nums);
            r.pop_back();
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
};