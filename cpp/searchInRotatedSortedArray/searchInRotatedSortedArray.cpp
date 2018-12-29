// Source : https://leetcode.com/problems/search-in-rotated-sorted-array
// Author : Nan
// Date   : 2018-12-29
// 196 / 196 test cases passed.
// Runtime: 8 ms

/*
* Judge if nums[mid] is bigger than nums[right], then search.    
* 
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] == target) return mid;
            //sorted array on the right
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            //sorted array on the left
            else {
                if (nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};