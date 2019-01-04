// Source : https://leetcode.com/problems/first-missing-positive
// Author : Nan
// Date   : 2019-01-04
// 157 / 157 test cases passed.
// Runtime: 4 ms

/*
* Store nums[i] in index i.
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, l = nums.size();
        if (l == 0) return 1;
        for (i = 0; i < l; i++) {
            while (nums[i] > 0 && nums[i] <= l && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (i = 0; i < l; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums[i - 1] + 1;
    }
};