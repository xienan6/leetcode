// Source : https://leetcode.com/problems/maximum-product-subarray/
// Author : Nan
// Date   : 2019-05-16
// Runtime: 4 ms

/*
* Product until meet 0. Forward and reverse product twice.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0]; 
        int res = 0;
        fun(res, nums);
        reverse(nums.begin(), nums.end());
        fun(res, nums);
        return res;
    }
    void fun(int &res, vector<int>& nums) {
        int s = 0;
        while (s < nums.size() && nums[s] == 0) ++s;
        int product = nums[s];
        res = max(res, product);
        for (int i = s + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) product *= nums[i];
            else if (i + 1 != nums.size()){
                product = nums[i + 1];
                ++i;
            }
            res = max(res, product);
        }
    }
};