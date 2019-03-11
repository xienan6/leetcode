// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Nan
// Date   : 2019-03-11
// Runtime: 8 ms

/*
* Binary search. Boundary situation is [1,1,1,1,1] 
* and time complexity is O(n).  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] == target) return true;
            //sorted array on the right
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            //sorted array on the left
            else if (nums[mid] > nums[right]){
                if (nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            }
            else right--;
        }
        return false; 
    }
};