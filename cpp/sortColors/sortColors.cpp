// Source : https://leetcode.com/problems/sort-colors/
// Author : Nan
// Date   : 2019-03-08
// 87 / 87 cases passed.
// Runtime: 8 ms

/*
* Shift backward.   
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = 0;
        for (int p = 0; p < nums.size(); p++) {
            if (nums[p] == 0) {
                nums[k++] = 2;
                nums[j++] = 1;
                nums[i++] = 0;
            }
            else if(nums[p] == 1) {
                nums[k++] = 2;
                nums[j++] = 1;
            }
            else nums[k++] = 2;
        }
    }
};