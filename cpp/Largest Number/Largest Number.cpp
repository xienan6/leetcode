// Source : https://leetcode.com/problems/largest-number/
// Author : Nan
// Date   : 2019-06-01
// Runtime: 16 ms

/*
* Sort.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    static int cmp(int s1, int s2) {
        return to_string(s1) + to_string(s2) > to_string(s2) + to_string(s1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (int i = 0; i < nums.size(); ++i) res += to_string(nums[i]);
        return res[0] == '0' ? "0" : res;
    }
};