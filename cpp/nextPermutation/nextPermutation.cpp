// Source : https://leetcode.com/problems/next-permutation/
// Author : Nan
// Date   : 2018-12-27
// 265 / 265 test cases passed.
// Runtime: 8 ms

/*
* For example, for set 1 2 3 7 6 5 2 1 we first look for the 
* first non-reverse element, here is 3, then look for the first 
* element greater than 3 from the back, here is 5, exchange, 
* get 5 7 6 3 2 1 sub-arrangement, then reverse, you can get 
* the next arrangement. If the first non-reverse element is not 
* found, then the permutation is already the largest permutation.  
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), flag = 1;
        if (n <= 1) return;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                flag = 0;
                break;
            }
        }
        if (flag) reverse(nums.begin(), nums.end());
    }
};