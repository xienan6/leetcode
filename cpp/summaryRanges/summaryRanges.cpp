// Source : https://leetcode.com/problems/summary-ranges/
// Author : Nan
// Date   : 2019-08-16
// Runtime: 4 ms

/*
* Simulate solution.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                if (nums[i - 1] != start) res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                else res.push_back(to_string(start));
                start = nums[i];
            }
        }
        if (start == nums[nums.size() - 1]) res.push_back(to_string(start));
        else res.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));
        return res;
    }
};