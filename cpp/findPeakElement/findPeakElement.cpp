// Source : https://leetcode.com/problems/find-peak-element/
// Author : Nan
// Date   : 2019-05-21
// Runtime: 8 ms

/*
* Binary search.  
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};