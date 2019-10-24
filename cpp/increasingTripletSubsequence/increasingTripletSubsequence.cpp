// Source : https://leetcode.com/problems/increasing-triplet-subsequence
// Author : Nan
// Date   : 2019-10-24
// Runtime: 4 ms

/*
* Record the smallest two numbers.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};