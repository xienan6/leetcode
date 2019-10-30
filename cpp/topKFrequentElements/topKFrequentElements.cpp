// Source : https://leetcode.com/problems/top-k-frequent-elements
// Author : Nan
// Date   : 2019-10-30
// Runtime: 20 ms

/*
* Record and sort or use priority_queue.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<N> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = v.size();
                N n(nums[i], 1);
                v.push_back(n);
            }
            else {
                ++v[m[nums[i]]].cnt;
            }
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; ++i) res.push_back(v[i].num);
        return res;
    }
    struct N{
        int num;
        int cnt;
        N (int n, int c) {
            num = n;
            cnt = c;
        }
    };
    static bool cmp(N n1, N n2) {
        return n1.cnt > n2.cnt;
    }
    
};