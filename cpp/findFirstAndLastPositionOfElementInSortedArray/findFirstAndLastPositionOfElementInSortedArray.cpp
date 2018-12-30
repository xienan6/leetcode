// Source : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : Nan
// Date   : 2018-12-30
// 88 / 88 test cases passed.
// Runtime: 8 ms

/*
* Use twice binary search to find first and last position of element.  
* 
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size() - 1;
        vector<int> result;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                if (mid == 0 || nums[mid - 1] < nums[mid]) {
                    result.push_back(mid);
                    break;
                }
                else right = mid - 1;
            }
        }
        if (result.empty()) return {-1, -1};
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                if (mid == nums.size() - 1 || nums[mid + 1] > nums[mid]) {
                    result.push_back(mid);
                    break;
                }
                else left = mid + 1;
            }
        }
        return result;
    }
};