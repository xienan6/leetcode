// Source : https://leetcode.com/problems/longest-increasing-subsequence/
// Author : Nan
// Date   : 2019-09-22
// Runtime: 4 ms

/*
* DP + binary search.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};