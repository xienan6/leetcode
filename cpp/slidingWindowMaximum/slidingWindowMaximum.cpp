// Source : https://leetcode.com/problems/product-of-array-except-self
// Author : Nan
// Date   : 2019-08-29
// Runtime: 60 ms

/*
* Use a deque to guarantee numbers in deque are ordered. 
* Time complexity is O(n) because every number will get 
* out deque at most once.
*
* Time complexity O(n), Space complexity O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};