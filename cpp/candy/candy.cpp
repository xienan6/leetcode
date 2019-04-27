// Source : https://leetcode.com/problems/candy/
// Author : Nan
// Date   : 2019-04-27
// Runtime: 28 ms

/*
* Step 1, if right child's value is greater than left 
* child's value, then give him one more candy than left one. 
* Step 2, if left child's value is greater than right 
* child's value, then give him one more candy than right one.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) {
                nums[i + 1] = nums[i] + 1;
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            if (ratings[i - 1] > ratings[i]) {
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
            }
        }
        for (int i = 0; i < n; ++i) res += nums[i];
        return res;
    }
};