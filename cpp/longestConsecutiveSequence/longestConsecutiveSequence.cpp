// Source : https://leetcode.com/problems/longest-consecutive-sequence/
// Author : Nan
// Date   : 2019-04-22
// Runtime: 20 ms

/*
* Use hashmap to find if the pre and 
* next of a number are exist in list.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                s.erase(nums[i]);
                int pre = nums[i] - 1, next = nums[i] + 1;
                while (s.count(pre)) s.erase(pre--);
                while (s.count(next)) s.erase(next++);
                res = max(res, next - pre - 1);
            }
        }
        return res;
    }
};