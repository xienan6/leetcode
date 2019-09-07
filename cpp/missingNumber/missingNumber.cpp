// Source : https://leetcode.com/problems/missing-number/
// Author : Nan
// Date   : 2019-09-07
// Runtime: 24 ms

/*
* Use [0,1...n-1] XOR input.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) res = res ^ nums[i] ^ i;
        return res;
    }
};