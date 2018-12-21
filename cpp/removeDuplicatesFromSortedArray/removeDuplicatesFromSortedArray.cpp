// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Nan
// Date   : 2018-12-21
// 161 / 161 test cases passed.
// Runtime: 16 ms

/*
* Use two pointers, fast and slow pointers. 
* Fast pointers traverse array and slow pointer 
* exchange unique num to front.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[pos - 1]) nums[pos++] = nums[i];
        }
        return pos;
    }
};