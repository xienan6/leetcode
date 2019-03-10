// Source : https://leetcode.com/problems/subsets
// Author : Nan
// Date   : 2019-03-10
// Runtime: 8 ms

/*
* Recursion.
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> r;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            f(result, r, 0, i, n, nums);
        }
        return result;
    }
    void f(vector<vector<int>> &result, vector<int> &r, int start, int k, int n, vector<int>& nums) {
        if (k <= 0) {
            result.push_back(r);
            return;
        }
        for (int i = start; i <= n - k; i++) {
            r.push_back(nums[i]);
            f(result, r, i + 1, k - 1, n, nums);
            r.pop_back();
        }
    }
};