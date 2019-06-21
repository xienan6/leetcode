// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : Nan
// Date   : 2019-06-21
// Runtime: 8 ms

/*
* Use two pointers to find right bound then move left pointer repeatly.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};