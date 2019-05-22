// Source : https://leetcode.com/problems/maximum-gap/
// Author : Nan
// Date   : 2019-05-22
// Runtime: 16 ms

/*
* Bucket sort.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        int size = (mx - mn) / nums.size() + 1;
        int bucket_nums = (mx - mn) / size + 1;
        vector<int> bucket_min(bucket_nums, INT_MAX);
        vector<int> bucket_max(bucket_nums, INT_MIN);
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = (nums[i] - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], nums[i]);
            bucket_max[idx] = max(bucket_max[idx], nums[i]);
            s.insert(idx);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};