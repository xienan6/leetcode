// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// Author : Nan
// Date   : 2019-03-10
// 166 / 166 cases passed.
// Runtime: 16 ms

/*
* Simulate.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) 
            if (pos < 2 || nums[pos - 2] != nums[i]) nums[pos++] = nums[i];
        return pos;
    }
};