// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author : Nan
// Date   : 2019-06-30
// Runtime: 28 ms

/*
* Quick sort and compare.
*
* Time complexity O(nlogn), Space complexity O(nlogn)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};