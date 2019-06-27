// Source : https://leetcode.com/problems/kth-largest-element-in-an-array
// Author : Nan
// Date   : 2019-06-27
// Runtime: 52 ms

/*
* Partion sort recursively.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int idx = findk(left, right, nums);
            if (idx == k - 1) return nums[k - 1];
            else if (idx < k - 1) left = idx + 1;
            else right = idx - 1;
        }
        return 0;
    }
    int findk(int left, int right, vector<int> &nums) {
        int p = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < p && nums[r] > p) swap(nums[l++], nums[r--]);
            else if (nums[l] >= p) ++l;
            else if (nums[r] <= p) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};