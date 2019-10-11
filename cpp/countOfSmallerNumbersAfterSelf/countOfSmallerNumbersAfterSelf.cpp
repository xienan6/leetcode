// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author : Nan
// Date   : 2019-10-11
// Runtime: 156 ms

/*
* Binary search insert.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};