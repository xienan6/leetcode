// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Nan
// Date   : 2019-01-22
// 202 / 202 test cases passed.
// Runtime: 4 ms

/*
* DP. If sum < 0, abandon it, or calculete summation.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum = nums[i] + (sum > 0 ? sum : 0);
            result = max(result, sum);
        }
        return result;
    }
};