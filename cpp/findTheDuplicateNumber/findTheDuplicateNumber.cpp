// Source : https://leetcode.com/problems/find-the-duplicate-number
// Author : Nan
// Date   : 2019-09-17
// Runtime: 12 ms

/*
* There must be a circle and find the point of the intersection.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];
        while (slow != fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};