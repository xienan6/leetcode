// Source : https://leetcode.com/problems/rotate-array/
// Author : Nan
// Date   : 2019-06-03
// Runtime: 16 ms

/*
*
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        nums.resize(size);
    }
};