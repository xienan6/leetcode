// Source : https://leetcode.com/problems/move-zeroes
// Author : Nan
// Date   : 2019-09-14
// Runtime: 12 ms

/*
* Count zero.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) if (nums[i] != 0) nums[cnt++] = nums[i];
        for (int i = nums.size() - 1; i >= cnt; --i) nums[i] = 0;
    }
};