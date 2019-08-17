// Source : https://leetcode.com/problems/majority-element-ii/
// Author : Nan
// Date   : 2019-08-17
// Runtime: 16 ms

/*
* There at most are 2 numbers appear more than n / 3 times. 
* Most people vote for two numbers and finally check if the 
* two numbers appear more than n / 3 times.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1, c2, cnt1 = 0, cnt2 = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt1 == 0 && nums[i] != c2) {
                c1 = nums[i];
                ++cnt1;
            }
            else if (cnt2 == 0 && nums[i] != c1) {
                c2 = nums[i];
                ++cnt2;
            }
            else if (c1 == nums[i]) {
                ++cnt1;
            }
            else if (c2 == nums[i]) {
                ++cnt2;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        if (cnt1 > 0) {
            cnt1 = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == c1) ++cnt1;
            }
            if (cnt1 > nums.size() / 3) res.push_back(c1);
        }
        if (cnt2 > 0) {
            cnt2 = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == c2) ++cnt2;
            }
            if (cnt2 > nums.size() / 3) res.push_back(c2);
        }
        return res;
    }
};