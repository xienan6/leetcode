// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : Nan
// Date   : 2019-05-18
// Runtime: 4 ms

/*
* Binary search. 
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[left]) left = mid;
            else if (nums[mid] < nums[left]) right = mid;
            else ++left;
        }
        return min(nums[left], nums[right]);
    }
};