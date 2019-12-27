// Source : https://leetcode.com/problems/frog-jump
// Author : Nan
// Date   : 2019-12-27
// Runtime: 36 ms

/*
* DFS + prune.
*
* Time complexity O(-), Space complexity O(-)
*/

class Solution {
public:
    bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
        int key = pos | k << 11;
        if (dp.count(key) > 0)
            return dp[key];
        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1)
                continue;
            if (gap > k + 1)
                return dp[key] = false;
            if (canCross(stones, i, gap))
                return dp[key] = true;
        }
        return dp[key] = (pos == stones.size() - 1);
    }
private:
    unordered_map<int, bool> dp;
};