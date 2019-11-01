// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author : Nan
// Date   : 2019-11-01
// Runtime: 4 ms

/*
* Use a hash to check if a number exsit.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            if (m.find(nums1[i]) != m.end()) ++m[nums1[i]];
            else m[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (m.find(nums2[i]) != m.end() && m[nums2[i]] > 0) {
                --m[nums2[i]];
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};