// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Nan
// Date   : 2019-05-17
// Runtime: 4 ms

/*
* Binary search. 
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, res = INT_MAX;
        if (right == 0) return nums[0];
        while (left < right) {
            res = min(min(res, nums[left]), nums[right]);
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[left] && nums[mid] < nums[right]) return res;
            else if (nums[mid] > nums[left] && nums[mid] > nums[right]) left = mid;
            else right = mid;
        }
        return res;
    }
};