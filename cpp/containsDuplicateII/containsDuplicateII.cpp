// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Nan
// Date   : 2019-07-02
// Runtime: 32 ms

/*
* Use a hashmap to record last index.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};