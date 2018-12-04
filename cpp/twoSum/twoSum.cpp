// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Nn
// Date   : 2018-12-04

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.find(target - nums[i]) == mymap.end()) {
                mymap[nums[i]] = i;
            }
            else {
                result = {mymap[target - nums[i]], i};
                break;
            }
        }
        return result;
    }
};
