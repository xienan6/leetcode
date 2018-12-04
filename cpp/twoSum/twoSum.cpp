// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Nn
// Date   : 2018-12-04

/*
* The easy solution is use a O(n^2) run-time complexity method. However,
* we can use a map or a hashmap to store numbers and reduce run-time
* complexity to O(nlogn) or O(n) because a hashmap or a map can find
* the number = target - number[0] in O(logn) or O(1).
*/

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
