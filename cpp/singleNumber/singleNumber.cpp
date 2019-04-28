// Source : https://leetcode.com/problems/single-number/
// Author : Nan
// Date   : 2019-04-28
// Runtime: 16 ms

/*
* Use XOR.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) res ^= nums[i];
        return res;
    }
};