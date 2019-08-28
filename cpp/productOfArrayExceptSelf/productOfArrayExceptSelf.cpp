// Source : https://leetcode.com/problems/product-of-array-except-self
// Author : Nan
// Date   : 2019-08-28
// Runtime: 36 ms

/*
* The cumulative product on the left of a number 
* multiplied by the cumulative product to the right 
* of this number is product of array except self. We 
* can use result array to save space.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};