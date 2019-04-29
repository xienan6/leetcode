// Source : https://leetcode.com/problems/single-number-ii/
// Author : Nan
// Date   : 2019-04-29
// Runtime: 12 ms

/*
* Use a number to record the number "1" of every bit. Then mod 3. 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
