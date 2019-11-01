// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : Nan
// Date   : 2019-10-31
// Runtime: 8 ms

/*
* Use a hash to check if a number exsit.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s, r;
        for (int i = 0; i < nums1.size(); ++i) s.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); ++i) if (s.find(nums2[i]) != s.end()) r.insert(nums2[i]);
        return vector<int>(r.begin(), r.end());
    }
};