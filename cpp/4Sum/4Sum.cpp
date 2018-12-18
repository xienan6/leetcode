// Source : https://leetcode.com/problems/4sum
// Author : Nan
// Date   : 2018-12-18
// 282 / 282 test cases passed.
// Runtime: 16 ms

/*
* You can sort the array firstly. Then traverse the array, 
* and use two pointer from start and end. Because of sorted already, 
* you can find all answer in O(n^3) time. You can use some tricks to reduce time.  
* Notice that nSum questions only need O(n-1) Time complexity. 
*
* Time complexity O(n^3), Space complexity O(1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                int first = j + 1;
                int last = n - 1;
                while (first < last) {
                    if (nums[i] + nums[j] + nums[first] + nums[last] < target) {
                        do{first++;}while (first < last && nums[first] == nums[first - 1]);
                    }
                    else if(nums[i] + nums[j] + nums[first] + nums[last] > target) {
                        do{last--;}while (first < last && nums[last] == nums[last + 1]);
                    }
                    else {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[first]);
                        v.push_back(nums[last]);
                        result.push_back(v);
                        do{first++;}while (first < last && nums[first] == nums[first - 1]);
                        do{last--;}while (first < last && nums[last] == nums[last + 1]);
                    }
                }
            }
        }
        return result;
    }
};