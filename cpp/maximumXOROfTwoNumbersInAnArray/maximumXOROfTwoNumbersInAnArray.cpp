// Source : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Author : Nan
// Date   : 2020-01-10
// Runtime: 121 ms

/*
* 
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};