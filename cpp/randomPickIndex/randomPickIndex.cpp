// Source : https://leetcode.com/problems/random-pick-index
// Author : Nan
// Date   : 2019-12-22
// Runtime: 92 ms

/*
* Reservoir sampling.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    Solution(vector<int> nums): v(nums) {}
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */