// Source : https://leetcode.com/problems/patching-array/
// Author : Nan
// Date   : 2019-10-21
// Runtime: 4 ms

/*
* Calculate the sum of firt n terms and if it need to patch a number, then patch a number.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long i = 0, res = 0, miss = 1;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            }
            else {
                miss += miss;
                ++res;
            }
        }
        return res;
    }
};