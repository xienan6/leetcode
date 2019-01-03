// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Nan
// Date   : 2019-01-03
// 172 / 172 test cases passed.
// Runtime: 16 ms

/*
* Recursive.
* 
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        dfs(result, {}, target, 0, candidates);
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<int> r, int target, int start, vector<int> &candidates) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(r);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i - 1]) continue;
            r.push_back(candidates[i]);
            dfs(result, r, target - candidates[i], i + 1, candidates);
            r.pop_back();
        }
    }
};