// Source : https://leetcode.com/problems/remove-element/description/
// Author : Nan
// Date   : 2018-12-17
// 113 / 113 test cases passed.
// Runtime: 4 ms

/*
* Traverse once.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
       // int index = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                len--;  
                i--;
            }
        }
        return len;
        
    }
};